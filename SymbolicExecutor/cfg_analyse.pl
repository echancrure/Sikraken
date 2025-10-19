:- lib(assoc).    % ECLiPSe assoc library
:- lib(lists).
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
%clause v6
% ECLiPSe Prolog code for efficient function call mapping - stack-safe version
:- lib(ic).
:- lib(lists).
:- lib(assoc).
:- lib(hash).

% Main predicate - stack-safe iterative version using difference lists
extend_mapping_with_function_calls_fast(OriginalMapping, FunctionCalls, ExtendedMapping) :-
    % Create efficient lookup structures
    create_original_lookup(OriginalMapping, OriginalLookup),
    create_function_call_lookup(FunctionCalls, FunctionCallLookup),
    
    % Initialize result with original mapping using hash table for better performance
    hash_create(ResultHash),
    initialize_result_hash(OriginalMapping, ResultHash),
    
    % Extract all (Node, Label) pairs
    extract_node_labels(OriginalMapping, NodeLabels),
    
    % Process iteratively until stable using worklist approach
    process_worklist(NodeLabels, FunctionCallLookup, ResultHash),
    
    % Convert back to list format
    convert_hash_to_mapping(NodeLabels, ResultHash, ExtendedMapping).

% Create lookup for original mapping
create_original_lookup([], Empty) :-
    empty_assoc(Empty).
create_original_lookup([(Node, Label) - Edges | Rest], Lookup) :-
    create_original_lookup(Rest, RestLookup),
    put_assoc((Node, Label), RestLookup, Edges, Lookup).

% Create lookup for function calls - more efficient grouping
create_function_call_lookup(FunctionCalls, Lookup) :-
    empty_assoc(Empty),
    build_function_call_lookup(FunctionCalls, Empty, Lookup).

build_function_call_lookup([], Lookup, Lookup).
build_function_call_lookup([edge(From, To, Label) | Rest], AccLookup, Lookup) :-
    (   get_assoc(From, AccLookup, ExistingCalls) ->
        put_assoc(From, AccLookup, [(To, Label) | ExistingCalls], NewAccLookup)
    ;   put_assoc(From, AccLookup, [(To, Label)], NewAccLookup)
    ),
    build_function_call_lookup(Rest, NewAccLookup, Lookup).

% Initialize result hash table
initialize_result_hash([], _).
initialize_result_hash([(Node, Label) - Edges | Rest], Hash) :-
    hash_set(Hash, (Node, Label), Edges),
    initialize_result_hash(Rest, Hash).

% Extract all (Node, Label) pairs
extract_node_labels([], []).
extract_node_labels([(Node, Label) - _ | Rest], [(Node, Label) | NodeLabels]) :-
    extract_node_labels(Rest, NodeLabels).

% Worklist algorithm - stack-safe processing
process_worklist(NodeLabels, FunctionCallLookup, ResultHash) :-
    % Initialize worklist with all nodes
    process_worklist_iterations(NodeLabels, FunctionCallLookup, ResultHash, NodeLabels).

% Process iterations until no changes
process_worklist_iterations([], _, _, _) :- !.
process_worklist_iterations(AllNodes, FunctionCallLookup, ResultHash, Worklist) :-
    process_current_worklist(Worklist, FunctionCallLookup, ResultHash, [], NewWorklist),
    (   NewWorklist = [] ->
        true  % No changes, done
    ;   % Continue with nodes that changed
        process_worklist_iterations(AllNodes, FunctionCallLookup, ResultHash, NewWorklist)
    ).

% Process current worklist and build new worklist of changed nodes
process_current_worklist([], _, _, NewWorklist, NewWorklist).
process_current_worklist([(Node, Label) | RestWorklist], FunctionCallLookup, ResultHash, 
                        AccNewWorklist, NewWorklist) :-
    % Get current edges
    hash_get(ResultHash, (Node, Label), CurrentEdges),
    
    % Compute new edges efficiently
    compute_new_edges_efficient(Node, Label, CurrentEdges, FunctionCallLookup, ResultHash, NewEdges),
    
    % Check if changed and update
    (   edges_equal(CurrentEdges, NewEdges) ->
        % No change for this node
        NextAccWorklist = AccNewWorklist
    ;   % Changed - update hash and add to new worklist
        hash_set(ResultHash, (Node, Label), NewEdges),
        NextAccWorklist = [(Node, Label) | AccNewWorklist]
    ),
    
    % Process remaining worklist
    process_current_worklist(RestWorklist, FunctionCallLookup, ResultHash, 
                            NextAccWorklist, NewWorklist).

% Compute new edges efficiently without deep recursion
compute_new_edges_efficient(Node, Label, CurrentEdges, FunctionCallLookup, ResultHash, NewEdges) :-
    % Use difference lists to avoid stack overflow
    collect_direct_function_edges(Node, Label, FunctionCallLookup, ResultHash, DirectEdges-[]),
    collect_successor_function_edges(CurrentEdges, FunctionCallLookup, ResultHash, SuccEdges-[]),
    
    % Combine edges efficiently
    append(CurrentEdges, DirectEdges, TempEdges),
    append(TempEdges, SuccEdges, AllEdges),
    sort(AllEdges, NewEdges).

% Collect edges from direct function calls using difference lists
collect_direct_function_edges(Node, Label, FunctionCallLookup, ResultHash, Edges-Tail) :-
    (   get_assoc(Node, FunctionCallLookup, FunctionCalls) ->
        collect_from_function_calls(FunctionCalls, Label, ResultHash, Edges-Tail)
    ;   Edges = Tail
    ).

% Collect from function calls list
collect_from_function_calls([], _, _, Edges-Edges).
collect_from_function_calls([(FuncStart, FuncLabel) | RestCalls], NodeLabel, ResultHash, Edges-Tail) :-
    (   NodeLabel = FuncLabel ->
        (   hash_get(ResultHash, (FuncStart, true), FuncEdges) ->
            append(FuncEdges, RestEdges, Edges),
            collect_from_function_calls(RestCalls, NodeLabel, ResultHash, RestEdges-Tail)
        ;   collect_from_function_calls(RestCalls, NodeLabel, ResultHash, Edges-Tail)
        )
    ;   collect_from_function_calls(RestCalls, NodeLabel, ResultHash, Edges-Tail)
    ).

% Collect edges from successor function calls
collect_successor_function_edges([], _, _, Edges-Edges).
collect_successor_function_edges([(SuccNode, EdgeLabel) | RestSuccs], FunctionCallLookup, 
                                ResultHash, Edges-Tail) :-
    (   get_assoc(SuccNode, FunctionCallLookup, FunctionCalls) ->
        collect_from_function_calls(FunctionCalls, EdgeLabel, ResultHash, Edges-MidTail),
        collect_successor_function_edges(RestSuccs, FunctionCallLookup, ResultHash, MidTail-Tail)
    ;   collect_successor_function_edges(RestSuccs, FunctionCallLookup, ResultHash, Edges-Tail)
    ).

% Efficient edge equality check
edges_equal(Edges1, Edges2) :-
    sort(Edges1, Sorted1),
    sort(Edges2, Sorted2),
    Sorted1 = Sorted2.

% Convert hash back to mapping format
convert_hash_to_mapping([], _, []).
convert_hash_to_mapping([(Node, Label) | RestNodes], Hash, 
                       [(Node, Label) - Edges | RestMapping]) :-
    hash_get(Hash, (Node, Label), Edges),
    convert_hash_to_mapping(RestNodes, Hash, RestMapping).

% Alternative version with even more aggressive stack optimization
extend_mapping_with_function_calls_ultra_fast(OriginalMapping, FunctionCalls, ExtendedMapping) :-
    % Create hash tables for efficient lookup
    hash_create(MappingHash),
    hash_create(FuncCallHash),
    
    % Populate hash tables
    populate_mapping_hash(OriginalMapping, MappingHash),
    populate_funcall_hash(FunctionCalls, FuncCallHash),
    
    % Extract node labels for processing
    extract_node_labels(OriginalMapping, NodeLabels),
    
    % Process with optimized algorithm using findall
    process_mapping_with_findall(NodeLabels, MappingHash, FuncCallHash, ExtendedMapping).

% Populate mapping hash table
populate_mapping_hash([], _).
populate_mapping_hash([(Node, Label) - Edges | Rest], Hash) :-
    hash_set(Hash, (Node, Label), Edges),
    populate_mapping_hash(Rest, Hash).

% Populate function call hash table
populate_funcall_hash([], _).
populate_funcall_hash([function_call(From, To, Label) | Rest], Hash) :-
    Key = From,
    (   hash_get(Hash, Key, ExistingCalls) ->
        hash_set(Hash, Key, [(To, Label) | ExistingCalls])
    ;   hash_set(Hash, Key, [(To, Label)])
    ),
    populate_funcall_hash(Rest, Hash).

% Process mapping using findall for maximum stack safety
process_mapping_with_findall(NodeLabels, MappingHash, FuncCallHash, ExtendedMapping) :-
    findall((Node, Label) - FinalEdges,
           (   member((Node, Label), NodeLabels),
               compute_final_edges_iterative(Node, Label, MappingHash, FuncCallHash, FinalEdges)
           ),
           ExtendedMapping).

% Compute final edges using iterative approach with findall
compute_final_edges_iterative(Node, Label, MappingHash, FuncCallHash, FinalEdges) :-
    hash_get(MappingHash, (Node, Label), InitialEdges),
    iterative_expansion(Node, Label, InitialEdges, MappingHash, FuncCallHash, FinalEdges).

% Iterative expansion without deep recursion
iterative_expansion(Node, Label, CurrentEdges, MappingHash, FuncCallHash, FinalEdges) :-
    expand_edges_one_iteration(Node, Label, CurrentEdges, MappingHash, FuncCallHash, NewEdges),
    (   edges_equal(CurrentEdges, NewEdges) ->
        FinalEdges = NewEdges
    ;   iterative_expansion(Node, Label, NewEdges, MappingHash, FuncCallHash, FinalEdges)
    ).

% Expand edges by one iteration using findall
expand_edges_one_iteration(Node, Label, CurrentEdges, MappingHash, FuncCallHash, NewEdges) :-
    findall((TargetNode, TargetLabel),
           (   % Original edges
               member((TargetNode, TargetLabel), CurrentEdges)
           ;   % Direct function call edges
               hash_get(FuncCallHash, Node, FunctionCalls),
               member((FuncStart, FuncLabel), FunctionCalls),
               Label = FuncLabel,
               hash_get(MappingHash, (FuncStart, true), FuncEdges),
               member((TargetNode, TargetLabel), FuncEdges)
           ;   % Successor function call edges
               member((SuccNode, EdgeLabel), CurrentEdges),
               hash_get(FuncCallHash, SuccNode, SuccFunctionCalls),
               member((FuncStart, FuncLabel), SuccFunctionCalls),
               EdgeLabel = FuncLabel,
               hash_get(MappingHash, (FuncStart, true), FuncEdges),
               member((TargetNode, TargetLabel), FuncEdges)
           ),
           AllEdges),
    sort(AllEdges, NewEdges).

% Utility predicate to print mapping
print_extended_mapping([]).
print_extended_mapping([(Node, Label) - Edges | Rest]) :-
    format('From node ~w with label ~w: ~w~n', [Node, Label, Edges]),
    print_extended_mapping(Rest).

% Example usage
example_usage :-
    % Original mapping  
    OriginalMapping = [
        (start('Calculate_output3'), true) - [(1, false), (1, true)],
        (1, true) - [],
        (1, false) - [],
        (start('Calculate_output2'), true) - [(2, false), (2, true)],
        (2, true) - [],
        (2, false) - [],
        (start('Calculate_output'), true) - [(3, false), (3, true)],
        (3, true) - [],
        (3, false) - [],
        (start('Main'), true) - [(6, false), (6, true), (5, false), (5, true), (4, false), (4, true)],
        (6, true) - [(4, false), (4, true)],
        (4, true) - [],
        (4, false) - [],
        (6, false) - [(5, false), (5, true)],
        (5, true) - [],
        (5, false) - [],
        (start(elaboration), true) - []
    ],
    
    % Function calls
    FunctionCalls = [
        function_call(2, start('Calculate_output3'), false),
        function_call(3, start('Calculate_output2'), false),
        function_call(4, start('Calculate_output'), true),
        function_call(4, start('Calculate_output'), false),
        function_call(5, start('Calculate_output3'), true),
        function_call(5, start('Calculate_output'), true),
        function_call(5, start('Calculate_output'), false)
    ],
    
    % Generate extended mapping
    extend_mapping_with_function_calls_fast(OriginalMapping, FunctionCalls, ExtendedMapping),
    
    % Print results
    nl, write('Extended Mapping:'), nl,
    print_extended_mapping(ExtendedMapping).

% Legacy interface
extend_mapping_with_function_calls(OriginalMapping, FunctionCalls, ExtendedMapping) :-
    extend_mapping_with_function_calls_fast(OriginalMapping, FunctionCalls, ExtendedMapping).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*
%claude v5
% ECLiPSe Prolog code for efficient function call mapping using worklist algorithm
:- lib(ic).
:- lib(lists).
:- lib(assoc).

% Main predicate - highly optimized iterative version
extend_mapping_with_function_calls_fast(OriginalMapping, FunctionCalls, ExtendedMapping) :-
    % Create efficient lookup structures
    create_original_lookup(OriginalMapping, OriginalLookup),
    create_function_call_lookup(FunctionCalls, FunctionCallLookup),
    
    % Initialize result with original mapping
    initialize_result_lookup(OriginalMapping, ResultLookup),
    
    % Extract all (Node, Label) pairs that need processing
    extract_node_labels(OriginalMapping, NodeLabels),
    
    % Process all nodes iteratively until no more changes
    process_until_stable(NodeLabels, OriginalLookup, FunctionCallLookup, ResultLookup, FinalLookup),
    
    % Convert back to list format
    convert_lookup_to_mapping(NodeLabels, FinalLookup, ExtendedMapping).

% Create lookup for original mapping
create_original_lookup([], Empty) :-
    empty_assoc(Empty).
create_original_lookup([(Node, Label) - Edges | Rest], Lookup) :-
    create_original_lookup(Rest, RestLookup),
    put_assoc((Node, Label), RestLookup, Edges, Lookup).

% Create lookup for function calls - group by source node
create_function_call_lookup([], Empty) :-
    empty_assoc(Empty).
create_function_call_lookup([function_call(From, To, Label) | Rest], Lookup) :-
    create_function_call_lookup(Rest, RestLookup),
    (   get_assoc(From, RestLookup, ExistingCalls) ->
        put_assoc(From, RestLookup, [(To, Label) | ExistingCalls], Lookup)
    ;   put_assoc(From, RestLookup, [(To, Label)], Lookup)
    ).

% Initialize result lookup with original mapping
initialize_result_lookup([], Empty) :-
    empty_assoc(Empty).
initialize_result_lookup([(Node, Label) - Edges | Rest], Lookup) :-
    initialize_result_lookup(Rest, RestLookup),
    put_assoc((Node, Label), RestLookup, Edges, Lookup).

% Extract all (Node, Label) pairs
extract_node_labels([], []).
extract_node_labels([(Node, Label) - _ | Rest], [(Node, Label) | NodeLabels]) :-
    extract_node_labels(Rest, NodeLabels).

% Iteratively process until no changes occur (fixed-point)
process_until_stable(NodeLabels, OriginalLookup, FunctionCallLookup, ResultLookup, FinalLookup) :-
    process_one_iteration(NodeLabels, OriginalLookup, FunctionCallLookup, ResultLookup, NewResultLookup, Changed),
    (   Changed = true ->
        % Continue iterating if changes occurred
        process_until_stable(NodeLabels, OriginalLookup, FunctionCallLookup, NewResultLookup, FinalLookup)
    ;   % No changes, we're done
        FinalLookup = NewResultLookup
    ).

% Process all nodes once and detect if any changes occurred
process_one_iteration([], _, _, ResultLookup, ResultLookup, false).
process_one_iteration([(Node, Label) | RestNodes], OriginalLookup, FunctionCallLookup, 
                     ResultLookup, FinalLookup, Changed) :-
    % Get current edges for this node
    get_assoc((Node, Label), ResultLookup, CurrentEdges),
    
    % Compute new edges by expanding through function calls
    expand_edges_one_step(CurrentEdges, Node, Label, FunctionCallLookup, ResultLookup, NewEdges),
    
    % Check if edges changed
    (   same_edges(CurrentEdges, NewEdges) ->
        NodeChanged = false,
        UpdatedLookup = ResultLookup
    ;   NodeChanged = true,
        put_assoc((Node, Label), ResultLookup, NewEdges, UpdatedLookup)
    ),
    
    % Process remaining nodes
    process_one_iteration(RestNodes, OriginalLookup, FunctionCallLookup, 
                         UpdatedLookup, FinalLookup, RestChanged),
    
    % Combine change flags
    (   (NodeChanged = true ; RestChanged = true) ->
        Changed = true
    ;   Changed = false
    ).

% Expand edges one step through function calls
expand_edges_one_step(CurrentEdges, Node, Label, FunctionCallLookup, ResultLookup, NewEdges) :-
    % Add edges from direct function calls
    (   get_assoc(Node, FunctionCallLookup, FunctionCalls) ->
        expand_direct_function_calls(FunctionCalls, Label, ResultLookup, DirectFuncEdges)
    ;   DirectFuncEdges = []
    ),
    
    % Add edges from function calls through current successors
    expand_through_successors(CurrentEdges, FunctionCallLookup, ResultLookup, IndirectFuncEdges),
    
    % Combine all edges
    append(CurrentEdges, DirectFuncEdges, TempEdges),
    append(TempEdges, IndirectFuncEdges, AllEdges),
    sort(AllEdges, NewEdges).  % sort removes duplicates automatically

% Expand through direct function calls from current node
expand_direct_function_calls([], _, _, []).
expand_direct_function_calls([(FuncStart, FuncLabel) | RestCalls], NodeLabel, 
                            ResultLookup, AllFuncEdges) :-
    (   NodeLabel = FuncLabel ->
        % Get current edges of the function start node
        (   get_assoc((FuncStart, true), ResultLookup, FuncEdges) ->
            true
        ;   FuncEdges = []
        )
    ;   FuncEdges = []
    ),
    
    % Process remaining function calls
    expand_direct_function_calls(RestCalls, NodeLabel, ResultLookup, RestFuncEdges),
    
    % Combine results
    append(FuncEdges, RestFuncEdges, AllFuncEdges).

% Expand through function calls from current successors
expand_through_successors([], _, _, []).
expand_through_successors([(SuccNode, EdgeLabel) | RestEdges], FunctionCallLookup, 
                         ResultLookup, AllIndirectEdges) :-
    % Check for function calls from this successor
    (   get_assoc(SuccNode, FunctionCallLookup, FunctionCalls) ->
        expand_successor_function_calls(FunctionCalls, EdgeLabel, ResultLookup, SuccFuncEdges)
    ;   SuccFuncEdges = []
    ),
    
    % Process remaining successors
    expand_through_successors(RestEdges, FunctionCallLookup, ResultLookup, RestIndirectEdges),
    
    % Combine results
    append(SuccFuncEdges, RestIndirectEdges, AllIndirectEdges).

% Expand function calls from a specific successor
expand_successor_function_calls([], _, _, []).
expand_successor_function_calls([(FuncStart, FuncLabel) | RestCalls], EdgeLabel, 
                               ResultLookup, AllCallEdges) :-
    (   EdgeLabel = FuncLabel ->
        % Get current edges of the function start node
        (   get_assoc((FuncStart, true), ResultLookup, FuncEdges) ->
            true
        ;   FuncEdges = []
        )
    ;   FuncEdges = []
    ),
    
    % Process remaining function calls
    expand_successor_function_calls(RestCalls, EdgeLabel, ResultLookup, RestCallEdges),
    
    % Combine results
    append(FuncEdges, RestCallEdges, AllCallEdges).

% Check if two edge lists are the same
same_edges(Edges1, Edges2) :-
    sort(Edges1, Sorted1),
    sort(Edges2, Sorted2),
    Sorted1 = Sorted2.

% Convert lookup back to mapping format
convert_lookup_to_mapping([], _, []).
convert_lookup_to_mapping([(Node, Label) | RestNodes], Lookup, 
                         [(Node, Label) - Edges | RestMapping]) :-
    get_assoc((Node, Label), Lookup, Edges),
    convert_lookup_to_mapping(RestNodes, Lookup, RestMapping).

% Utility predicate to print mapping
print_extended_mapping([]).
print_extended_mapping([(Node, Label) - Edges | Rest]) :-
    format('From node ~w with label ~w: ~w~n', [Node, Label, Edges]),
    print_extended_mapping(Rest).

% Example usage
example_usage :-
    % Original mapping
    OriginalMapping = [
        (start('Calculate_output3'), true) - [(1, false), (1, true)],
        (1, true) - [],
        (1, false) - [],
        (start('Calculate_output2'), true) - [(2, false), (2, true)],
        (2, true) - [],
        (2, false) - [],
        (start('Calculate_output'), true) - [(3, false), (3, true)],
        (3, true) - [],
        (3, false) - [],
        (start('Main'), true) - [(6, false), (6, true), (5, false), (5, true), (4, false), (4, true)],
        (6, true) - [(4, false), (4, true)],
        (4, true) - [],
        (4, false) - [],
        (6, false) - [(5, false), (5, true)],
        (5, true) - [],
        (5, false) - [],
        (start(elaboration), true) - []
    ],
    
    % Function calls
    FunctionCalls = [
        function_call(2, start('Calculate_output3'), false),
        function_call(3, start('Calculate_output2'), false),
        function_call(4, start('Calculate_output'), true),
        function_call(4, start('Calculate_output'), false),
        function_call(5, start('Calculate_output3'), true),
        function_call(5, start('Calculate_output'), true),
        function_call(5, start('Calculate_output'), false)
    ],
    
    % Generate extended mapping
    extend_mapping_with_function_calls_fast(OriginalMapping, FunctionCalls, ExtendedMapping),
    
    % Print results
    nl, write('Extended Mapping:'), nl,
    print_extended_mapping(ExtendedMapping).

% Legacy interface for compatibility
extend_mapping_with_function_calls(OriginalMapping, FunctionCalls, ExtendedMapping) :-
    extend_mapping_with_function_calls_fast(OriginalMapping, FunctionCalls, ExtendedMapping).
*/
/*
%%claude v4
% ECLiPSe Prolog code to generate extended reachability mapping with function calls
:- lib(ic).
:- lib(lists).
:- lib(assoc).
:- lib(hash).

% Main predicate to generate the extended mapping
extend_mapping_with_function_calls(OriginalMapping, FunctionCalls, ExtendedMapping) :-
    % Create lookup structures for efficiency
    create_original_lookup(OriginalMapping, OriginalLookup),
    create_function_call_lookup(FunctionCalls, FunctionCallLookup),
    
    % Get all unique (Node, Label) pairs from original mapping
    extract_node_labels(OriginalMapping, NodeLabels),
    
    % Compute extended mapping for each (Node, Label) pair
    compute_extended_mapping(NodeLabels, OriginalLookup, FunctionCallLookup, ExtendedMapping).

% Create efficient lookup structure for original mapping
create_original_lookup([], Empty) :-
    empty_assoc(Empty).
create_original_lookup([(Node, Label) - Edges | Rest], Lookup) :-
    create_original_lookup(Rest, RestLookup),
    put_assoc((Node, Label), RestLookup, Edges, Lookup).

% Create efficient lookup structure for function calls
create_function_call_lookup([], Empty) :-
    empty_assoc(Empty).
create_function_call_lookup([function_call(From, To, Label) | Rest], Lookup) :-
    create_function_call_lookup(Rest, RestLookup),
    (   get_assoc(From, RestLookup, ExistingCalls) ->
        put_assoc(From, RestLookup, [(To, Label) | ExistingCalls], Lookup)
    ;   put_assoc(From, RestLookup, [(To, Label)], Lookup)
    ).

% Extract all (Node, Label) pairs from original mapping
extract_node_labels([], []).
extract_node_labels([(Node, Label) - _ | Rest], [(Node, Label) | NodeLabels]) :-
    extract_node_labels(Rest, NodeLabels).

% Compute extended mapping for all node-label pairs
compute_extended_mapping([], _, _, []).
compute_extended_mapping([(Node, Label) | Rest], OriginalLookup, FunctionCallLookup, 
                        [(Node, Label) - ExtendedEdges | ExtendedRest]) :-
    % Compute extended edges for this (Node, Label) pair
    empty_assoc(VisitedEmpty),
    compute_extended_edges_for_node(Node, Label, OriginalLookup, FunctionCallLookup, 
                                   VisitedEmpty, ExtendedEdges),
    
    % Process remaining nodes
    compute_extended_mapping(Rest, OriginalLookup, FunctionCallLookup, ExtendedRest).

% Compute extended edges for a specific (Node, Label) pair with cycle detection
compute_extended_edges_for_node(Node, Label, OriginalLookup, FunctionCallLookup, 
                                Visited, ExtendedEdges) :-
    % Check if we've already visited this (Node, Label) to avoid cycles
    (   get_assoc((Node, Label), Visited, _) ->
        ExtendedEdges = []
    ;   
        % Mark this (Node, Label) as visited
        put_assoc((Node, Label), Visited, true, NewVisited),
        
        % Get original direct edges
        (   get_assoc((Node, Label), OriginalLookup, DirectEdges) ->
            true
        ;   DirectEdges = []
        ),
        
        % Check for direct function calls from this node with this label
        (   get_assoc(Node, FunctionCallLookup, FunctionCalls) ->
            process_direct_function_calls(FunctionCalls, Label, OriginalLookup, 
                                         FunctionCallLookup, NewVisited, DirectFuncEdges)
        ;   DirectFuncEdges = []
        ),
        
        % Compute indirect edges through successors
        compute_indirect_edges(DirectEdges, OriginalLookup, FunctionCallLookup, 
                              NewVisited, IndirectEdges),
        
        % Combine all edges and remove duplicates
        append(DirectEdges, DirectFuncEdges, TempEdges),
        append(TempEdges, IndirectEdges, AllEdges),
        remove_duplicates(AllEdges, ExtendedEdges)
    ).

% Process direct function calls from the current node
process_direct_function_calls([], _, _, _, _, []).
process_direct_function_calls([(FuncStart, FuncLabel) | RestCalls], NodeLabel, 
                             OriginalLookup, FunctionCallLookup, Visited, AllCallEdges) :-
    % Only follow function call if the node label matches the function call label
    (   NodeLabel = FuncLabel ->
        % Get successors of the function start with label 'true'
        compute_extended_edges_for_node(FuncStart, true, OriginalLookup, 
                                       FunctionCallLookup, Visited, FuncEdges)
    ;   FuncEdges = []
    ),
    
    % Process remaining function calls
    process_direct_function_calls(RestCalls, NodeLabel, OriginalLookup, 
                                 FunctionCallLookup, Visited, RestCallEdges),
    
    % Combine results
    append(FuncEdges, RestCallEdges, AllCallEdges).

% Compute indirect edges by following function calls
compute_indirect_edges([], _, _, _, []).
compute_indirect_edges([(TargetNode, EdgeLabel) | RestEdges], OriginalLookup, 
                      FunctionCallLookup, Visited, IndirectEdges) :-
    % Check if there are function calls from TargetNode
    (   get_assoc(TargetNode, FunctionCallLookup, FunctionCalls) ->
        % Process each function call from this node
        process_function_calls(FunctionCalls, EdgeLabel, OriginalLookup, 
                              FunctionCallLookup, Visited, CallEdges)
    ;   CallEdges = []
    ),
    
    % Process remaining direct edges
    compute_indirect_edges(RestEdges, OriginalLookup, FunctionCallLookup, 
                          Visited, RestIndirectEdges),
    
    % Combine results
    append(CallEdges, RestIndirectEdges, IndirectEdges).

% Process function calls from a specific node with a specific edge label
process_function_calls([], _, _, _, _, []).
process_function_calls([(FuncStart, FuncLabel) | RestCalls], EdgeLabel, 
                      OriginalLookup, FunctionCallLookup, Visited, AllCallEdges) :-
    % Only follow function call if the edge label matches the function call label
    (   EdgeLabel = FuncLabel ->
        % Get successors of the function start with label 'true'
        compute_extended_edges_for_node(FuncStart, true, OriginalLookup, 
                                       FunctionCallLookup, Visited, FuncEdges)
    ;   FuncEdges = []
    ),
    
    % Process remaining function calls
    process_function_calls(RestCalls, EdgeLabel, OriginalLookup, 
                          FunctionCallLookup, Visited, RestCallEdges),
    
    % Combine results
    append(FuncEdges, RestCallEdges, AllCallEdges).

% Remove duplicates from edge list
remove_duplicates([], []).
remove_duplicates([Edge | Rest], UniqueList) :-
    (   member(Edge, Rest) ->
        % Edge is a duplicate, skip it and process rest
        remove_duplicates(Rest, UniqueList)
    ;   % Edge is unique, keep it and process rest
        remove_duplicates(Rest, UniqueRest),
        UniqueList = [Edge | UniqueRest]
    ).

% Utility predicate to print the extended mapping in a readable format
print_extended_mapping([]).
print_extended_mapping([(Node, Label) - Edges | Rest]) :-
    format('From node ~w with label ~w: ~w~n', [Node, Label, Edges]),
    print_extended_mapping(Rest).

% Example usage predicate
example_usage :-
    % Original mapping
    OriginalMapping = [
        (start('Calculate_output3'), true) - [(1, false), (1, true)],
        (1, true) - [],
        (1, false) - [],
        (start('Calculate_output2'), true) - [(2, false), (2, true)],
        (2, true) - [],
        (2, false) - [],
        (start('Calculate_output'), true) - [(3, false), (3, true)],
        (3, true) - [],
        (3, false) - [],
        (start('Main'), true) - [(6, false), (6, true), (5, false), (5, true), (4, false), (4, true)],
        (6, true) - [(4, false), (4, true)],
        (4, true) - [],
        (4, false) - [],
        (6, false) - [(5, false), (5, true)],
        (5, true) - [],
        (5, false) - [],
        (start(elaboration), true) - []
    ],
    
    % Function calls
    FunctionCalls = [
        function_call(2, start('Calculate_output3'), false),
        function_call(3, start('Calculate_output2'), false),
        function_call(4, start('Calculate_output'), true),
        function_call(4, start('Calculate_output'), false),
        function_call(5, start('Calculate_output3'), true),
        function_call(5, start('Calculate_output'), true),
        function_call(5, start('Calculate_output'), false)
    ],
    
    % Generate extended mapping
    extend_mapping_with_function_calls(OriginalMapping, FunctionCalls, ExtendedMapping),
    
    % Print results
    nl, write('Extended Mapping:'), nl,
    print_extended_mapping(ExtendedMapping).

% Optimized version for large datasets using ECLiPSe's hash tables for memoization
extend_mapping_optimized(OriginalMapping, FunctionCalls, ExtendedMapping) :-
    create_original_lookup(OriginalMapping, OriginalLookup),
    create_function_call_lookup(FunctionCalls, FunctionCallLookup),
    extract_node_labels(OriginalMapping, NodeLabels),
    
    % Create a hash table for memoization
    hash_create(MemoTable),
    
    % Compute extended mapping with memoization
    compute_extended_mapping_memoized(NodeLabels, OriginalLookup, FunctionCallLookup, 
                                     MemoTable, ExtendedMapping).

compute_extended_mapping_memoized([], _, _, _, []).
compute_extended_mapping_memoized([(Node, Label) | Rest], OriginalLookup, FunctionCallLookup, 
                                 MemoTable, [(Node, Label) - ExtendedEdges | ExtendedRest]) :-
    compute_extended_edges_memoized(Node, Label, OriginalLookup, FunctionCallLookup, 
                                   MemoTable, ExtendedEdges),
    compute_extended_mapping_memoized(Rest, OriginalLookup, FunctionCallLookup, 
                                     MemoTable, ExtendedRest).

% Memoized version of extended edge computation
compute_extended_edges_memoized(Node, Label, OriginalLookup, FunctionCallLookup, 
                               MemoTable, ExtendedEdges) :-
    Key = (Node, Label),
    (   hash_get(MemoTable, Key, CachedResult) ->
        % Use cached result
        ExtendedEdges = CachedResult
    ;   % Compute and cache result
        empty_assoc(VisitedEmpty),
        compute_extended_edges_for_node(Node, Label, OriginalLookup, FunctionCallLookup, 
                                       VisitedEmpty, ExtendedEdges),
        hash_set(MemoTable, Key, ExtendedEdges)
    ).
*/
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*chat gpt below
%%%
:- lib(assoc).
:- lib(lists).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Utilities: foldl, include, pairs_keys, ordset helpers
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% foldl(+Pred, +List, +Acc0, -Acc).
foldl(_, [], Acc, Acc).
foldl(Pred, [X|Xs], Acc0, Acc) :-
    call(Pred, X, Acc0, Acc1),
    foldl(Pred, Xs, Acc1, Acc).

% my_include(+Goal, +List, -Filtered).
my_include(_, [], []).
my_include(Goal, [X|Xs], [X|Ys]) :-
    call(Goal, X), !,
    my_include(Goal, Xs, Ys).
my_include(Goal, [_|Xs], Ys) :-
    my_include(Goal, Xs, Ys).

% pairs_keys(+Pairs, -Keys).
pairs_keys([], []).
pairs_keys([K-_|T], [K|Ks]) :-
    pairs_keys(T, Ks).

% ord_union(+A,+B,-U). Merge two sorted lists.
ord_union(A, B, U) :- ( A==[] -> U=B ; B==[] -> U=A ; ord_union_merge(A,B,U) ).
ord_union_merge([], B, B).
ord_union_merge(A, [], A).
ord_union_merge([X|Xs],[Y|Ys], [X|Zs]) :-
    X @< Y, !, ord_union_merge(Xs,[Y|Ys],Zs).
ord_union_merge([X|Xs],[Y|Ys], [Y|Zs]) :-
    Y @< X, !, ord_union_merge([X|Xs],Ys,Zs).
ord_union_merge([X|Xs],[X|Ys],[X|Zs]) :- !, ord_union_merge(Xs,Ys,Zs).

% insert_sorted/3: insert element into sorted list without duplicates
insert_sorted(X, [], [X]).
insert_sorted(X, [H|T], [X,H|T]) :- X @< H, !.
insert_sorted(X, [H|T], [H|T2]) :-
    X == H, !, T2=T.
insert_sorted(X, [H|T], [H|T2]) :-
    insert_sorted(X, T, T2).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Build adjacency assoc
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

augment_mapping(BaseMapList, FunctionCallList, AugmentedMapList) :-
    empty_assoc(Adj0),
    foldl(add_base_entry, BaseMapList, Adj0, Adj1),
    foldl(add_call_entry, FunctionCallList, Adj1, Adj),
    assoc_to_list(Adj, Pairs),
    pairs_keys(Pairs, Keys),
    empty_assoc(EmptyReach),
    init_reach_assoc(Keys, Adj, EmptyReach, Reach0),
    propagate_fixpoint(Adj, Keys, Reach0, ReachFinal),
    assoc_to_list(ReachFinal, ReachPairs),
    map_assoc_pairs_to_output(ReachPairs, AugmentedMapList).

add_base_entry((Node,Label)-Neighbors, AdjIn, AdjOut) :-
    Key = node_label(Node, Label),
    convert_neighbors(Neighbors, NeighNodes0),
    sort(NeighNodes0, NeighNodes),   % ensure ordset once
    ( get_assoc(Key, AdjIn, Existing) ->
        ord_union(Existing, NeighNodes, New),
        put_assoc(Key, AdjIn, New, AdjOut)
    ; put_assoc(Key, AdjIn, NeighNodes, AdjOut)
    ).

convert_neighbors([], []).
convert_neighbors([(N,L)|T], [node_label(N,L)|TT]) :- !, convert_neighbors(T,TT).
convert_neighbors([node_label(N,L)|T], [node_label(N,L)|TT]) :- !, convert_neighbors(T,TT).
convert_neighbors([Other|T], [NN|TT]) :-
    (Other=(N,L) -> NN=node_label(N,L) ; NN=Other),
    convert_neighbors(T, TT).

add_call_entry(function_call(From, ToStart, CallLabel), AdjIn, AdjOut) :-
    Key = node_label(From, CallLabel),
    ToKey = node_label(ToStart, true),
    ( get_assoc(Key, AdjIn, Existing) ->
        ( memberchk(ToKey, Existing) -> AdjOut=AdjIn
        ; insert_sorted(ToKey, Existing, New),
          put_assoc(Key, AdjIn, New, AdjOut)
        )
    ; put_assoc(Key, AdjIn, [ToKey], AdjOut)
    ).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Initial reach sets
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

init_reach_assoc([], _, Reach, Reach).
init_reach_assoc([Key|Ks], Adj, ReachIn, ReachOut) :-
    ( get_assoc(Key, Adj, Neighs) -> true ; Neighs=[] ),
    my_include(is_non_start, Neighs, Immediate),
    sort(Immediate, UniqueImmediate),
    put_assoc(Key, ReachIn, UniqueImmediate, ReachMid),
    init_reach_assoc(Ks, Adj, ReachMid, ReachOut).

is_start(Node) :- Node = start(_).
is_non_start(node_label(Node,_)) :- \+ is_start(Node).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Worklist fixpoint propagation
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

propagate_fixpoint(Adj, Keys, ReachIn, ReachOut) :-
    build_pred_assoc(Keys, Adj, PredAssoc),
    collect_nonempty_reach_keys(Keys, ReachIn, WL0),
    propagate_worklist(Adj, PredAssoc, ReachIn, WL0, ReachOut).

collect_nonempty_reach_keys([], _, []).
collect_nonempty_reach_keys([K|Ks], Reach, WL) :-
    ( get_assoc(K, Reach, R), R \== [] ->
        WL=[K|More], collect_nonempty_reach_keys(Ks, Reach, More)
    ; collect_nonempty_reach_keys(Ks, Reach, WL)
    ).

build_pred_assoc(Keys, Adj, PredAssocOut) :-
    empty_assoc(P0),
    build_pred_assoc_keys(Keys, Adj, P0, PredAssocOut).

build_pred_assoc_keys([], _, P, P).
build_pred_assoc_keys([K|Ks], Adj, PIn, POut) :-
    ( get_assoc(K, Adj, Neighs) -> true ; Neighs=[] ),
    add_preds_for_neighs(K, Neighs, PIn, PMid),
    build_pred_assoc_keys(Ks, Adj, PMid, POut).

add_preds_for_neighs(_, [], P, P).
add_preds_for_neighs(PredKey, [N|Ns], PIn, POut) :-
    ( get_assoc(N, PIn, Existing) ->
        ( memberchk(PredKey, Existing) -> PIn2=PIn
        ; insert_sorted(PredKey, Existing, New),
          put_assoc(N, PIn, New, PIn2)
        )
    ; put_assoc(N, PIn, [PredKey], PIn2)
    ),
    add_preds_for_neighs(PredKey, Ns, PIn2, POut).

propagate_worklist(_, _, Reach, [], Reach).
propagate_worklist(Adj, PredAssoc, ReachIn, [Src|WL], ReachOut) :-
    ( get_assoc(Src, ReachIn, ReachSrc) -> true ; ReachSrc=[] ),
    ( get_assoc(Src, PredAssoc, Preds) -> true ; Preds=[] ),
    propagate_to_preds(Preds, Src, ReachSrc, ReachIn, ReachMid, NewPreds),
    append(WL, NewPreds, WL2),
    propagate_worklist(Adj, PredAssoc, ReachMid, WL2, ReachOut).

propagate_to_preds([], _, _, Reach, Reach, []).
propagate_to_preds([Pred|Ps], Src, ReachSrc, ReachIn, ReachOut, Grown) :-
    Src=node_label(Node,_),
    ( Node=start(_) -> IncludeSrc=[] ; IncludeSrc=[Src] ),
    ord_union(IncludeSrc, ReachSrc, ToAdd),
    ( ToAdd==[] ->
        ReachMid=ReachIn, Grew=[]
    ;
        ( get_assoc(Pred, ReachIn, Curr) -> true ; Curr=[] ),
        ord_union(Curr, ToAdd, New),
        ( New==Curr ->
            ReachMid=ReachIn, Grew=[]
        ;
            put_assoc(Pred, ReachIn, New, ReachMid),
            Grew=[Pred]
        )
    ),
    propagate_to_preds(Ps, Src, ReachSrc, ReachMid, ReachOut, RestGrown),
    append(Grew, RestGrown, Grown).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Output conversion
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

map_assoc_pairs_to_output([], []).
map_assoc_pairs_to_output([node_label(N,L)-Neighs|Rest],
                          [(N,L)-OutNeighs|OutRest]) :-
    convert_back_neighbors(Neighs, OutNeighs),
    map_assoc_pairs_to_output(Rest, OutRest).

convert_back_neighbors([], []).
convert_back_neighbors([node_label(N,L)|T], [(N,L)|TT]) :-
    convert_back_neighbors(T, TT).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Example demo
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

example_demo(Aug) :-
    Base = [
      (start(Calculate_output3), true)-[(1,false),(1,true)],
      (1,true)-[], (1,false)-[],
      (start(Calculate_output2), true)-[(2,false),(2,true)],
      (2,true)-[], (2,false)-[],
      (start(Calculate_output), true)-[(3,false),(3,true)],
      (3,true)-[], (3,false)-[],
      (start(Main), true)-[(6,false),(6,true),(5,false),(5,true),(4,false),(4,true)],
      (6,true)-[(4,false),(4,true)], (4,true)-[], (4,false)-[],
      (6,false)-[(5,false),(5,true)], (5,true)-[], (5,false)-[],
      (start(elaboration), true)-[]
    ],
    Calls = [
      function_call(2, start(Calculate_output3), false),
      function_call(3, start(Calculate_output2), false),
      function_call(4, start(Calculate_output), true),
      function_call(4, start(Calculate_output), false),
      function_call(5, start(Calculate_output3), true),
      function_call(5, start(Calculate_output), true),
      function_call(5, start(Calculate_output), false)
    ],
    augment_mapping(Base, Calls, Aug).




/*
% ---------------------------------------------------------------------
% Public entry point:
%   augment_mapping(+BaseMapList, +FunctionCallList, -AugmentedMapList)
%
% BaseMapList:  list of entries of the form (Node,Label)-Neighbors
%               where Neighbors is a list of (ToNode,ToLabel) pairs.
% FunctionCallList: list of function_call(From, ToStart, CallLabel) terms
% AugmentedMapList: same shape as BaseMapList, but successors augmented.
% ---------------------------------------------------------------------
augment_mapping(BaseMapList, FunctionCallList, AugmentedMapList) :-
    empty_assoc(Adj0),
    foldl(add_base_entry, BaseMapList, Adj0, Adj1),
    foldl(add_call_entry, FunctionCallList, Adj1, Adj),
    assoc_to_list(Adj, Pairs),
    pairs_keys(Pairs, Keys),
    empty_assoc(EmptyReach),
    init_reach_assoc(Keys, Adj, EmptyReach, Reach0),
    propagate_fixpoint(Adj, Keys, Reach0, ReachFinal),
    assoc_to_list(ReachFinal, ReachPairs),
    map_assoc_pairs_to_output(ReachPairs, AugmentedMapList).

% ---------------------------------------------------------------------
% Build adjacency assoc from base mapping and function calls.
% Keys and neighbor items are stored as node_label(Node,Label) terms.
% ---------------------------------------------------------------------
% ---------------------------------------------------------------------
% Simple foldl replacement in ECLiPSe
% ---------------------------------------------------------------------
foldl(_, [], Acc, Acc).
foldl(Pred, [X|Xs], Acc0, Acc) :-
    call(Pred, X, Acc0, Acc1),
    foldl(Pred, Xs, Acc1, Acc).

add_base_entry((Node,Label)-Neighbors, AdjIn, AdjOut) :-
    Key = node_label(Node, Label),
    convert_neighbors(Neighbors, NeighNodes),
    ( get_assoc(Key, AdjIn, Existing) ->
        union_sorted(Existing, NeighNodes, New) ,
        put_assoc(Key, AdjIn, New, AdjOut)
    ; put_assoc(Key, AdjIn, NeighNodes, AdjOut)
    ).
% If list uses pair syntax Key-Neighbors where Key is already node_label/2:
add_base_entry(Key-Neighbors, AdjIn, AdjOut) :-
    Key = node_label(_, _),
    convert_neighbors(Neighbors, NeighNodes),
    ( get_assoc(Key, AdjIn, Existing) ->
        union_sorted(Existing, NeighNodes, New) ,
        put_assoc(Key, AdjIn, New, AdjOut)
    ; put_assoc(Key, AdjIn, NeighNodes, AdjOut)
    ).

% convert neighbor representations like (N,L) to node_label(N,L)
convert_neighbors([], []).
convert_neighbors([ (N,L) | T], [ node_label(N,L) | TT]) :- !, convert_neighbors(T, TT).
convert_neighbors([ node_label(N,L) | T], [ node_label(N,L) | TT]) :- !, convert_neighbors(T, TT).
convert_neighbors([Other|T], R) :-
    % tolerate mixed representations (be permissive)
    ( Other = (N,L) -> NN = node_label(N,L) ; NN = Other ),
    convert_neighbors(T, TT),
    R = [NN|TT].

% Add function_call edges: From/CallLabel -> ToStart,true
add_call_entry(function_call(From, ToStart, CallLabel), AdjIn, AdjOut) :-
    Key = node_label(From, CallLabel),
    ToKey = node_label(ToStart, true),
    ( get_assoc(Key, AdjIn, Existing) ->
        ( memberchk(ToKey, Existing) -> AdjOut = AdjIn
        ; sort([ToKey|Existing], New), put_assoc(Key, AdjIn, New, AdjOut)
        )
    ; put_assoc(Key, AdjIn, [ToKey], AdjOut)
    ).

% ---------------------------------------------------------------------
% Initialize Reach assoc: for each key, immediate non-start neighbors only
% (we will add recursively via fixpoint propagation)
% ---------------------------------------------------------------------
init_reach_assoc([], _, Reach, Reach).
init_reach_assoc([Key|Ks], Adj, ReachIn, ReachOut) :-
    ( get_assoc(Key, Adj, Neighs) -> true ; Neighs = [] ),
    my_include(is_non_start, Neighs, Immediate),
    sort(Immediate, UniqueImmediate),
    put_assoc(Key, ReachIn, UniqueImmediate, ReachMid),
    init_reach_assoc(Ks, Adj, ReachMid, ReachOut).

% keep elements that satisfy Goal
my_include(_, [], []).
my_include(Goal, [X|Xs], [X|Ys]) :-
    call(Goal, X), !,
    my_include(Goal, Xs, Ys).
my_include(Goal, [_|Xs], Ys) :-
    my_include(Goal, Xs, Ys).

is_start(Node) :- Node = start(_).
is_non_start(node_label(Node,_)) :- \+ is_start(Node).

% ---------------------------------------------------------------------
% Fixpoint propagation:
%   for every Key, for each neighbor M of Key:
%     include M if non-start, and include Reach[M] (if any).
%   Repeat until no change.
% ---------------------------------------------------------------------
propagate_fixpoint(Adj, Keys, ReachIn, ReachOut) :-
    one_pass(Adj, Keys, ReachIn, ReachMid, Changed),
    ( Changed == true -> propagate_fixpoint(Adj, Keys, ReachMid, ReachOut)
    ; ReachOut = ReachMid
    ).

one_pass(_, [], Reach, Reach, false).
one_pass(Adj, [Key|Ks], ReachIn, ReachOut, ChangedAll) :-
    ( get_assoc(Key, Adj, Neighs) -> true ; Neighs = [] ),
    % collect items to add: immediate non-start neighbors and all Reach sets of neighbors
    collect_additions(Neighs, ReachIn, Adj, AddList),
    ( get_assoc(Key, ReachIn, Curr) -> true ; Curr = [] ),
    union_sorted(Curr, AddList, New),
    ( New == Curr -> Changed = false, ReachMid = ReachIn
    ; put_assoc(Key, ReachIn, New, ReachMid), Changed = true
    ),
    one_pass(Adj, Ks, ReachMid, ReachOut, ChangedRest),
    ( Changed = true ; ChangedRest = true -> ChangedAll = true ; ChangedAll = false ).

% collect additions for a list of neighbors:
%   - if neighbor is non-start: include neighbor + Reach[neighbor]
%   - if neighbor is start(...): include Reach[start(...), true] only (do not include the start node itself)
collect_additions([], _, _, []).
collect_additions([N|Ns], ReachIn, Adj, TotalAdd) :-
    ( N = node_label(Node,_),
      is_start(Node) ->
        % use the special start(true) key
        KeyTarget = node_label(Node, true),
        ( get_assoc(KeyTarget, ReachIn, Rtarget) -> Add1 = Rtarget ; Add1 = [] )
    ;
        % non-start: include N itself and its reach set
        ( get_assoc(N, ReachIn, Rn) -> Add1 = [N|Rn] ; Add1 = [N] )
    ),
    collect_additions(Ns, ReachIn, Adj, RestAdd),
    append(Add1, RestAdd, A),
    sort(A, TotalAdd).  % maintain ord-set shape

% ---------------------------------------------------------------------
% Helpers: convert assoc pairs (node_label... -> ReachList) back into user's
% (Node,Label)-[(ToNode,ToLabel), ...] format.
% ---------------------------------------------------------------------
map_assoc_pairs_to_output([], []).
map_assoc_pairs_to_output([node_label(Node,Label)-Neighs | Rest], [ (Node,Label)-OutNeighbors | OutRest]) :-
    convert_back_neighbors(Neighs, OutNeighbors),
    map_assoc_pairs_to_output(Rest, OutRest).

convert_back_neighbors([], []).
convert_back_neighbors([node_label(N,L)|T], [(N,L)|TT]) :-
    convert_back_neighbors(T, TT).

% ---------------------------------------------------------------------
% Misc small utilities
% ---------------------------------------------------------------------
pairs_keys([], []).
pairs_keys([K-_|T], [K|Ks]) :- pairs_keys(T, Ks).

% union sorted lists (works with arbitrary term order)
union_sorted(A, B, U) :- append(A,B,AB), sort(AB, U).

% ---------------------------------------------------------------------
% Example run predicate using your sample input (from the problem statement).
% Load file and call `example_demo(Aug).`
% ---------------------------------------------------------------------
example_demo(Aug) :-
    Base = [
      (start(Calculate_output3), true)-[ (1,false), (1,true) ],
      (1,true)-[],
      (1,false)-[],
      (start(Calculate_output2), true)-[ (2,false), (2,true) ],
      (2,true)-[],
      (2,false)-[],
      (start(Calculate_output), true)-[ (3,false), (3,true) ],
      (3,true)-[],
      (3,false)-[],
      (start(Main), true)-[ (6,false),(6,true),(5,false),(5,true),(4,false),(4,true) ],
      (6,true)-[ (4,false),(4,true) ],
      (4,true)-[],
      (4,false)-[],
      (6,false)-[ (5,false),(5,true) ],
      (5,true)-[],
      (5,false)-[],
      (start(elaboration), true)-[]
    ],
    Calls = [
      function_call(2, start(Calculate_output3), false),
      function_call(3, start(Calculate_output2), false),
      function_call(4, start(Calculate_output), true),
      function_call(4, start(Calculate_output), false),
      function_call(5, start(Calculate_output3), true),
      function_call(5, start(Calculate_output3), true),
      function_call(5, start(Calculate_output), false)
    ],
    augment_mapping(Base, Calls, Aug),
    Aug = AugmentedMap,
    !.

% ---------------------------------------------------------------------
% End of file
% ---------------------------------------------------------------------
*/
*/