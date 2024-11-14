%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
declare_declarators([], _).
declare_declarators([Declarator|R], Type_name) :-
    %mytrace,
    (nonvar(Declarator), Declarator = initialised(Var, Expression) ->   %added nonvar(...) as a guard 30/07/24
        symbolically_interpret(cast(Type_name, Expression), symb(_Type, Casted))
    ;
        (%declaration of non-initialised variable
         %todo check for redefinition which is allowed: see diary 07/08/24
         Var = Declarator,
         Casted = 0 %todo: should be only for global and static variables as non-static and automatic objects are not initialised in C see K&R p. 219
        )
    ),
    %C pointers variables are not ptc_solver variable: they are handled syntactically e.g. seav(pointer(integer), not_needed, addr(Y_2{se_seav_atts : seav(integer, not_needed, 42)}))
    extract_pointers(Var, Type_name, Type_name_ptr_opt, Clean_var), %e.g. extract_pointers(ptr_decl(pointer, Pi_3{c_id(pi)}), integer, pointer(integer), Pi_3)
    seav__create_var(Type_name_ptr_opt, Clean_var),
    seav__update(Clean_var, 'input', 'not_needed'),
    seav__update(Clean_var, 'output', Casted),
    declare_declarators(R, Type_name).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
declare_typedefs([], _).
declare_typedefs([Typedef|R], Type_name) :-
    extract_pointers(Typedef, Type_name, Type_name_ptr_opt, Clean_typedef_var),
    se_typedef_atts__create(Type_name_ptr_opt, Clean_typedef_var),
    declare_typedefs(R, Type_name).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%e.g. extract_pointers(ptr_decl(pointer, X), int, pointer(int), X)
extract_pointers(Var, Type_name, Type_name_ptr_opt, Clean_var) :-
    (nonvar(Var), Var = ptr_decl(Ptr_exp, Clean_var) ->
        extract_inner_pointers(Ptr_exp, Type_name, Type_name_ptr_opt)
    ;
        (%not a pointer variable declaration
         Type_name_ptr_opt = Type_name,
         Clean_var = Var
        )    
    ).
    %%%
    extract_inner_pointers(Ptr_exp, Type_name, Type_name_ptr_opt) :-
        (Ptr_exp == 'pointer' ->
            Type_name_ptr_opt = pointer(Type_name)
        ;
         Ptr_exp = pointer(qual(_Type_qualifier_list)) ->   %we discard the Type_qualifier_list for now [const|restrict|volatile|atomic]
            Type_name_ptr_opt = pointer(Type_name)
        ;
         Ptr_exp = pointer(Inner_ptr_exp) ->
            (extract_inner_pointers(Inner_ptr_exp, Type_name, Inner_type_name),
             Type_name_ptr_opt = pointer(Inner_type_name)
            )
        ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
declare_params([], []).
declare_params([param(Specifiers, Param)|R], [Clean_param|R_params]) :-
    extract_type(Specifiers, Type_name),
    extract_pointers(Param, Type_name, Type_name_ptr_opt, Clean_param),
    ptc_solver__variable([Input_var], Type_name),
    (Type_name_ptr_opt = pointer(_) ->
        Input = addr(Input_var)         %C pointers variables are not ptc_solver variable: they are handled syntactically e.g. seav(pointer(integer), not_needed, addr(Y_2{se_seav_atts : seav(integer, not_needed, 42)}))
    ;
        Input = Input_var
    ),
    seav__create_var(Type_name_ptr_opt, Clean_param),
    seav__update(Clean_param, 'input', Input),      %todo only needed for target function
    seav__update(Clean_param, 'output', Input),
    declare_params(R, R_params).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
declare_return(Return_seav, Type_name) :-
    extract_pointers(Return_seav, Type_name, Type_name_ptr_opt, Clean_return),
    ptc_solver__variable([Output_var], Type_name),
    (Type_name_ptr_opt = pointer(_) ->
         Output = addr(Output_var)           %C pointers variables are not ptc_solver variable: they are handled syntactically e.g. seav(pointer(integer), not_needed, addr(Y_2{se_seav_atts : seav(integer, not_needed, 42)}))
    ;
         Output = Output_var
    ),
    seav__create_var(Type_name_ptr_opt, Clean_return),
    seav__update(Clean_return, 'input', 'not_needed'),
    seav__update(Clean_return, 'output', Output).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%typedef occurs last in the list
extract_type([Typedef_var], Type) :-
    se_typedef_atts__is_typedef_atts(Typedef_var),
    !,
    se_typedef_atts__get(Typedef_var, 'type', Type).
extract_type(['unsigned'|R], unsigned(Type)) :-
    !,
    extract_type(R, Type).
extract_type(['signed'|R], Type) :- %signed is the default so we ignore it
    !,
    extract_type(R, Type).
extract_type(['const'|R], Type) :-
    !,
    common_util__error(8, "Type Qualifier: Ignored Semantics", "todo check how semantics is affected", [('type_qualifier', 'const')], '8_261024', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info),
    extract_type(R, Type).
extract_type(['restrict'|R], Type) :-
    !,
    common_util__error(8, "Type Qualifier: Ignored Semantics", "todo check how semantics is affected", [('type_qualifier', 'restrict')], '8_261024', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info),
    extract_type(R, Type).
extract_type(['volatile'|R], Type) :-
    !,
    common_util__error(8, "Type Qualifier: Ignored Semantics", "todo check how semantics is affected", [('type_qualifier', 'volatile')], '8_261024', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info),
    extract_type(R, Type).
extract_type(['atomic'|R], Type) :-
    !,
    common_util__error(8, "Type Qualifier: Ignored Semantics", "todo check how semantics is affected", [('type_qualifier', 'atomic')], '8_261024', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info),
    extract_type(R, Type).
extract_type(['int'], int) :-
    !.
extract_type(['char'], char) :-
    !.
extract_type(['short', 'int'], short) :-
    !.
extract_type(['short'], short) :-
    !.
extract_type(['long', 'int'], long) :-
    !.
extract_type(['long'], long) :-
    !.
extract_type(['long', 'long'], long_long) :-
    !.
extract_type(['long', 'double'], long_double) :-
    !.
extract_type(['float'], float) :-
    !.
extract_type(['double'], double) :-
    !.
extract_type(['bool'], bool) :-
    !.
extract_type(['void'], void) :-
    !.
extract_type([struct(Tag, Struct_decl_list)], _Struct_type) :-
    !,
    (Tag == 'anonymous' ->
        (true
        )
    ;
     Struct_decl_list == 'forward' ->
        (true
        )
    ;
        (true
        )
    ),
    common_util__error(9, "Struct Declarations are Not Handled", "Sikraken needs expanding", [('Tag', Tag)], '9_121124', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
extract_type(Specifiers, _Type_name) :-
    common_util__error(9, "Not Handled", "Sikraken needs expanding", [('Specifiers', Specifiers)], '9_270724', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
match_parameters_arguments([param_no_decl([void], [])], []) :-
    !.
match_parameters_arguments([], []) :-
    !.
match_parameters_arguments([param(Declaration_specifiers, Parameter)|Rest_parameters], [Argument|Rest_arguments]) :-
    !,
    extract_type(Declaration_specifiers, Type_name),
    declare_declarators([initialised(Parameter, Argument)], Type_name),
    match_parameters_arguments(Rest_parameters, Rest_arguments).
match_parameters_arguments(Parameters, Arguments) :-
    !,
    common_util__error(10, "mismatch of parameters and arguments", "Cannot call function", [('Parameters', Parameters), ('Arguments', Arguments)], '10160824_1', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%