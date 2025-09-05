:- lib(assoc).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%chatgpt improvement on claude's version above
%28 Aug: works but leaves duplicates when function calls, too slow for Problem07_label00
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
