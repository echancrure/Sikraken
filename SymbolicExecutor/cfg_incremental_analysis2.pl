% lazy_reach_store_earlystop_eclipse.pl
% ECLiPSe Prolog — small, careful change from your original implementation.
% Preserves original data-structures & API but adds:
%  - early-stop DFS (stop when first uncovered edge encountered)
%  - partial caching per-start: reach(ReachStore, Frontier, CompleteFlag, HasUncov)
%  - cache invalidation on cover_edge/cover_edges (clear_reach_cache) so cached HasUncov
%    can be trusted and we can avoid the redundant reach_intersects_uncovered recheck.
%
% Call cover_edges/cover_edge to mark edges as covered.
% Call edge_reaches_uncovered(Edge) to test if Edge can reach any currently-uncovered edge.


:- lib(assoc).
:- lib(lists).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Public API (same names as your original file)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% build_graph/0
build_graph :-
    findall(edge(Src,Dst,Lbl), edge(Src,Dst,Lbl), BaseEdges),
    findall(edge(From,To,Lbl), function_call(From,To,Lbl), CallEdges),
    build_graph_from_lists(BaseEdges, CallEdges).

% build_graph_from_lists(+BaseEdges, +CallEdges)
build_graph_from_lists(BaseEdges, CallEdges) :-
    append(BaseEdges, CallEdges, AllEdges0),
    % index edges create IdMap (assoc) and RevList (list Id-edge)
    index_edges(AllEdges0, IdMap, RevList, NumberEdges),
    % build adjacency: source node -> list of edge ids starting at that node (e.g. 3 -> [id0, id1])
    build_source_index(RevList, SourceAssoc),
    % main output: build edge adjacency: edgeId -> [neighborEdgeId,...] (neighbors start at dst)
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
    printf("build_graph: %w edges indexed.\n", [NumberEdges]).

% Succeeds if exploring Edge can reach any currently-uncovered edge.
edge_reaches_uncovered(Edge) :-
    ensure_graph_built,
    edge_to_id(Edge, Id),
    ensure_reach_cached_and_test(Id).

% Mark a single edge as covered (set uncovered(Id) := 0)
% Note: we invalidate reach_cache here so cached HasUncov remains correct.
cover_edge(Edge) :-
    ensure_graph_built,
    edge_to_id(Edge, Id),
    getval(uncovered, Uncov),
    store_set(Uncov, Id, 0),
    clear_reach_cache.

% cover_edges(+List)
cover_edges(List) :-
    ensure_graph_built,
    getval(uncovered, Uncov),
    ( foreach(E, List), param(Uncov) do
        edge_to_id(E, Id), store_set(Uncov, Id, 0)
    ),
    clear_reach_cache.

% clear_reach_cache/0
clear_reach_cache :-
    empty_assoc(E), 
    setval(reach_cache, E).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Use list of edges to build: 
% - IdMap: assoc edge -> Id
% - RevList: list of Id-edge
index_edges(Edges, IdMap, RevList, Count) :-
    empty_assoc(Assoc),
    index_edges_loop(Edges, 0, Assoc, IdMap, [], RevList),
    length(RevList, Count).

index_edges_loop([], _Index, IdMapOut, IdMapOut, RevListOut, RevListOut).
index_edges_loop([E|Es], Index, IdMapIn, IdMapOut, RevListIn, RevListOut) :-
    (get_assoc(E, IdMapIn, _) ->    %duplicate: do nothing ignore [optimisation: remove duplicate check if sure theer are no duplicates]
                                    %[optimisation: create the IdMap and RevList when building the graph rather than using asserted facts]
        IndexNew = Index, IdMapNew = IdMapIn, RevListNew = RevListIn
    ;
        put_assoc(E, IdMapIn, Index, IdMapNew),
        RevListNew = [Index-E|RevListIn],
        IndexNew is Index + 1
    ),
    index_edges_loop(Es, IndexNew, IdMapNew, IdMapOut, RevListNew, RevListOut).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Use RevList: list of Id-edge to build: 
% - SourceAssoc: assoc SrcNode -> [edgeId,...] (edges starting at Src)
build_source_index(RevList, SourceAssocOut) :-
    empty_assoc(SourceAssocIn),
    build_source_loop(RevList, SourceAssocIn, SourceAssocOut).

build_source_loop([], SourceAssocOut, SourceAssocOut).
build_source_loop([Id-edge(Src,_,_)|T], SourceAssocIn, SourceAssocOut) :-
    (get_assoc(Src, SourceAssocIn, L) -> 
        put_assoc(Src, SourceAssocIn, [Id|L], S1) %add edge Id to the list of edges starting at Src
    ; 
        put_assoc(Src, SourceAssocIn, [Id], S1) 
    ),
    build_source_loop(T, S1, SourceAssocOut).
%%%
build_edge_adj(RevList, SourceAssoc, AdjOut) :-
    empty_assoc(AdjIn),
    build_edge_adj_loop(RevList, SourceAssoc, AdjIn, AdjOut).

build_edge_adj_loop([], _, AdjIn, AdjIn).
build_edge_adj_loop([Id-edge(_,Dst,_)|T], SourceAssoc, AdjIn, AdjOut) :-
    ( get_assoc(Dst, SourceAssoc, NeighIds) -> put_assoc(Id, AdjIn, NeighIds, A1) ; put_assoc(Id, AdjIn, [], A1) ),
    build_edge_adj_loop(T, SourceAssoc, A1, AdjOut).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Lazy reachability with early-stop + partial caching
%% (conservative & close to your original approach)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% reach_cache maps StartId -> reach(ReachStore, FrontierList, CompleteFlag, HasUncov)
%  - ReachStore: store of ids explored so far for this start
%  - FrontierList: stack (list) of remaining ids to explore when stopped
%  - CompleteFlag: 1 if exploration exhausted, 0 if partial
%  - HasUncov: 1 if during exploration we found an uncovered edge (so caller can
%              immediately conclude true without rescanning ReachStore)

% ensure_reach_cached_and_test(+StartId)
ensure_reach_cached_and_test(StartId) :-
    getval(reach_cache, RC0),
    ( get_assoc(StartId, RC0, reach(ReachStore, Frontier, CompleteFlag, HasUncov)) ->
        (HasUncov =:= 1 -> ! %has uncovered edge in cached reach: succeed immediately
        ; 
         CompleteFlag =:= 1 -> !, fail %fully searched and no uncovered: fail immediately
        ;   
            % Partial search and no uncovered found yet: resume exploration
            resume_compute_reach_from_cached(StartId, ReachStore, Frontier, RC0, RC1),
            setval(reach_cache, RC1),
            get_assoc(StartId, RC1, reach(_ReachStore2, _F2, CompleteFlag2, HasUncov2)),
            ( HasUncov2 =:= 1 -> ! ; CompleteFlag2 =:= 1 -> !, fail ; fail )
        )
    ;
        % Not cached: compute (stops early if an uncovered found), store result and trust HasUncov
        compute_reach_with_frontier(StartId, ReachStoreNew, FrontierNew, CompleteFlagNew, HasUncovNew),
        put_assoc(StartId, RC0, reach(ReachStoreNew, FrontierNew, CompleteFlagNew, HasUncovNew), RC2),
        setval(reach_cache, RC2),
        ( HasUncovNew =:= 1 -> ! ; CompleteFlagNew =:= 1 -> !, fail ; fail )
    ).

% compute_reach_with_frontier(+StartId, -ReachStore, -Frontier, -CompleteFlag, -HasUncov)
compute_reach_with_frontier(StartId, ReachStoreOut, FrontierOut, CompleteFlagOut, HasUncovOut) :-
    store_create(ReachStore),
    store_create(Visited),
    compute_reach_loop([StartId], ReachStore, Visited, ReachStoreOut, FrontierOut, CompleteFlagOut, HasUncovOut).

% compute_reach_loop(+Stack, +ReachStore, +Visited, -ReachStoreOut, -FrontierOut, -CompleteFlag, -HasUncov)
compute_reach_loop([], ReachStore, _, ReachStore, [], 1, 0) :- !.
compute_reach_loop([Id|Rest], ReachStore, Visited, ReachStoreOut, FrontierOut, CompleteFlagOut, HasUncovOut) :-
    ( store_get(Visited, Id, 1) ->
        compute_reach_loop(Rest, ReachStore, Visited, ReachStoreOut, FrontierOut, CompleteFlagOut, HasUncovOut)
    ;
        % mark visited and reach
        store_set(Visited, Id, 1),
        store_set(ReachStore, Id, 1),
        % if this id is currently uncovered, stop early and leave rest as frontier
        getval(uncovered, Uncov),
        ( store_get(Uncov, Id, V), V =:= 1 ->
            ReachStoreOut = ReachStore,
            FrontierOut = Rest,
            CompleteFlagOut = 0,
            HasUncovOut = 1
        ;
            % push neighbours
            getval(adj_assoc, Adj),
            ( get_assoc(Id, Adj, Neighs) -> true ; Neighs = [] ),
            append(Neighs, Rest, NewStack),
            compute_reach_loop(NewStack, ReachStore, Visited, ReachStoreOut, FrontierOut, CompleteFlagOut, HasUncovOut)
        )
    ).

% resume_compute_reach_from_cached(+StartId, +ReachStoreIn, +FrontierIn, +RC_in, -RC_out)
resume_compute_reach_from_cached(StartId, ReachStoreIn, FrontierIn, RC_in, RC_out) :-
    % create Visited store and mark every key from ReachStoreIn as visited
    store_create(Visited),
    ( stored_keys(ReachStoreIn, Keys) -> mark_visited(Keys, Visited, ReachStoreIn) ; true ),
    % continue DFS from FrontierIn
    compute_reach_loop(FrontierIn, ReachStoreIn, Visited, ReachStoreFinal, FrontierFinal, CompleteFlagFinal, HasUncovFinal),
    % update cache assoc
    put_assoc(StartId, RC_in, reach(ReachStoreFinal, FrontierFinal, CompleteFlagFinal, HasUncovFinal), RC_out).

mark_visited([], _, _).
mark_visited([K|Ks], Visited, ReachStore) :-
    store_set(Visited, K, 1),
    store_set(ReachStore, K, 1),
    mark_visited(Ks, Visited, ReachStore).

% reach_intersects_uncovered/2 (kept for external use — not used internally for the
% immediate post-compute recheck, which we removed)
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
%unused helper 
edge_of_id(Id, Edge) :-
    getval(rev_map, Rev),
    member(Id-Edge, Rev).   %expensive but should only be for debug

% get the id for an edge term
edge_to_id(Edge, Id) :- !,
    getval(id_map, IdMap),
    ( get_assoc(Edge, IdMap, Id) -> true
    ; 
      throw(error(bad_edge_term(Edge), edge_to_id/2))
    ).

ensure_graph_built :-
    ( getval(id_map, _) -> true ; throw(error(graph_not_built, build_graph/0)) ).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Debug / convenience
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

show_uncovered_ids(List) :-
    getval(uncovered, Uncov),
    ( stored_keys(Uncov, Keys) -> include_uncovered(Keys, Uncov, List) ; List = [] ).

include_uncovered([], _, []).
include_uncovered([K|Ks], Uncov, [K|R]) :-
    store_get(Uncov, K, V), V =:= 1, !,
    include_uncovered(Ks, Uncov, R).
include_uncovered([_|Ks], Uncov, R) :-
    include_uncovered(Ks, Uncov, R).

cached_reach_ids(List) :-
    getval(reach_cache, RC),
    assoc_to_list(RC, Pairs),
    findall(Id, member(Id-_, Pairs), List).

print_edge_uncovered(E) :-
    ( edge_reaches_uncovered(E) -> writeln(reachable_uncovered) ; writeln(no_uncovered) ).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Example usage helper
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

example_setup :-
    retractall(edge(_,_,_)), retractall(function_call(_,_,_)),
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
    assert(function_call(2, start(calculate_output3), false)),
    assert(function_call(3, start(calculate_output2), false)),
    assert(function_call(4, start(calculate_output), true)),
    assert(function_call(4, start(calculate_output), false)),
    assert(function_call(5, start(calculate_output3), true)),
    assert(function_call(5, start(calculate_output3), true)),
    assert(function_call(5, start(calculate_output), false)).

demo_flow :-
    example_setup,
    build_graph,
    (se_globals__get_val(debug_mode, debug) -> getval(rev_map, Rev), printf("Edges: %w\n", [Rev]) ; true),
    (se_globals__get_val(debug_mode, debug) -> getval(adj_assoc, Adj), assoc_to_list(Adj, AdjList), printf("Adjacency: %w\n", [AdjList]) ; true),
    cached_reach_ids(Cached0), writeln(cached_reach_ids=Cached0),
    ( Rev = [Id-edge(Src, Tar, Lab)|_] ->
        printf("Testing first edge id %d (%w)\n", [Id, edge(Src, Tar, Lab)]),
        ( edge_reaches_uncovered(Id) -> writeln('first reaches uncovered') ; writeln('first does not reach uncovered') )
    ; true ).

% End of file