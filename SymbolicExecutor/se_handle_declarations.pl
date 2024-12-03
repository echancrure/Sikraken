%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
declare_declarators([], _).
declare_declarators([Declarator|R], Type_name) :-
    %mytrace,
    %below is the ugliest Prolog code in Sikraken; I think modifying the parsed output may help ; actually entire rewrite is needed
    (nonvar(Declarator), Declarator = initialised(Direct_declarator, _) ->   %added nonvar(...) as a guard 30/07/24
        true
    ;
        (%declaration of non-initialised variable
         %todo check for redefinition which is allowed: see diary 07/08/24 [probably should remove existing scope value...]
         Direct_declarator = Declarator
        )
    ),
    %C pointers variables are not ptc_solver variable: they are handled syntactically e.g. seav(pointer(integer), not_needed, addr(Y_2{se_seav_atts : seav(integer, not_needed, 42)}))
    extract_pointers(Direct_declarator, Type_name, Type_name_ptr_opt, Clean_var), %e.g. extract_pointers(ptr_decl(pointer, Pi_3{c_id(pi)}), integer, pointer(integer), Pi_3)
    (nonvar(Declarator), Declarator = initialised(_, Expression) ->
        true
    ;
        (Default = int(0), %todo: [in effect same as Declarator = initialised(Direct_declarator, 0)] but only for global and static variables as non-static and automatic objects are not initialised in C see K&R p. 219
         get_pointer_type_default(Type_name_ptr_opt, Default, Expression)    %because non-initialised pointers, need to be initialised to addr(...addr(0)...)
        )
    ),
    (nonvar(Type_name_ptr_opt), Type_name_ptr_opt = array(Element_type, Size_expr) ->    %array variable creation required
        (symbolically_interpret(Size_expr, symb(_, Size)),
         symbolically_interpret(Expression, symb(_, Initialisation)),   %todo should be casted to Element_type, should be done within ptc_solver_array
         symbolically_interpret(Default, symb(_, Default_value)),
         ptc_solver__create_c_array(Element_type, Size, Default_value, Initialisation, Casted)
        )
    ;
     se_struct_atts__is_struct_atts(Type_name_ptr_opt) ->
        (se_struct_atts__get(Type_name_ptr_opt, 'field_values', Field_valuesL),
         (nonvar(Declarator), Declarator = initialised(_, Expression) ->
            (symbolically_interpret(Expression, symb(_, Initialisation)),
             (nonvar(Initialisation), Initialisation = initializer(Initialisation_exp) ->
                ptc_solver__initialise_record(Field_valuesL, Initialisation_exp, Casted)
             ;
                common_util__error(9, "Unexpected item in the packing area", "Should not happen", [('Initialisation', Initialisation)], '9_031224_4', 'se_handle_all_declarations', 'extract_pointers', no_localisation, no_extra_info)
             )
            )
         ;
            ptc_solver__create_record(Field_valuesL, Casted)    %we assume default initialialisations are made explicit are parsing time 
         )
        )
    ;    
        symbolically_interpret(cast(Type_name_ptr_opt, Expression), symb(_Type, Casted))
    ),
    seav__create_var(Type_name_ptr_opt, 'not_needed', Casted, Clean_var),
    declare_declarators(R, Type_name).
    %%%
    get_pointer_type_default(Pointer_expression, Default, addr(Inner_default)) :-
        nonvar(Pointer_expression),
        Pointer_expression = pointer(Type_expression),
        !,
        get_pointer_type_default(Type_expression, Default, Inner_default).
    get_pointer_type_default(_, Default, Default).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
declare_typedefs([], _).
declare_typedefs([Typedef|R], Type_name) :-
    extract_pointers(Typedef, Type_name, Type_name_ptr_opt, Clean_typedef_var),
    se_typedef_atts__create(Type_name_ptr_opt, Clean_typedef_var),
    declare_typedefs(R, Type_name).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
create_field_valuesL([], []).
create_field_valuesL([struct_decl(Type_specifiers_L, Members_L)|Struct_declarations_Rest], Field_values_List) :-
    single_struct_decl(Type_specifiers_L, Members_L, Inner_field_values_List),
    create_field_valuesL(Struct_declarations_Rest, Field_values_Rest),
    append(Inner_field_values_List, Field_values_Rest, Field_values_List).
    %%%
    single_struct_decl(Type_specifiers_L, Members_L, Inner_field_values_List) :-
        extract_type(Type_specifiers_L, Member_type),   %will have to deal with pointers
        length(Members_L, Lenght),
        length(Values_L, Lenght),
        ptc_solver__variable(Values_L, Member_type),     %will have to deal with non-basic members e.g. arrays, other struct etc
        create_inner_field_values_List(Members_L, Values_L, Inner_field_values_List).
        %%%
        create_inner_field_values_List([], [], []).
        create_inner_field_values_List([Member|Members_Rest], [Value|Values_Rest], [(Member, Value)|Inner_field_values_Rest]) :-
            create_inner_field_values_List(Members_Rest, Values_Rest, Inner_field_values_Rest).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%e.g. extract_pointers(ptr_decl(pointer, X), int, pointer(int), X)
%e.g. extract_pointers(array_decl(A, Size), int, array(int, Size), A)
extract_pointers(Var, Type_name, Type_name_ptr_opt, Clean_var) :-
    (nonvar(Var) ->
        (Var = ptr_decl(Ptr_exp, Clean_var) ->
            extract_inner_pointers(Ptr_exp, Type_name, Type_name_ptr_opt)
        ;
         Var = array_decl(Array_var, Size) ->   %e.g. array_decl(A, 0) and array_decl(B, int(5))
            (var(Array_var) ->
                (Clean_var = Array_var,
                 Type_name_ptr_opt = array(Type_name, Size)
                )
            ;
                common_util__error(9, "array declaration not handled", "Sikraken needs expanding", [('Array_var', Array_var)], '9_181124', 'se_handle_all_declarations', 'extract_pointers', no_localisation, no_extra_info)
            )
        )
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
    seav__create_var(Type_name_ptr_opt, Input, Input, Clean_param), %todo only needed for target function
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
    seav__create_var(Type_name_ptr_opt, 'not_needed', Output, Clean_return).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%extract the basic type from the list of declaration_specifiers
%typedef occurs last in the list
extract_type([Typedef_var], Type) :-
    se_typedef_atts__is_typedef_atts(Typedef_var),
    !,
    se_typedef_atts__get(Typedef_var, 'type', Type).
extract_type(['unsigned'], int) :-  %unsigned on its own is allowed
    !.
extract_type(Declaration_specifiers_list, unsigned(Type)) :-
    memberchk('unsigned', Declaration_specifiers_list),
    !,
    append(Start, ['unsigned'|Rest], Declaration_specifiers_list),
    append(Start, Rest, Declaration_specifiers_list_rest),
    !,
    extract_type(Declaration_specifiers_list_rest, Type).
extract_type(['signed'|R], Type) :- %signed is the default so we ignore it
    !,
    extract_type(R, Type).
extract_type(['const'|R], Type) :-  %const has no semantic impact for symbolic execution: perhaps could be optimised to mean don't create a SEAV sice it will never be assigned (gain likely to be small)
    !,
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
extract_type(['long', 'long', 'int'], long_long) :-
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
extract_type([struct(Tag)], _Struct_type) :-    %empty struct_declaration_list : forward declaration or used as part of variable declaration
    !,
    common_util__error(9, "Struct Declarations are Not Handled", "Sikraken needs expanding", [('Tag', Tag)], '9_031224', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
extract_type([struct(Tag, Struct_decl_list)], _Struct_type) :-
    !,
    (Tag == 'anonymous' ->
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