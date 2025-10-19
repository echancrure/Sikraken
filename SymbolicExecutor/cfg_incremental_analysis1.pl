% lazy_reach_store.pl
% ECLiPSe Prolog — Option A implemented with store-based bitsets (complete file)
%
% Usage:
%  - Either assert edge/3 and function_call/3 facts, then call build_graph/0
%  - Or call build_graph_from_lists(BaseEdges, CallEdges)
%  - Use edge_reaches_uncovered(EdgeOrId) to test pruning
%  - Use cover_edge(EdgeOrId) or cover_edges(List) to mark edges covered
%
% This file uses:
%   - assoc for maps (id_map, adjacency)
%   - store for mutable sparse bitsets (reachability caches and uncovered set)
%
% Notes:
%  - Edges are terms edge(Src,Dst,Label). Function calls are converted to
%    synthetic edges function_call(From, To, Label) are included in indexing.
%  - Reachability bitset for an edge is computed lazily on first need and cached.
%  - The uncovered set is a store where a key Id has value 1 when uncovered,
%    and 0 or absent when covered.
%  - No assert/retract in hot path except for the reach cache (could be replaced
%    by setval/assoc if preferred).
%

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
% Build the graph from lists of edge(...) terms.
build_graph_from_lists(BaseEdges, CallEdges) :-
    append(BaseEdges, CallEdges, AllEdges0),
    % make unique: remove duplicates (keep first occurrence)
    %sort(AllEdges0, AllEdges),      % sort/1 gives canonical order; fine for indexing
    % index edges -> IdMap (assoc) and RevList (list Id-edge)
    index_edges(AllEdges0, IdMap, RevList, M),
    % build adjacency: source node -> list of edge ids starting at that node
    build_source_index(RevList, SourceAssoc),
    % build edge adjacency: edgeId -> [neighborEdgeId,...] (neighbors start at dst)
    build_edge_adj(RevList, SourceAssoc, AdjAssoc),
    % initialize uncovered bitset (store)
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
% True if exploring EdgeOrId can reach any currently-uncovered edge.
edge_reaches_uncovered(EdgeOrId) :-
    ensure_graph_built,
    edge_to_id(EdgeOrId, Id),
    ensure_reach_cached(Id),
    % get reach store and uncovered store
    getval(reach_cache, RC), get_assoc(Id, RC, ReachStore),
    getval(uncovered, Uncov),
    reach_intersects_uncovered(ReachStore, Uncov).

% cover_edge(+EdgeOrId)
% Mark a single edge as covered (set uncovered(Id) := 0)
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
% RevList = [Id-edge(...) , ...] (Id integers from 0..Count-1)
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
% SourceAssoc: SourceNode -> [EdgeId, ...]
build_source_index(RevList, SourceAssocOut) :-
    empty_assoc(S0),
    build_source_loop(RevList, S0, SourceAssocOut).

build_source_loop([], S, S).
build_source_loop([Id-edge(Src,_,_)|T], S0, S) :-
    ( get_assoc(Src, S0, L) -> put_assoc(Src, S0, [Id|L], S1) ; put_assoc(Src, S0, [Id], S1) ),
    build_source_loop(T, S1, S).

% build_edge_adj(+RevList, +SourceAssoc, -AdjAssoc)
% For each Id-edge(_,Dst,_), neighbors are edges whose source == Dst
build_edge_adj(RevList, SourceAssoc, AdjOut) :-
    empty_assoc(A0),
    build_edge_adj_loop(RevList, SourceAssoc, A0, AdjOut).

build_edge_adj_loop([], _, A, A).
build_edge_adj_loop([Id-edge(_,Dst,_)|T], SourceAssoc, A0, A) :-
    ( get_assoc(Dst, SourceAssoc, NeighIds) -> put_assoc(Id, A0, NeighIds, A1) ; put_assoc(Id, A0, [], A1) ),
    build_edge_adj_loop(T, SourceAssoc, A1, A).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Lazy reachability computation (stores)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% ensure_reach_cached(+EdgeId)
ensure_reach_cached(Id) :-
    getval(reach_cache, RC),
    ( get_assoc(Id, RC, _) -> true
    ;
        % compute and insert
        compute_reach_store(Id, ReachStore),
        put_assoc(Id, RC, ReachStore, RC2),
        setval(reach_cache, RC2)
    ).

% compute_reach_store(+StartId, -ReachStore)
% Iterative DFS (stack) with store-based visited and reach sets
compute_reach_store(StartId, ReachStore) :-
    store_create(ReachStore),
    store_create(Visited),
    compute_reach_loop([StartId], ReachStore, Visited).

compute_reach_loop([], _, _) :- !.
compute_reach_loop([Id|Rest], ReachStore, Visited) :-
    ( store_get(Visited, Id, 1) ->
        compute_reach_loop(Rest, ReachStore, Visited)
    ;
        % mark visited and reach
        store_set(Visited, Id, 1),
        store_set(ReachStore, Id, 1),
        % push neighbors
        getval(adj_assoc, Adj),
        ( get_assoc(Id, Adj, Neighs) -> true ; Neighs = [] ),
        append(Neighs, Rest, NewStack),
        compute_reach_loop(NewStack, ReachStore, Visited)
    ).

% reach_intersects_uncovered(+ReachStore, +UncoveredStore)
% True if any key Id is present & set in both ReachStore and UncoveredStore
reach_intersects_uncovered(ReachStore, Uncov) :-
    % iterate over keys in ReachStore (which is usually smaller than Uncov)
    ( stored_keys(ReachStore, Keys)
     ->
        ( member(Id, Keys),
          store_get(Uncov, Id, V),
          V =:= 1, ! )
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

% cached reach ids
cached_reach_ids(List) :-
    getval(reach_cache, RC),
    assoc_to_list(RC, Pairs),
    findall(Id, member(Id-_, Pairs), List).

% print reachable uncovered (human)
print_edge_uncovered(E) :-
    edge_reaches_uncovered(E) -> writeln(reachable_uncovered) ; writeln(no_uncovered).

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