%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
declare_declarators([], _).
declare_declarators([Declarator|R], Type_name) :-
    %mytrace,
    (nonvar(Declarator), Declarator = initialised(Var, Expression) ->   %added nonvar(...) as a guard 30/07/24
        symbolically_interpret(Expression, Symbolic)    %todo: handling initialised variables without re-using assignment symbolic execution is probably a bad idea
    ;
        (%declaration of non-initialised variable
         %todo check for redefinition which is allowed: see diary 07/08/24
         Var = Declarator,
         Symbolic = 0 %todo: should be only for global and static variables as non-static and automatic objects are not initialised in C see K&R p. 219
        )
    ),
    extract_pointers(Var, Type_name, Type_name_ptr_opt, Clean_var), %e.g. extract_pointers(pointer(Pi_3{c_id(pi)}), integer, pointer(integer), Pi_3)
    seav__create_var(Type_name_ptr_opt, Clean_var),
    seav__update(Clean_var, 'input', 'not_needed'),
    %create ptc solver variable and = to Symbolic
    (Type_name_ptr_opt = pointer(_) ->
        Output = Symbolic           %C pointers variables are not ptc_solver variable: they are handled syntactically e.g. seav(pointer(integer), not_needed, addr(Y_2{se_seav_atts : seav(integer, not_needed, 42)}))
    ;
        (ptc_solver__variable([Output], Type_name),
         ptc_solver__sdl(Output = Symbolic)
        )
    ),
    seav__update(Clean_var, 'output', Output),
    declare_declarators(R, Type_name).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%e.g. extract_pointers(pointer(X), int, pointer(int), X)
extract_pointers(Var, Type_name, Type_name_ptr_opt, Clean_var) :-
    (nonvar(Var), Var = pointer(Inner_var) ->
        (extract_pointers(Inner_var, Type_name, Inner_type_name, Clean_var),
         Type_name_ptr_opt = pointer(Inner_type_name)
        )
    ;
        (Type_name_ptr_opt = Type_name,
         Clean_var = Var
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
extract_type([int], integer) :-
    !.
extract_type([void], void) :-
    !.
extract_type(Specifiers, _Type_name) :-
    common_util__error(9, "Not Handled", "Sikraken needs expanding", [('Specifiers', Specifiers)], 9270724, 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
match_parameters_arguments([], []) :-
        !.
match_parameters_arguments([param(Declaration_specifiers, Parameter)|Rest_parameters], [Argument|Rest_arguments]) :-
    !,
    extract_type(Declaration_specifiers, Type_name),
    declare_declarators([initialised(Parameter, Argument)], Type_name),
    match_parameters_arguments(Rest_parameters, Rest_arguments).
match_parameters_arguments(Parameters, Arguments) :-
    !,
    common_util__error(10, "mismatch of parameters and arguments", "Cannot call function", [('Parameters', Parameters), ('Arguments', Arguments)], 10160824_1, 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%