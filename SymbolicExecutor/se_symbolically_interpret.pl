symbolically_interpret(Expression, symb(Type, Symbolic_expression)) :-  %need to be at the top so tha tit does not unify with the other predicates below
    var(Expression),
    seav__is_seav(Expression), 
    !,
    seav__get(Expression, 'type', Type),
    seav__get(Expression, 'output', Symbolic_expression).
symbolically_interpret(int(Expression), symb(int, Expression)) :-   %constant with no suffix
    !.
symbolically_interpret(unsigned(Expression), symb(unsigned(int), Expression)) :- %u constant, identified in parser
    !.
symbolically_interpret(unsigned_long(Expression), symb(unsigned(long), Expression)) :- %ul constant, identified in parser
    !.
symbolically_interpret(unsigned_long_long(Expression), symb(unsigned(long_long), Expression)) :- %ull constant, identified in parser
    !.
symbolically_interpret(long(Expression), symb(long, Expression)) :- %l constant, identified in parser
    !.
symbolically_interpret(long_long(Expression), symb(long_long, Expression)) :- %ll constant, identified in parser
    !.
symbolically_interpret(double(Expression), symb(double, Expression)) :-   %double is the default type for floating point constants, identified in parser
    !.
symbolically_interpret(float(Expression), symb(float, Expression)) :-     %f constant, identified in parser
    !.
symbolically_interpret(long_double(Expression), symb(long_double, Expression)) :-     %l constant, identified in parser
    !.
symbolically_interpret(function_call(Function, Arguments), Symbolic_expression) :-
    !,
    (se_sub_atts__is_sub_atts(Function) ->
        (se_sub_atts__get(Function, 'body', Body),
         (Body == 'no_body_is_extern' -> %calling an extern function with no body
            (se_name_atts__get(Function, 'name', Function_name),
                (is_verifier_input_function(Function_name, Type) ->
                    (%mytrace,
                     ptc_solver__variable([Input_var], Type),
                     se_globals__get_ref('verifier_inputs', Verifier_inputs),
                     append(Verifier_inputs, [verif(Type, Input_var)], New_verifier_inputs),
                     se_globals__set_ref('verifier_inputs', New_verifier_inputs),
                     Symbolic_expression = symb(Type, Input_var)
                    )
                ;
                (Function_name == 'Exit' ; Function_name == 'Abort') ->
                    (%Arguments = [Exit_code],
                     %common_util__error(0, "Exit Called:", 'no_error_consequences', [('Exit_code', Exit_code)], '0_170824_1', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info),
                     %mytrace,
                     Symbolic_expression = symb(void, Function_name),  %unused, just for symmetry
                     end_of_path_predicate(_, _),   %only works in 'testcomp'    we bypass everything and go straight
                     %problem when labeling fails... when should not retry
                     fail
                    )
                ;
                 Function_name == 'UC___assert_fail' -> %has 4 parameters which we ignore: simply generating a test and backtracking as for 'Exit' and 'Abort'
                    (mytrace,
                     Symbolic_expression = symb(void, Function_name),  %unused, just for symmetry
                     end_of_path_predicate(_, _),   %only works in 'testcomp'    we bypass everything and go straight
                     fail
                    )
                ;
                    common_util__error(10, "Function call to unknown external function", "Cannot perform symbolic interpretation", [('Function_name', Function_name)], '10_150824_3', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info)
                )
            )
         ;
            (se_sub_atts__get(Function, 'parameters', Parameters),
             se_sub_atts__get(Function, 'return_type', Return_type),
             se_globals__push_scope_stack,          %function parameters scope
             match_parameters_arguments(Parameters, Arguments),
             symbolic_execute(Body, Flow),
             (Flow = return(Return_expression) ->
                symbolically_interpret(cast(Return_type, Return_expression), Symbolic_expression)
             ;
                Symbolic_expression = symb('void', 'void')   %e.g. via a fall through or a simple return statement with no expression
             ),
             se_globals__pop_scope_stack            %function parameters scope
            )
         )
        )
    ;
        (se_name_atts__get(Function, 'name', Function_name),
         common_util__error(10, "Calling a function that does not exist", "Seriously wrong; Suggest add include or declare as extern", [('Function_name', Function_name)], '10_100924_1', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info)
        )
    ).
symbolically_interpret(cast(Raw_typeL, Expression), symb(To_type, Casted)) :-
    !,
    
    (is_list(Raw_typeL) ->
        (%mytrace, 
         extract_type(Raw_typeL, To_type)    %from the parsed file, needs to be sanitised
        )
    ;
        To_type = Raw_typeL     %an internal call, already transformed
    ),
    symbolically_interpret(Expression, symb(From_type, Symbolic)),
    ptc_solver__perform_cast(cast(To_type, From_type), Symbolic, Casted).
symbolically_interpret(addr(Expression), symb(pointer, addr(Expression))) :-
    !.
symbolically_interpret(deref(Expression), Symbolic_expression) :-
    !,
    symbolically_interpret(Expression, Symbolic_expression_ptr),
    (Symbolic_expression_ptr = symb(pointer, addr(Inner_symbolic_expression)) ->   %todo: need testing with many levels of derefs
        symbolically_interpret(Inner_symbolic_expression, Symbolic_expression)
    ;
        common_util__error(10, "Dereferencing something which is not a pointer", "Cannot perform symbolic interpretation", [('Symbolic_expression_ptr', Symbolic_expression_ptr)], '10_040924_2', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info)
    ).
symbolically_interpret(multiply_op(Le_exp, Ri_exp), symb(Common_type, Le_casted_exp * Ri_casted_exp)) :-
    !,
    %mytrace,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, Common_type, Le_casted_exp, Ri_casted_exp).
symbolically_interpret(div_op(Le_exp, Ri_exp), symb(Common_type, Le_casted_exp / Ri_casted_exp)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, Common_type, Le_casted_exp, Ri_casted_exp).
symbolically_interpret(mod_op(Le_exp, Ri_exp), symb(Common_type, mod_op(Le_casted_exp, Ri_casted_exp))) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, Common_type, Le_casted_exp, Ri_casted_exp).
symbolically_interpret(plus_op(Le_exp, Ri_exp), symb(Common_type, Le_casted_exp + Ri_casted_exp)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, Common_type, Le_casted_exp, Ri_casted_exp).
symbolically_interpret(minus_op(Le_exp, Ri_exp), symb(Common_type, Le_casted_exp - Ri_casted_exp)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, Common_type, Le_casted_exp, Ri_casted_exp).
symbolically_interpret(minus_op(Expression), symb(Promoted_type, Result)) :-
    !,
    %mytrace,
    symbolically_interpret(Expression, symb(Type, Symbolic_expression)),
    apply_integral_promotion(Type, Promoted_type),  %special case if Promoted_type is unsigned(int), unsigned(long) or unsigned(long_long)
    (Promoted_type = unsigned(Signed_type) ->
        ptc_solver__perform_cast(cast(Promoted_type, Signed_type), -Symbolic_expression, Result)
    ;
        ptc_solver__perform_cast(cast(Type, Promoted_type), -Symbolic_expression, Result)
    ).
%%%relational operators: todo a lot of code is repeated: refactor
symbolically_interpret(less_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    ptc_solver__relation(<, Le_casted_exp, Ri_casted_exp, R).
symbolically_interpret(greater_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    ptc_solver__relation(>, Le_casted_exp, Ri_casted_exp, R).
symbolically_interpret(less_or_eq_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    ptc_solver__relation(=<, Le_casted_exp, Ri_casted_exp, R).
symbolically_interpret(greater_or_eq_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    ptc_solver__relation(>=, Le_casted_exp, Ri_casted_exp, R).
symbolically_interpret(equal_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    ptc_solver__relation(=, Le_casted_exp, Ri_casted_exp, R).
symbolically_interpret(not_equal_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    ptc_solver__relation(\=, Le_casted_exp, Ri_casted_exp, R).
%%%
symbolically_interpret(postfix_inc_op(Expression), Symbolic_expression) :-
    !,
    symbolically_interpret(Expression, Symbolic_expression),
    symbolic_execute(assign(Expression, plus_op(Expression, int(1))), _).       %todo Expression should only be symbolic executed once
symbolically_interpret(postfix_dec_op(Expression), Symbolic_expression) :-
    !,
    symbolically_interpret(Expression, Symbolic_expression),
    symbolic_execute(assign(Expression, minus_op(Expression, int(1))), _).      %todo Expression should only be symbolic executed once
%%%
%L and R: C semantics of && is always short circuit
%either L is true and overall truth is R's
%or L is false and overall truth is false
symbolically_interpret(and_op(Le_exp, Ri_exp), symb(int, R)) :-   
    !,
    %mytrace,
    symbolically_interpret(Le_exp, symb(_, Le_symbolic)), %only performed once as it should
    (Le_symbolic == 1 ->        %to avoid creating unnecessary choice point 
        symbolically_interpret(Ri_exp, symb(_, R))
    ;
     Le_symbolic == 0 ->        %to avoid creating unnecessary choice point 
        R #= 0
    ;    
        (
            (ptc_solver__sdl(Le_symbolic),
             symbolically_interpret(Ri_exp, symb(_, R))
            )
        ;%deliberate choice point
            (ptc_solver__sdl(not(Le_symbolic)),
             R #= 0
            )
        )
    ).
%%%
%L or R: C semantics of || is always short circuit
%either L is true and overall truth is true
%or L is false and overall truth is R's
symbolically_interpret(or_op(Le_exp, Ri_exp), symb(int, R)) :-   
    !,
    %mytrace,
    symbolically_interpret(Le_exp, symb(_, Le_symbolic)), %only performed once as it should
    (Le_symbolic == 1 ->    %to avoid creating unnecessary choice point 
        R #= 1
    ;
     Le_symbolic == 0 ->    %to avoid creating unnecessary choice point 
        symbolically_interpret(Ri_exp, symb(_, R))
    ;
        (
            (ptc_solver__sdl(Le_symbolic),
             R #= 1
            )
        ;%deliberate choice point
            (ptc_solver__sdl(not(Le_symbolic)),
             symbolically_interpret(Ri_exp, symb(_, R))
            )
        )
    ).
%%%
%
symbolically_interpret(not_op(Le_exp), symb(int, R)) :-
    !,
    %mytrace,
    (var(Le_exp) ->
        (symbolically_interpret(Le_exp, symb(_, Le_symbolic)),
         R #= neg(Le_symbolic)
        )
    ;
     Le_exp = and_op(Le, Ri) ->
        symbolically_interpret(or_op(not_op(Le), not_op(Ri)), symb(_, R))
    ;
     Le_exp = or_op(Le, Ri) ->
        symbolically_interpret(and_op(not_op(Le), not_op(Ri)), symb(_, R))
    ;
     Le_exp = not_op(Le) ->  %double negation
        symbolically_interpret(Le, symb(_, R))
    ;
        (symbolically_interpret(Le_exp, symb(_, Le_symbolic)),
         R #= neg(Le_symbolic)
        )
    ).
%handling of conditional expression construct in C "(cond) ? true_exp : false_exp"
symbolically_interpret(cond_exp(branch(Id, Condition), True_exp, False_exp), symb(Common_type, Symbolic)) :-
    !,
    %mytrace,
    %resulting Common_type is not sound: according to C standard type of the overall conditional expression is the common type of the True and False expressions, 
    %but because we do not extract types statitically extracting both types would mean symbolically executing both expressions which due to side effects, would be even more unsound
    %todo revisit when type extraction can be performed statically: e.g. in parser or during CFG building   
    symbolically_interpret(Condition, symb(_, Cond_Symbolic)),
    (
        (ptc_solver__sdl(Cond_Symbolic),
         se_globals__update_ref('current_path_bran', branch(Id, 'true')),
         symbolically_interpret(True_exp, symb(Common_type, Symbolic))
        )
    ;
        (ptc_solver__sdl(not(Cond_Symbolic)),
         se_globals__update_ref('current_path_bran', branch(Id, 'false')),
         symbolically_interpret(False_exp, symb(Common_type, Symbolic))
        )
    ).
symbolically_interpret(Unhandled_expression, _Symbolic_expression) :-
    common_util__error(10, "Expression is not handled", "Cannot perform symbolic interpretation", [('Unhandled_expression', Unhandled_expression)], '10_020824', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
implicit_type_casting(Same_type, Same_type, Le_symbolic, Ri_symbolic, Same_type, Le_symbolic, Ri_symbolic) :-   %Types are equal: no casting needed
    !.
implicit_type_casting(Le_type, Ri_type, Le_symbolic, Ri_symbolic, Common_type, Le_casted_exp, Ri_casted_exp) :-
    %mytrace,
    (float_conversion(Le_type, Ri_type, Le_symbolic, Ri_symbolic, Common_type, Le_casted_exp, Ri_casted_exp) ->
        true
    ;
        (apply_integral_promotion(Le_type, Le_type_c),
         apply_integral_promotion(Ri_type, Ri_type_c),
         (Le_type_c == Ri_type_c ->     %both integral types are equal after promotion: no casting needed
            (Common_type = Le_type_c,
             Le_casted_exp = Le_symbolic,
             Ri_casted_exp = Ri_symbolic
            )
         ;
            integer_conversion(Le_type_c, Ri_type_c, Le_symbolic, Ri_symbolic, Common_type, Le_casted_exp, Ri_casted_exp)
         )
        )
    ).
    %%%
    %may need indexing, but order is important so be careful
    integer_conversion(unsigned(long_long), From_type, Le_symbolic, Ri_symbolic, unsigned(long_long), Le_symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(long_long), From_type), Ri_symbolic, Ri_casted_exp).
    integer_conversion(From_type, unsigned(long_long), Le_symbolic, Ri_symbolic, unsigned(long_long), Le_casted_exp, Ri_symbolic) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(long_long), From_type), Le_symbolic, Le_casted_exp).
    integer_conversion(long_long, From_type, Le_symbolic, Ri_symbolic, long_long, Le_symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(long_long, From_type), Ri_symbolic, Ri_casted_exp).
    integer_conversion(From_type, long_long, Le_symbolic, Ri_symbolic, long_long, Le_casted_exp, Ri_symbolic) :-
        !,
        ptc_solver__perform_cast(cast(long_long, From_type), Le_symbolic, Le_casted_exp).
    integer_conversion(unsigned(long), From_type, Le_symbolic, Ri_symbolic, unsigned(long), Le_symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(long), From_type), Ri_symbolic, Ri_casted_exp).
    integer_conversion(From_type, unsigned(long), Le_symbolic, Ri_symbolic, unsigned(long), Le_casted_exp, Ri_symbolic) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(long), From_type), Le_symbolic, Le_casted_exp).
    integer_conversion(long, From_type, Le_symbolic, Ri_symbolic, long, Le_symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(long, From_type), Ri_symbolic, Ri_casted_exp).
    integer_conversion(From_type, long, Le_symbolic, Ri_symbolic, long, Le_casted_exp, Ri_symbolic) :-
        !,
        ptc_solver__perform_cast(cast(long, From_type), Le_symbolic, Le_casted_exp).
    integer_conversion(unsigned(int), From_type, Le_symbolic, Ri_symbolic, unsigned(int), Le_symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(int), From_type), Ri_symbolic, Ri_casted_exp).
    integer_conversion(From_type, unsigned(int), Le_symbolic, Ri_symbolic, unsigned(int), Le_casted_exp, Ri_symbolic) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(int), From_type), Le_symbolic, Le_casted_exp).
    integer_conversion(Le_type, Ri_type, _, _, _, _, _) :-
        !,
        common_util__error(10, "Should not happen", "Cannot perform symbolic interpretation", [('Le_type', Le_type), ('Ri_type', Ri_type)], '10_040924_3', 'se_symbolically_interpret', 'integer_conversion', no_localisation, no_extra_info).
    %%%
    %may need indexing, but order is important so be careful
    float_conversion(long_double, From_type, Le_symbolic, Ri_symbolic, long_double, Le_symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(long_double, From_type), Ri_symbolic, Ri_casted_exp).
    float_conversion(From_type, long_double, Le_symbolic, Ri_symbolic, long_double, Le_casted_exp, Ri_symbolic) :-
        !,
        ptc_solver__perform_cast(cast(long_double, From_type), Le_symbolic, Le_casted_exp).
    float_conversion(double, From_type, Le_symbolic, Ri_symbolic, double, Le_symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(double, From_type), Ri_symbolic, Ri_casted_exp).
    float_conversion(From_type, double, Le_symbolic, Ri_symbolic, double, Le_casted_exp, Ri_symbolic) :-
        !,
        ptc_solver__perform_cast(cast(double, From_type), Le_symbolic, Le_casted_exp).
    float_conversion(float, From_type, Le_symbolic, Ri_symbolic, float, Le_symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(float, From_type), Ri_symbolic, Ri_casted_exp).
    float_conversion(From_type, float, Le_symbolic, Ri_symbolic, float, Le_casted_exp, Ri_symbolic) :-
        !,
        ptc_solver__perform_cast(cast(float, From_type), Le_symbolic, Le_casted_exp).
    float_conversion(_, _, _, _, _, _, _) :-
        fail.
%%%
    apply_integral_promotion(char, int) :-
        !.
    apply_integral_promotion(unsigned(char), int) :-
        !.
    apply_integral_promotion(short, int) :-
        !.
    apply_integral_promotion(unsigned(short), int) :-
        !.
    apply_integral_promotion(enum, int) :-
        !.
    apply_integral_promotion(Other_types_are_unchanged, Other_types_are_unchanged) :-   %in particular unsigned(int) remain unsigned(int)
        !.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
is_verifier_input_function('UC___VERIFIER_nondet_bool', bool).
is_verifier_input_function('UC___VERIFIER_nondet_char', char).
is_verifier_input_function('UC___VERIFIER_nondet_int', int).
is_verifier_input_function('UC___VERIFIER_nondet_int128', int128) :-  %128 bit integer, gcc extension
    common_util__error(10, "Unhandled function name in is_verifier_input_function", "Cannot perform symbolic interpretation", [('Function name', 'UC___VERIFIER_nondet_int128')], '10_040924', 'se_symbolically_interpret', 'is_verifier_input_function', no_localisation, no_extra_info).
is_verifier_input_function('UC___VERIFIER_nondet_float', float).
is_verifier_input_function('UC___VERIFIER_nondet_double', double).
is_verifier_input_function('UC___VERIFIER_nondet_loff_t', loff_t) :-  %large offset for file manipulation
    common_util__error(10, "Unhandled function name in is_verifier_input_function", "Cannot perform symbolic interpretation", [('Function name', 'UC___VERIFIER_nondet_loff_t')], '10_040924', 'se_symbolically_interpret', 'is_verifier_input_function', no_localisation, no_extra_info).
is_verifier_input_function('UC___VERIFIER_nondet_long', long).
is_verifier_input_function('UC___VERIFIER_nondet_longlong', long_long).
is_verifier_input_function('UC___VERIFIER_nondet_pchar', pointer(char)) :-
    common_util__error(10, "Unhandled function name in is_verifier_input_function", "Cannot perform symbolic interpretation", [('Function name', 'UC___VERIFIER_nondet_pchar')], '10_040924', 'se_symbolically_interpret', 'is_verifier_input_function', no_localisation, no_extra_info).
is_verifier_input_function('UC___VERIFIER_nondet_pthread_t', pointer(thread_t)) :-
    common_util__error(10, "Unhandled function name in is_verifier_input_function", "Cannot perform symbolic interpretation", [('Function name', 'UC___VERIFIER_nondet_pthread_t')], '10_040924', 'se_symbolically_interpret', 'is_verifier_input_function', no_localisation, no_extra_info).
is_verifier_input_function('UC___VERIFIER_nondet_sector_t', sector_t) :-
    common_util__error(10, "Unhandled function name in is_verifier_input_function", "Cannot perform symbolic interpretation", [('Function name', 'UC___VERIFIER_nondet_sector_t')], '10_040924', 'se_symbolically_interpret', 'is_verifier_input_function', no_localisation, no_extra_info).
is_verifier_input_function('UC___VERIFIER_nondet_short', short).
is_verifier_input_function('UC___VERIFIER_nondet_size_t', size_t) :-
    common_util__error(10, "Unhandled function name in is_verifier_input_function", "Cannot perform symbolic interpretation", [('Function name', 'UC___VERIFIER_nondet_size_t')], '10_040924', 'se_symbolically_interpret', 'is_verifier_input_function', no_localisation, no_extra_info).
is_verifier_input_function('UC___VERIFIER_nondet_u32', u32) :-
    common_util__error(10, "Unhandled function name in is_verifier_input_function", "Cannot perform symbolic interpretation", [('Function name', 'UC___VERIFIER_nondet_u32')], '10_040924', 'se_symbolically_interpret', 'is_verifier_input_function', no_localisation, no_extra_info).
is_verifier_input_function('UC___VERIFIER_nondet_uchar', unsigned(char)).
is_verifier_input_function('UC___VERIFIER_nondet_uint', unsigned(int)).
is_verifier_input_function('UC___VERIFIER_nondet_uint128', uint128) :-  %128 bit unsigned integer, gcc extension
    common_util__error(10, "Unhandled function name in is_verifier_input_function", "Cannot perform symbolic interpretation", [('Function name', 'UC___VERIFIER_nondet_uint128')], '10_040924', 'se_symbolically_interpret', 'is_verifier_input_function', no_localisation, no_extra_info).
is_verifier_input_function('UC___VERIFIER_nondet_ulong', unsigned(long)).
is_verifier_input_function('UC___VERIFIER_nondet_ulonglong', unsigned(long_long)).
is_verifier_input_function('UC___VERIFIER_nondet_unsigned', unsigned(int)).
is_verifier_input_function('UC___VERIFIER_nondet_ushort', unsigned(short)).
is_verifier_input_function('UC___VERIFIER_nondet_pointer', pointer) :-  %pointer to void
    common_util__error(10, "Unhandled function name in is_verifier_input_function", "Cannot perform symbolic interpretation", [('Function name', 'UC___VERIFIER_nondet_pointer')], '10_040924', 'se_symbolically_interpret', 'is_verifier_input_function', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%