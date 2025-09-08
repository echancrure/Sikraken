% lazy_reach_store_earlystop_eclipse.pl
% ECLiPSe Prolog — Option A with early-stop reachability + partial caching
%
% Usage (drop-in replacement for your original file):
%  - Either assert edge/3 and function_call/3 facts, then call build_graph/0
%  - Or call build_graph_from_lists(BaseEdges, CallEdges)
%  - Use edge_reaches_uncovered(EdgeOrId) to test pruning (succeeds if any
%    currently-uncovered edge reachable)
%  - Use cover_edge(EdgeOrId) or cover_edges(List) to mark edges covered
%
% Characteristics:
%  - DFS stops immediately when it discovers an uncovered edge.
%  - Partial results are cached per-start-edge as a triple:
%       reach(ReachStore, FrontierList, CompleteFlag)
%    * ReachStore = store containing all ids explored so far from this start
%    * FrontierList = stack of ids still left to explore when we stopped
%    * CompleteFlag = 1 if exploration exhausted (no more frontier), 0 if partial
%  - On subsequent queries the cached ReachStore is re-used and exploration
%    resumes from FrontierList (Visited is pre-populated with ReachStore keys).
%  - For simplicity this version does NOT consult other start-nodes' caches
%    while exploring (could be added later), but still gives large wins for
%    repeated queries and early-stopping behaviour.

:- lib(assoc).
:- lib(lists).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Public API
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% build_graph/0
% Build the graph from asserted edge/3 and function_call/3 facts.
build_graph :-
    % collect edge terms from asserted facts
    findall(edge(Src,Dst,Lbl), edge(Src,Dst,Lbl), BaseEdges),
    findall(edge(From,To,Lbl), function_call(From,To,Lbl), CallEdges),
    build_graph_from_lists(BaseEdges, CallEdges).

% build_graph_from_lists(+BaseEdges, +CallEdges)
build_graph_from_lists(BaseEdges, CallEdges) :-
    append(BaseEdges, CallEdges, AllEdges0),
    % index edges -> IdMap (assoc) and RevList (list Id-edge)
    index_edges(AllEdges0, IdMap, RevList, M),
    % build adjacency: source node -> list of edge ids starting at that node
    build_source_index(RevList, SourceAssoc),
    % build edge adjacency: edgeId -> [neighborEdgeId,...] (neighbors start at dst)
    build_edge_adj(RevList, SourceAssoc, AdjAssoc),
    % initialize uncovered store
    store_create(Uncovered),
    % set all edges as uncovered by setting key Id -> 1
    ( foreach(Id-_, RevList), param(Uncovered) do store_set(Uncovered, Id, 1) ),
    % init empty reach cache assoc
    empty_assoc(EmptyReach),
    % store globals
    setval(id_map, IdMap),
    setval(rev_map, RevList),
    setval(adj_assoc, AdjAssoc),
    setval(uncovered, Uncovered),
    setval(reach_cache, EmptyReach),
    printf("build_graph: %w edges indexed.\n", [M]).

% edge_reaches_uncovered(+EdgeOrId)
% Succeeds if exploring EdgeOrId can reach any currently-uncovered edge.
edge_reaches_uncovered(EdgeOrId) :-
    ensure_graph_built,
    edge_to_id(EdgeOrId, Id),
    ensure_reach_cached_and_test(Id).

% cover_edge(+EdgeOrId)
cover_edge(E) :-
    ensure_graph_built,
    edge_to_id(E, Id),
    getval(uncovered, Uncov),
    store_set(Uncov, Id, 0).

% cover_edges(+List)
cover_edges([]).
cover_edges([E|Es]) :- cover_edge(E), cover_edges(Es).

% clear_reach_cache/0 (if graph topology changes)
clear_reach_cache :-
    empty_assoc(E), setval(reach_cache, E).

% edge_of_id(+Id, -Edge)
edge_of_id(Id, Edge) :-
    getval(rev_map, Rev),
    member(Id-Edge, Rev).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Indexing utilities
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% index_edges(+EdgesList, -IdMapAssoc, -RevList, -Count)
index_edges(Edges, IdMap, RevList, Count) :-
    empty_assoc(A0),
    index_edges_loop(Edges, 0, A0, IdMap, [], RevList),
    length(RevList, Count).

index_edges_loop([], _I, AM, AM, R, R).
index_edges_loop([E|Es], I0, AM0, AM, R0, R) :-
    ( get_assoc(E, AM0, _) ->
        I1 = I0, AM1 = AM0, R1 = R0
    ;
        put_assoc(E, AM0, I0, AM1),
        R1 = [I0-E|R0],
        I1 is I0 + 1
    ),
    index_edges_loop(Es, I1, AM1, AM, R1, R).

% build_source_index(+RevList, -SourceAssoc)
build_source_index(RevList, SourceAssocOut) :-
    empty_assoc(S0),
    build_source_loop(RevList, S0, SourceAssocOut).

build_source_loop([], S, S).
build_source_loop([Id-edge(Src,_,_)|T], S0, S) :-
    ( get_assoc(Src, S0, L) -> put_assoc(Src, S0, [Id|L], S1) ; put_assoc(Src, S0, [Id], S1) ),
    build_source_loop(T, S1, S).

% build_edge_adj(+RevList, +SourceAssoc, -AdjAssoc)
build_edge_adj(RevList, SourceAssoc, AdjOut) :-
    empty_assoc(A0),
    build_edge_adj_loop(RevList, SourceAssoc, A0, AdjOut).

build_edge_adj_loop([], _, A, A).
build_edge_adj_loop([Id-edge(_,Dst,_)|T], SourceAssoc, A0, A) :-
    ( get_assoc(Dst, SourceAssoc, NeighIds) -> put_assoc(Id, A0, NeighIds, A1) ; put_assoc(Id, A0, [], A1) ),
    build_edge_adj_loop(T, SourceAssoc, A1, A).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Lazy reachability with early-stop + partial caching
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% reach_cache maps StartId -> reach(ReachStore, FrontierList, CompleteFlag)
%   FrontierList is a stack (list) of remaining IDs to visit, in order

% ensure_reach_cached_and_test(+StartId)
% Succeeds if the cached/extended reach from StartId reaches any currently-uncovered edge.
% Fails otherwise.
ensure_reach_cached_and_test(StartId) :-
    getval(reach_cache, RC0),
    ( get_assoc(StartId, RC0, reach(ReachStore, Frontier, CompleteFlag)) ->
        % check current uncovered intersection first
        getval(uncovered, Uncov),
        ( reach_intersects_uncovered(ReachStore, Uncov) -> !
        ; CompleteFlag =:= 1 -> !, fail
        ; % resume exploration from saved frontier
            resume_compute_reach_from_cached(StartId, ReachStore, Frontier, RC0, RC1),
            setval(reach_cache, RC1),
            % re-check after resume
            get_assoc(StartId, RC1, reach(ReachStore2, _, CompleteFlag2)),
            ( reach_intersects_uncovered(ReachStore2, Uncov) -> !
            ; CompleteFlag2 =:= 1 -> !, fail
            ; % still partial and no uncovered -> fail (will be resumed on next query)
              % Note: we do not loop forever; we only resume once per call.
              fail
            )
        )
    ;
        % not cached yet: compute until an uncovered is found or exploration exhausted
        compute_reach_with_frontier(StartId, ReachStoreNew, FrontierNew, CompleteFlagNew),
        put_assoc(StartId, RC0, reach(ReachStoreNew, FrontierNew, CompleteFlagNew), RC2),
        setval(reach_cache, RC2),
        getval(uncovered, Uncov),
        ( reach_intersects_uncovered(ReachStoreNew, Uncov) -> !
        ; CompleteFlagNew =:= 1 -> !, fail
        ; fail
        )
    ).

% compute_reach_with_frontier(+StartId, -ReachStore, -Frontier, -CompleteFlag)
% Iterative DFS that stops early when an uncovered edge is encountered.
compute_reach_with_frontier(StartId, ReachStoreOut, FrontierOut, CompleteFlagOut) :-
    store_create(ReachStore),
    store_create(Visited),
    compute_reach_from_stack([StartId], ReachStore, Visited, ReachStoreOut, FrontierOut, CompleteFlagOut).

% resume_compute_reach_from_cached(+StartId, +ReachStoreIn, +FrontierIn, +RC_in, -RC_out)
% Resume exploration from FrontierIn, where Visited is pre-populated with ReachStoreIn keys.
resume_compute_reach_from_cached(StartId, ReachStoreIn, FrontierIn, RC_in, RC_out) :-
    % create Visited store and mark every key from ReachStoreIn as visited
    store_create(Visited),
    ( stored_keys(ReachStoreIn, Keys) -> mark_visited(Keys, Visited, ReachStoreIn) ; true ),
    % continue DFS from FrontierIn
    compute_reach_from_stack(FrontierIn, ReachStoreIn, Visited, ReachStoreFinal, FrontierFinal, CompleteFlagFinal),
    % update cache assoc
    put_assoc(StartId, RC_in, reach(ReachStoreFinal, FrontierFinal, CompleteFlagFinal), RC_out).

mark_visited([], _, _).
mark_visited([K|Ks], Visited, ReachStore) :-
    % ensure K is set in both Visited and ReachStore (ReachStore already contains it)
    store_set(Visited, K, 1),
    store_set(ReachStore, K, 1),
    mark_visited(Ks, Visited, ReachStore).

% compute_reach_from_stack(+Stack, +ReachStore, +Visited, -ReachStoreOut, -FrontierOut, -CompleteFlag)
% Stack is a list used as a stack (head = next to pop). This predicate mutates ReachStore.
compute_reach_from_stack([], ReachStore, _Visited, ReachStore, [], 1) :- !.
compute_reach_from_stack([Id|Rest], ReachStore, Visited, ReachStoreOut, FrontierOut, CompleteFlag) :-
    ( store_get(Visited, Id, 1) ->
        compute_reach_from_stack(Rest, ReachStore, Visited, ReachStoreOut, FrontierOut, CompleteFlag)
    ;
        % mark visited and reach
        store_set(Visited, Id, 1),
        store_set(ReachStore, Id, 1),
        % if this id is currently uncovered, stop early and leave rest as frontier
        getval(uncovered, Uncov),
        ( store_get(Uncov, Id, V), V =:= 1 ->
            ReachStoreOut = ReachStore,
            FrontierOut = Rest,
            CompleteFlag = 0
        ;
            % push neighbours
            getval(adj_assoc, Adj),
            ( get_assoc(Id, Adj, Neighs) -> true ; Neighs = [] ),
            append(Neighs, Rest, NewStack),
            compute_reach_from_stack(NewStack, ReachStore, Visited, ReachStoreOut, FrontierOut, CompleteFlag)
        )
    ).

% reach_intersects_uncovered(+ReachStore, +UncovStore)
% True if any key in ReachStore is currently set to 1 in UncovStore.
reach_intersects_uncovered(ReachStore, Uncov) :-
    ( stored_keys(ReachStore, Keys) ->
        member(Id, Keys),
        store_get(Uncov, Id, V),
        V =:= 1, !
    ;
        fail
    ).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Helpers
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% translate edge term or id to id
edge_to_id(Id, Id) :- integer(Id), !.
edge_to_id(edge(Src,Dst,Lbl), Id) :- !,
    getval(id_map, IdMap),
    ( get_assoc(edge(Src,Dst,Lbl), IdMap, Id) -> true
    ; % fallback structural match (rare)
      assoc_to_list(IdMap, Pairs),
      member(Id-edge(Src2,Dst2,Lbl2), Pairs),
      Src2 == Src, Dst2 == Dst, Lbl2 == Lbl
    ).
edge_to_id(E, _) :- throw(error(bad_edge_term(E), edge_to_id/2)).

ensure_graph_built :-
    ( getval(id_map, _) -> true ; throw(error(graph_not_built, build_graph/0)) ).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Debug / convenience
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% show_uncovered_ids(-List)
show_uncovered_ids(List) :-
    getval(uncovered, Uncov),
    ( stored_keys(Uncov, Keys) -> include_uncovered(Keys, Uncov, List) ; List = [] ).

include_uncovered([], _, []).
include_uncovered([K|Ks], Uncov, [K|R]) :-
    store_get(Uncov, K, V), V =:= 1, !,
    include_uncovered(Ks, Uncov, R).
include_uncovered([_|Ks], Uncov, R) :-
    include_uncovered(Ks, Uncov, R).

% cached reach ids (keys in reach_cache)
cached_reach_ids(List) :-
    getval(reach_cache, RC),
    assoc_to_list(RC, Pairs),
    findall(Id, member(Id-_, Pairs), List).

% print reachable uncovered (human)
print_edge_uncovered(E) :-
    ( edge_reaches_uncovered(E) -> writeln(reachable_uncovered) ; writeln(no_uncovered) ).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Example usage helper
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Example small graph: call example_setup. Then build_graph, then query.
example_setup :-
    % clear previous facts if present
    retractall(edge(_,_,_)), retractall(function_call(_,_,_)),
    % sample edges (use your real terms instead)
    assert(edge(start(calculate_output3), 1, true)),
    assert(edge(1, end(calculate_output3), true)),
    assert(edge(1, end(calculate_output3), false)),
    assert(edge(start(calculate_output2), 2, true)),
    assert(edge(2, end(calculate_output2), true)),
    assert(edge(2, end(calculate_output2), false)),
    assert(edge(start(calculate_output), 3, true)),
    assert(edge(3, end(calculate_output), true)),
    assert(edge(3, end(calculate_output), false)),
    assert(edge(start(main), 6, true)),
    assert(edge(6, 4, true)),
    assert(edge(4, end(main), true)),
    assert(edge(4, end(main), false)),
    assert(edge(6, 5, false)),
    assert(edge(5, end(main), true)),
    assert(edge(5, end(main), false)),
    assert(edge(start(elaboration), end(elaboration), true)),
    % function calls (treated as edges in indexing)
    assert(function_call(2, start(calculate_output3), false)),
    assert(function_call(3, start(calculate_output2), false)),
    assert(function_call(4, start(calculate_output), true)),
    assert(function_call(4, start(calculate_output), false)),
    assert(function_call(5, start(calculate_output3), true)),
    assert(function_call(5, start(calculate_output3), true)),
    assert(function_call(5, start(calculate_output), false)).

% demo_flow: sets up example graph, builds, prints some info
demo_flow :-
    example_setup,
    build_graph,
    getval(rev_map, Rev), length(Rev, M), printf("Edges: %d\n", [M]),
    cached_reach_ids(Cached0), writeln(cached_reach_ids=Cached0),
    % test on a specific edge (if exists)
    ( Rev = [Id-edge(Src,_,_)|_] ->
        printf("Testing first edge id %d (%w)\n", [Id, edge(Src,_,_)]),
        ( edge_reaches_uncovered(Id) -> writeln('first reaches uncovered') ; writeln('first does not reach uncovered') )
    ; true ).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% End of file
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
