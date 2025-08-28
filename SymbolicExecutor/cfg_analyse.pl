:- lib(assoc).
:- lib(random).  % Eclipse Prolog's random library
/*
%%% BFS successor edges with labels code
all_successor_edges_with_labels(graph(Nodes, Edges), Reachable_edges_mapping) :-
    build_adj_list_with_labels(Edges, Adjacency_map),
    findall(
        (Node, Label)-ReachEdges,       %pair notation
        (
            member(Node, Nodes),
            member(edge(Node, To, Label), Edges),
            bfs_reachable_edges(To, Adjacency_map, ReachEdges)
        ),
        Reachable_edges_mapping)
    .

bfs_reachable_edges(Start, Adjacency_map, ReachEdges) :-
    bfs_queue([Start], Adjacency_map, [], [], ReachEdges).

bfs_queue([], _Adjacency_map, _Visited, AccEdges, ReachEdges) :-
    reverse(AccEdges, ReachEdges).
bfs_queue([Node|Queue], Adjacency_map, Visited, AccEdges, ReachEdges) :-
    ( memberchk(Node, Visited) ->
        bfs_queue(Queue, Adjacency_map, Visited, AccEdges, ReachEdges)
    ;
        ( get_assoc(Node, Adjacency_map, Succs) -> true ; Succs = [] ),
        findall((Node, L), member((_, L), Succs), OutEdges),
        findall(SuccNode, member((SuccNode, _), Succs), SuccNodes),
        append(Queue, SuccNodes, NewQueue),
        append(AccEdges, OutEdges, NewAccEdges),
        bfs_queue(NewQueue, Adjacency_map, [Node|Visited], NewAccEdges, ReachEdges)
    ).

build_adj_list_with_labels(Edges, Adjacency_map) :-
    empty_assoc(Empty),
    build_adj_list_with_labels_(Edges, Empty, Adjacency_map).

build_adj_list_with_labels_([], Map, Map).
build_adj_list_with_labels_([edge(F,T,L)|Rest], Acc, Map) :-
    ( get_assoc(F, Acc, List) ->
        NewList = [(T,L)|List],
        put_assoc(F, Acc, NewList, Acc1)
    ;
        put_assoc(F, Acc, [(T,L)], Acc1)
    ),
    build_adj_list_with_labels_(Rest, Acc1, Map).
*/
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%faster version (chatgpt) August 28th
%%% Public API — same behaviour & order, warnings fixed
/*:- lib(assoc).

%%% Main entry
all_successor_edges_with_labels(graph(Nodes, Edges), Reachable_edges_mapping) :-
    %mytrace,
    % single pass: build adjacency (prepending) + collect relevant edges
    empty_assoc(EmptyAdj),
    build_adj_and_relevant_edges(Edges, Nodes, EmptyAdj, AdjPre, [], NodeKeysRev, [], RelevantEdgesRev),

    % restore order
    reverse(RelevantEdgesRev, RelevantEdges),

    % reverse adjacency lists
    empty_assoc(EmptyAdj2),
    reverse_adj_lists(NodeKeysRev, AdjPre, EmptyAdj2, Adjacency_map),

    % scan relevant edges once, memoize BFS per To
    empty_assoc(Cache0),
    build_mapping_from_relevant_edges(RelevantEdges, Adjacency_map, Cache0, _CacheF, [], MappingRev),

    reverse(MappingRev, Reachable_edges_mapping).

%%% Build adjacency + collect relevant edges (membership check with memberchk/2)
build_adj_and_relevant_edges([], _Nodes, AdjAcc, AdjAcc, NodeKeysAcc, NodeKeysAcc, RelAcc, RelAcc).
build_adj_and_relevant_edges([edge(F,T,L)|Rest], Nodes, Adj0, AdjF, NodeKeys0, NodeKeysF, Rel0, RelF) :-
    ( get_assoc(F, Adj0, List) ->
        NewList = [(T,L)|List],
        put_assoc(F, Adj0, NewList, Adj1),
        NodeKeys1 = NodeKeys0
    ;
        put_assoc(F, Adj0, [(T,L)], Adj1),
        NodeKeys1 = [F|NodeKeys0]
    ),
    ( memberchk(F, Nodes) ->
        Rel1 = [(F,T,L)|Rel0]
    ;
        Rel1 = Rel0
    ),
    build_adj_and_relevant_edges(Rest, Nodes, Adj1, AdjF, NodeKeys1, NodeKeysF, Rel1, RelF).

%%% Reverse adjacency lists
reverse_adj_lists([], _AdjPre, AdjAcc, AdjAcc).
reverse_adj_lists([K|KR], AdjPre, AdjAcc0, AdjAcc) :-
    get_assoc(K, AdjPre, List),
    reverse(List, RevList),
    put_assoc(K, AdjAcc0, RevList, AdjAcc1),
    reverse_adj_lists(KR, AdjPre, AdjAcc1, AdjAcc).

%%% Build mapping
build_mapping_from_relevant_edges([], _Adj, Cache, Cache, Acc, Acc).
build_mapping_from_relevant_edges([(F,T,L)|Rest], Adj, Cache0, CacheF, Acc0, AccF) :-
    ( get_assoc(T, Cache0, ReachEdges) ->
        Cache1 = Cache0
    ;
        bfs_reachable_edges(T, Adj, ReachEdges),
        put_assoc(T, Cache0, ReachEdges, Cache1)
    ),
    Acc1 = [(F,L)-ReachEdges | Acc0],
    build_mapping_from_relevant_edges(Rest, Adj, Cache1, CacheF, Acc1, AccF).

%%% BFS (same as before)
bfs_reachable_edges(Start, Adjacency_map, ReachEdges) :-
    empty_assoc(Visited0),
    queue_init(Start, Q0),
    bfs_queue(Q0, Adjacency_map, Visited0, [], ReachEdgesRev),
    reverse(ReachEdgesRev, ReachEdges).

queue_init(Start, q([Start], [])).
queue_empty(q([], [])).

queue_dequeue(q([H|T], Back), H, q(T, Back)) :- !.
queue_dequeue(q([], Back), Item, q(NewFrontTail, [])) :-
    Back \= [],
    reverse(Back, [Item|NewFrontTail]).

enqueue_nodes([], Q, Q).
enqueue_nodes(SuccNodes, q(Front, Back), q(Front, NewBack)) :-
    reverse(SuccNodes, SuccRev),
    append(SuccRev, Back, NewBack).

bfs_queue(Q, _Adj, _Vis, AccRev, AccRev) :-
    queue_empty(Q), !.
bfs_queue(Q, Adj, Vis, AccRev, ReachEdgesRev) :-
    queue_dequeue(Q, Node, QRest),
    ( get_assoc(Node, Vis, _) ->
        bfs_queue(QRest, Adj, Vis, AccRev, ReachEdgesRev)
    ;
        ( get_assoc(Node, Adj, Succs) -> true ; Succs = [] ),
        succs_out_edges_and_nodes(Succs, Node, OutEdges, SuccNodes),
        reverse(OutEdges, OutEdgesRev),
        append(OutEdgesRev, AccRev, AccRev1),
        enqueue_nodes(SuccNodes, QRest, QNew),
        put_assoc(Node, Vis, true, Vis1),
        bfs_queue(QNew, Adj, Vis1, AccRev1, ReachEdgesRev)
    ).

succs_out_edges_and_nodes([], _Node, [], []).
succs_out_edges_and_nodes([(S,L)|R], Node, [(Node,L)|OutR], [S|SuccR]) :-
    succs_out_edges_and_nodes(R, Node, OutR, SuccR).
*/
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*%Claude version


%%% Optimized BFS for binary graphs (max 2 edges per node)
all_successor_edges_with_labels(graph(_Nodes, Edges), Reachable_edges_mapping) :-
    build_adj_list_with_labels(Edges, Adjacency_map),
    findall(
        (Node, Label)-ReachEdges,
        (
            member(edge(Node, To, Label), Edges),
            bfs_reachable_edges(To, Adjacency_map, ReachEdges)
        ),
        Reachable_edges_mapping
    ).

% Use difference lists for O(1) append operations
bfs_reachable_edges(Start, Adjacency_map, ReachEdges) :-
    empty_assoc(Empty_visited),
    bfs_queue_dl([Start], Adjacency_map, Empty_visited, ReachEdges-[]).

% BFS with difference lists and association-based visited tracking
bfs_queue_dl([], _Adjacency_map, _Visited, Edges-Edges).

bfs_queue_dl([Node|Queue], Adjacency_map, Visited, Edges-Tail) :-
    (get_assoc(Node, Visited, _) ->
        % Already visited
        bfs_queue_dl(Queue, Adjacency_map, Visited, Edges-Tail)
    ;
        % Not visited - mark as visited
        put_assoc(Node, Visited, true, NewVisited),
        % Get successors (at most 2 for binary graphs)
        (get_assoc(Node, Adjacency_map, Succs) -> true ; Succs = []),
        % Build outgoing edges directly (max 2 edges)
        build_out_edges(Node, Succs, Edges-MiddleTail),
        % Add unvisited successors to queue
        extract_unvisited_nodes(Succs, NewVisited, UnvisitedNodes),
        append(Queue, UnvisitedNodes, NewQueue),
        bfs_queue_dl(NewQueue, Adjacency_map, NewVisited, MiddleTail-Tail)
    ).

% Build outgoing edges for current node (optimized for at most 2 edges)
build_out_edges(_Node, [], Edges-Edges).
build_out_edges(Node, [(_,L)], [(Node,L)|Tail]-Tail).
build_out_edges(Node, [(_,L1),(_,L2)], [(Node,L1),(Node,L2)|Tail]-Tail).
build_out_edges(Node, [(_,L)|Rest], [(Node,L)|MiddleTail]-Tail) :-
    Rest = [_,_|_], % More than 2 edges - fallback to general case
    build_out_edges_general(Node, Rest, MiddleTail-Tail).

% Fallback for the rare case of >2 edges (shouldn't happen in your case)
build_out_edges_general(_Node, [], Edges-Edges).
build_out_edges_general(Node, [(_,L)|Rest], [(Node,L)|MiddleTail]-Tail) :-
    build_out_edges_general(Node, Rest, MiddleTail-Tail).

% Extract unvisited successor nodes (optimized for at most 2 successors)
extract_unvisited_nodes([], _Visited, []).
extract_unvisited_nodes([(N,_)], Visited, Nodes) :-
    (get_assoc(N, Visited, _) -> Nodes = [] ; Nodes = [N]).
extract_unvisited_nodes([(N1,_),(N2,_)], Visited, Nodes) :-
    (get_assoc(N1, Visited, _) -> Nodes1 = [] ; Nodes1 = [N1]),
    (get_assoc(N2, Visited, _) -> Nodes2 = [] ; Nodes2 = [N2]),
    append(Nodes1, Nodes2, Nodes).
extract_unvisited_nodes([(N,_)|Rest], Visited, Nodes) :-
    Rest = [_,_|_], % More than 2 - fallback
    extract_unvisited_nodes_general([(N,_)|Rest], Visited, Nodes).

% Fallback for >2 successors
extract_unvisited_nodes_general([], _Visited, []).
extract_unvisited_nodes_general([(N,_)|Rest], Visited, Nodes) :-
    extract_unvisited_nodes_general(Rest, Visited, RestNodes),
    (get_assoc(N, Visited, _) -> Nodes = RestNodes ; Nodes = [N|RestNodes]).

% Build adjacency list (unchanged)
build_adj_list_with_labels(Edges, Adjacency_map) :-
    empty_assoc(Empty),
    build_adj_list_with_labels_(Edges, Empty, Adjacency_map).

build_adj_list_with_labels_([], Map, Map).
build_adj_list_with_labels_([edge(F,T,L)|Rest], Acc, Map) :-
    (get_assoc(F, Acc, List) ->
        put_assoc(F, Acc, [(T,L)|List], Acc1)
    ;
        put_assoc(F, Acc, [(T,L)], Acc1)
    ),
    build_adj_list_with_labels_(Rest, Acc1, Map).
*/
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%chatgpt improvement on claude's version above

%%% Public API (same behaviour as your last version)
all_successor_edges_with_labels(graph(_Nodes, Edges), Reachable_edges_mapping) :-
    build_adj_list_with_labels(Edges, Adjacency_map),
    findall(
        (Node, Label)-ReachEdges,
        (
            member(edge(Node, To, Label), Edges),
            bfs_reachable_edges(To, Adjacency_map, ReachEdges)
        ),
        Reachable_edges_mapping
    ).

%%% BFS wrapper: returns ReachEdges in the same order as previous code
bfs_reachable_edges(Start, Adjacency_map, ReachEdges) :-
    empty_assoc(EmptyVisited),
    queue_init(Start, Q0),
    bfs_queue(Q0, Adjacency_map, EmptyVisited, [], ReachEdgesRev),
    reverse(ReachEdgesRev, ReachEdges).

%%% Queue utilities (two-list queue q(Front,Back))
queue_init(Start, q([Start], [])).
queue_empty(q([], [])).

queue_dequeue(q([H|T], Back), H, q(T, Back)) :- !.
queue_dequeue(q([], Back), Item, q(NewFrontTail, [])) :-
    Back \= [],
    reverse(Back, [Item|NewFrontTail]).

% Enqueue a list of successor nodes preserving their order.
% We reverse SuccNodes and then prepend the reversed list onto Back so that
% when Back is later reversed the successors come out in the original order.
enqueue_nodes(SuccNodes, q(Front, Back), q(Front, NewBack)) :-
    reverse(SuccNodes, Rev),
    prepend_list(Rev, Back, NewBack).

prepend_list([], B, B).
prepend_list([H|T], B, [H|Rest]) :-
    prepend_list(T, B, Rest).

%%% BFS main loop
% AccRev accumulates outgoing edges segments in reversed order; final reverse at top.
bfs_queue(Q, _Adj, _Visited, AccRev, AccRev) :-
    queue_empty(Q), !.
bfs_queue(Q, Adj, Vis, AccRev, ReachEdgesRev) :-
    queue_dequeue(Q, Node, QRest),
    ( get_assoc(Node, Vis, _) ->
        % already visited
        bfs_queue(QRest, Adj, Vis, AccRev, ReachEdgesRev)
    ;
        % not visited: mark visited
        put_assoc(Node, Vis, true, Vis1),
        ( get_assoc(Node, Adj, Succs) -> true ; Succs = [] ),
        % build outgoing edges and successor node list
        succs_out_edges_and_nodes(Succs, Node, OutEdges, SuccNodes),
        % prepend reversed OutEdges into the accumulator (so no append/3 on big lists)
        reverse(OutEdges, OutEdgesRev),
        append(OutEdgesRev, AccRev, AccRev1),
        enqueue_nodes(SuccNodes, QRest, QNew),
        bfs_queue(QNew, Adj, Vis1, AccRev1, ReachEdgesRev)
    ).

% From Succs = [(S1,L1),(S2,L2),...] produce:
%  - OutEdges = [(Node,L1),(Node,L2),...] (same order)
%  - SuccNodes = [S1,S2,...] (same order)
succs_out_edges_and_nodes([], _Node, [], []).
succs_out_edges_and_nodes([(S,L)|R], Node, [(Node,L)|OutR], [S|SuccR]) :-
    succs_out_edges_and_nodes(R, Node, OutR, SuccR).

%%% Adjacency builder (same semantics as your original: prepends successors)
build_adj_list_with_labels(Edges, Adjacency_map) :-
    empty_assoc(Empty),
    build_adj_list_with_labels_(Edges, Empty, Adjacency_map).

build_adj_list_with_labels_([], Map, Map).
build_adj_list_with_labels_([edge(F,T,L)|Rest], Acc, Map) :-
    ( get_assoc(F, Acc, List) ->
        put_assoc(F, Acc, [(T,L)|List], Acc1)
    ;
        put_assoc(F, Acc, [(T,L)], Acc1)
    ),
    build_adj_list_with_labels_(Rest, Acc1, Map).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%% Example usage

%%% between/3 for Eclipse Prolog (inclusive range)
between(Low, High, Low) :- Low =< High.
between(Low, High, X) :-
    Low < High,
    Low1 is Low + 1,
    between(Low1, High, X).

%%% nth0/3 zero-based index retrieval
nth0(0, [H|_], H).
nth0(N, [_|T], E) :-
    N > 0,
    N1 is N - 1,
    nth0(N1, T, E).

%%% random_member/2 selects a random element from a list
random_member(Elem, List) :-
    length(List, Len),
    Len > 0,
    random(Len, Idx),
    nth0(Idx, List, Elem).

% range/3 to generate list of integers
range(Low, High, []) :- Low > High, !.
range(Low, High, [Low|Rest]) :-
    Low =< High,
    Next is Low + 1,
    range(Next, High, Rest).

large_test_graph(graph(Nodes, Edges)) :-
    range(1, 500, Nodes),
    random_edges(Nodes, 2000, Edges).

random_edges(_, 0, []) :- !.
random_edges(Nodes, N, [edge(F, T, L) | Rest]) :-
    N > 0,
    random_member(F, Nodes),
    random_member(T, Nodes),
    random_label(L),
    N1 is N - 1,
    random_edges(Nodes, N1, Rest).
%%% Timing predicate
time_large_graph :-
    large_test_graph(Graph),
    statistics(runtime, [Start|_]),
    all_successor_edges_with_labels(Graph, Mapping),
    statistics(runtime, [End|_]),
    Time is End - Start,
    length(Mapping, Len),
    printf("Execution time: %d ms\n", [Time]),
    printf("Mapping size: %d\n", [Len]).
