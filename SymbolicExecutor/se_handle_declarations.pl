%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
declare_declarators([], _).
declare_declarators([Declarator|R], Type_name) :-
    declare_single_declarator(Declarator, Type_name, Type_name_ptr_opt, Value, Clean_var),
    seav__create_var(Type_name_ptr_opt, 'not_needed', Value, Clean_var),
    declare_declarators(R, Type_name).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
declare_single_declarator(Declarator, Type_name, Type_name_ptr_opt, Casted, Clean_var) :-
    %mytrace,
    getval('execution_mode', Execution_mode),
    (nonvar(Declarator), Declarator = initialised(Direct_declarator, Initialiser) ->
        true
    ;
        (Direct_declarator = Declarator,
         (Execution_mode == 'local' ->
            Initialiser = 'uninitialised'
         ;
            Initialiser = int(0)   %will initialise everything to 0 by default
         )
        )
    ),
    %C pointers variables are not ptc_solver variable: they are handled syntactically e.g. seav(pointer(integer), not_needed, addr(Y_2{se_seav_atts : seav(integer, not_needed, 42)}))
    extract_pointers(Direct_declarator, Type_name, Type_name_ptr_opt, Clean_var), %e.g. extract_pointers(ptr_decl(pointer, Pi_3{c_id(pi)}), integer, pointer(integer), Pi_3)

    (nonvar(Type_name_ptr_opt), Type_name_ptr_opt = array(Element_type, Size_expr) ->    %array variable creation required
        (symbolically_interpret(Size_expr, symb(_, Size)),
         (Initialiser == 'uninitialised' ->
            symbolically_interpret(int(0), symb(_, Initialisation)) %sticky plaster: this entire predicate needs rewritten
         ;       
            symbolically_interpret(Initialiser, symb(_, Initialisation))   %todo should be casted to Element_type, should be done within ptc_solver_array
         ),
         ptc_solver__create_variable(array(Element_type, Size, Initialisation), Casted)
        )
    ;
     ptc_solver__is_struct_type(Type_name_ptr_opt) ->
        (symbolically_interpret(Initialiser, symb(_, Initialisation)),
         ptc_solver__create_variable(struct(Type_name_ptr_opt, Initialisation), Casted)
        )
    ;    
        %atomic object
        %don't perform symbolic execution of Initialiser here because it is be done within the cast
        (Type_name_ptr_opt = pointer(_), nonvar(Declarator), Declarator \= initialised(Direct_declarator, Initialiser) ->
            Casted = addr(Initialiser)  %save yourself the trouble: don't go through casting
        ;
         Initialiser == 'uninitialised' ->
            Casted = _Initialiser
        ;
            symbolically_interpret(cast(Type_name_ptr_opt, Initialiser), symb(_Type, Casted))
        )
    ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

declare_typedefs([], _).
declare_typedefs([Typedef|R], Type_name) :-
    extract_pointers(Typedef, Type_name, Type_name_ptr_opt, Clean_typedef_var),
    se_typedef_atts__create(Type_name_ptr_opt, Clean_typedef_var),
    declare_typedefs(R, Type_name).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%should be done in the solver
create_struct_type(struct(Tag, Struct_declaration_list), Struct_type) :-
    (Tag == 'anonymous' ->
        Struct_type = _     % any free var will do
    ;
        Struct_type = Tag
    ),
    (%mytrace,
     create_field_valuesL(Struct_declaration_list, Field_valuesL),
     ptc_solver__create_struct_type(Struct_type, Field_valuesL)
    ).
    %%%
    create_field_valuesL([], []).
    create_field_valuesL([anonymous_member(Struct_or_Union)|Rest_i], Field_values_List) :-    %Anonymous Members in Structs have different access rules
        !,
        single_struct_decl([Struct_or_Union], [_Anonymous_member], Anonymous_struct_or_union_member),
        create_field_valuesL(Rest_i, Rest_o),
        append(Anonymous_struct_or_union_member, Rest_o, Field_values_List).
    create_field_valuesL([struct_decl(Type_specifiers_L, Declarators_List)|Struct_declarations_Rest], Field_values_List) :-
        !,
        single_struct_decl(Type_specifiers_L, Declarators_List, Inner_field_values_List),
        create_field_valuesL(Struct_declarations_Rest, Field_values_Rest),
        append(Inner_field_values_List, Field_values_Rest, Field_values_List).
        %%%
        single_struct_decl(Type_specifiers_L, Declarators_List, Inner_field_values_List) :-
            extract_type(Type_specifiers_L, Member_type),   %will have to deal with pointers and non-atomic
            member_list(Declarators_List, Member_type, Inner_field_values_List).
            %%%
            member_list([], _Member_type, []).
            member_list([Member|Declarators_List_Rest], Member_type, [(Member, Member_type)|Inner_field_values_Rest]) :-
                %for Declarator extract the member name and create a Value
                %a Declarator can be x, *x, x[10]
                member_list(Declarators_List_Rest, Member_type, Inner_field_values_Rest).
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
        ;
         atomic(Var) -> %a struct member
           (Type_name_ptr_opt = Type_name,
            Clean_var = Var
           )
        )
    ;
        (Type_name_ptr_opt = Type_name,
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
    ptc_solver__create_variable(Type_name, Input_var),
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
    ptc_solver__create_variable(Type_name, Output_var),
    (Type_name_ptr_opt = pointer(_) ->
         Output = addr(Output_var)           %C pointers variables are not ptc_solver variable: they are handled syntactically e.g. seav(pointer(integer), not_needed, addr(Y_2{se_seav_atts : seav(integer, not_needed, 42)}))
    ;
         Output = Output_var
    ),
    seav__create_var(Type_name_ptr_opt, 'not_needed', Output, Clean_return).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%extract_type handles the declaration_specifiers output from the C function create_declaration_specifiers() in the parser grammar
%it return atomic types (e.g. int, unsigned(long_long)) and create non-atomic types (struct, union, enum)
%the syntax of the input arg is spec([typedef, extern], Type_spec)
extract_type(spec(_Qualifier_list, Type_spec), Type) :-
    !,
    extract_type2(Type_spec, Type).
    
    extract_type2(Typedefname_var, Type) :-
        var(Typedefname_var),
        !,
        (se_typedef_atts__is_typedef_atts(Typedefname_var) ->
            se_typedef_atts__get(Typedefname_var, 'type', Type)
        ;
            common_util__error(9, "Expected a Typedefname_var", "Sikraken needs expanding", [('Typedefname_var', Typedefname_var)], '9_181124', 'se_handle_all_declarations', 'extract_type2', no_localisation, no_extra_info)
        ).
    extract_type2(struct(Tag, Struct_decl_list), Struct_type) :- %e.g. handling a typedef of a struct (the Tag can be anonymous): struct type is created
        !,
        create_struct_type(struct(Tag, Struct_decl_list), Struct_type).
    extract_type2(struct(Tag), Tag) :-
        (ptc_solver__is_struct_type(Tag) -> %a previously defined struct type (document when this occurs
            true
        ;
            create_struct_type(struct(Tag, []), _Struct_type)   %e.g. a typedef for a forward struct declaration... as in "typedef struct plot plot;"   //typedef of a forward declaration
        ),
        !.
    extract_type2(union(Tag, Union_decl_list), void) :-
        !,
        common_util__error(9, "Union types are not handled", "Sikraken needs expanding", [('Union', union(Tag, Union_decl_list))], '9_071224', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
    extract_type2(union(Tag), void) :-
        !,
        common_util__error(9, "Union forward types are not handled", "Sikraken needs expanding", [('Union', union(Tag))], '9_071224_1', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
    extract_type2(enum(Tag, Enum_decl_list), void) :-
        !,
        common_util__error(9, "Enum types are not handled", "Sikraken needs expanding", [('Enum', enum(Tag, Enum_decl_list))], '9_150525', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
    extract_type2(enum(Tag), void) :-
        !,
        common_util__error(9, "Enum forward types are not handled", "Sikraken needs expanding", [('Enum', enum(Tag))], '9_150525_1', 'se_handle_all_declarations', 'extract_type', no_localisation, no_extra_info).
    extract_type2(unsigned(Atomic_type), Atomic_type) :-  %e.g. unsigned(int), unsigned(char), unsigned(short), unsigned(long), unsigned(long_long)
        !,
        atomic(Atomic_type).
    extract_type2(Atomic_type, Atomic_type) :-  %e.g. int128, bool, int, float, double, long_double, char, short, long, long_long
        atomic(Atomic_type),
        !.
    extract_type2(Other, void) :- 
        !,
        common_util__error(9, "Unknown type", "Sikraken needs expanding", [('Other', Other)], '9_150525_3', 'se_handle_all_declarations', 'extract_type2', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
match_parameters_arguments([], []) :-
    !.
match_parameters_arguments([param(Declaration_specifiers, Parameter)|Rest_parameters], [Argument|Rest_arguments]) :-
    !,
    extract_type(Declaration_specifiers, Type_name),
    declare_declarators([initialised(Parameter, Argument)], Type_name), %make a copy?
    match_parameters_arguments(Rest_parameters, Rest_arguments).
match_parameters_arguments([unnamed_param(_Declaration_specifiers, [])|Rest_parameters], [_Argument|Rest_arguments]) :-
    !,
    match_parameters_arguments(Rest_parameters, Rest_arguments).
match_parameters_arguments(Parameters, Arguments) :-
    !,
    common_util__error(10, "mismatch of parameters and arguments", "Cannot call function", [('Parameters', Parameters), ('Arguments', Arguments)], '10160824_1', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%