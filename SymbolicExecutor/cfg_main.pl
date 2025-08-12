%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                                 Copyright 2025 SETU - Dr Christophe Meudec 
%%                                     <https://github.com/echancrure/Sikraken>
%% This file is part of Sikraken.
%% Sikraken is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
%%   the Free Software Foundation.
%% Sikraken is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
%%   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
%% GNU Lesser General Public License v3.0 only
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This is the top level file for the creation and querying of the CFG of the C code under test.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- lib(graph_algorithms).
:- lib(graphviz).
:- compile([cfg_build, cfg_analyse]).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%create se_sub_atts variables for all (all global in C) functions 
cfg_build__declare_functions(Parsed_prolog_code) :-
    declare_functions(Parsed_prolog_code).
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    declare_functions([]) :-
        !.
    declare_functions([Decl|Rest]) :-
        !,
        declare_functions(Decl),
        declare_functions(Rest).
    declare_functions(declaration(spec([typedef], Type_spec), Declarators)) :-
        !,
        symbolic_execute(declaration(spec([typedef], Type_spec), Declarators), 'carry_on').
    declare_functions(declaration(Declaration_specifiers, Declarators)) :-
        !,
        ((Declarators = [Declarator], nonvar(Declarator), 
         (Declarator = function(Function_name, Parameters) ; (Declarator = ptr_decl(pointer, Function), nonvar(Function), Function = function(Function_name, Parameters)))
         ) ->  %a function forward declaration
            (Declaration_specifiers = spec([extern], _Type_spec) ->   %found an extern function declaration
                (extract_type(Declaration_specifiers, Return_type_name),
                 se_sub_atts__create(Return_type_name, Parameters, 'no_body_is_extern', Function_name)
                )
            ;
             (se_name_atts__get(Function_name, 'name', Inner_name), is_verifier_input_function(Inner_name, _)) -> %some testcomp benchmarks do not declare the verifier functions as extern; as a hack we declare them here
                (extract_type(Declaration_specifiers, Return_type_name),
                 se_sub_atts__create(Return_type_name, Parameters, 'no_body_is_extern', Function_name)
                )
            ; 
                true    %we ignore all other, non-extern, forward function declarations: they will be defined later [can we not ignore them all?]
            )
        ;
            (%variable declarations
             true
            )
        ).
    declare_functions(function(Specifiers, function(Function_name, Parameters), [], Compound_statement)) :-
        !,
        extract_type(Specifiers, Return_type_name),
        se_sub_atts__create(Return_type_name, Parameters, Compound_statement, Function_name).
    %what kind of function is this? pointer to function cannot have bodies in C...
    declare_functions(function(Specifiers, ptr_decl(pointer, function(Function_name, Parameters)), [], Compound_statement)) :-
        !,
        extract_type(Specifiers, Return_type_name),
        extract_pointers(ptr_decl(pointer, function(Function_name, Parameters)), Return_type_name, Type_name_ptr_opt, _Clean_var),
        se_sub_atts__create(Type_name_ptr_opt, Parameters, Compound_statement, Function_name).
    declare_functions(_).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cfg_main__build_cfg(Parsed_prolog_code) :-
    cfg_build__init,
    cfg_build__build_cfg(Parsed_prolog_code, elaboration),
    cfg_build__create_graph(graph(Nodes, Edges)),
    (se_globals__get_val(debug_mode, debug) ->   %some overheads but only in debugging mode (implement your own if that is an issue)
        mytrace,
        writeln('CFG Nodes:'),
        writeln(Nodes),
        writeln('CFG Edges:'),
        writeln(Edges),
        writeln('CFG Graph:'),
        ArrayNodes =.. ['[]'|Nodes],    %trick to transform a list into a Prolog array
        make_graph_symbolic(ArrayNodes, Edges, Graph),
        view_graph(Graph, [edge_attrs_generator : edge_label_attrs])    %trying to add labels to individual edges but does not work
    ;
        true
    ),
    all_successor_edges_with_labels(graph(Nodes, Edges), Reachable_edges_mapping),
    se_globals__set_val('reachable_edges_mapping', Reachable_edges_mapping).
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Edge attribute generator — adds label to edge
        edge_label_attrs(_Graph, e(_From, _To, Label), [label=Label, color=Color]) :-   %note: must use e/3 to match the internal edge format
            ( Label == true  -> Color = green
            ; Label == false -> Color = red
            ;                   Color = black
            ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cfg_main__bran_is_already_covered(Branch) :-
    se_globals__get_val('covered_bran', Already_covered),
    memberchk(Branch, Already_covered).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cfg_main__bran_newly_covered(Newly_covered) :-
    se_globals__get_ref('current_path_bran', Current_path),
    prune_instances(Current_path, Current_path_no_duplicates),
    se_globals__get_val('covered_bran', Already_covered),
    subtract(Current_path_no_duplicates, Already_covered, Newly_covered).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
cfg_main__arcs_remaining :-
    %get overall arcs: cannot do this until we build CFG
    %se_globals__get_val('covered_bran', _Already_covered).
    fail.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%