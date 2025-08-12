:- lib(assoc).
:- lib(random).  % Eclipse Prolog's random library

%%% BFS successor edges with labels code (your BFS version)
all_successor_edges_with_labels(graph(Nodes, Edges), Reachable_edges_mapping) :-
    build_adj_list_with_labels(Edges, Adjacency_map),
    findall(
        (Node, Label)-ReachEdges,       %pair notation
        (
            member(Node, Nodes),
            member(edge(Node, To, Label), Edges),
            bfs_reachable_edges(To, Adjacency_map, ReachEdges)
        ),
        Reachable_edges_mapping).

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
