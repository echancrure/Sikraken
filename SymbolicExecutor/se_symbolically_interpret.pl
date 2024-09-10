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
    !,mytrace,
    (se_sub_atts__is_sub_atts(Function) ->
        (se_sub_atts__get(Function, 'body', Body),
         (Body == 'no_body_is_extern' -> %calling an extern function with no body
            (se_name_atts__get(Function, 'name', Function_name),
                (is_verifier_input_function(Function_name, Type) ->
                    (%mytrace,
                    ptc_solver__variable([Input_var], Type),
                    se_globals__get_ref('verifier_inputs', Verifier_inputs),
                    append(Verifier_inputs, [Input_var], New_verifier_inputs),
                    se_globals__set_ref('verifier_inputs', New_verifier_inputs),
                    Symbolic_expression = symb(Type, Input_var)
                    )
                ;
                (Function_name == 'Exit' ; Function_name == 'Abort') ->
                    (%Arguments = [Exit_code],
                    %common_util__error(0, "Exit Called:", 'no_error_consequences', [('Exit_code', Exit_code)], '0_170824_1', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info),
                    %mytrace,
                    Symbolic_expression = symb(Function_name, Function_name),  %unused, just for symmetry
                    end_of_path_predicate(_, _),   %only works in 'testcomp'
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
                Symbolic_expression = symb('void', 'void')   
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
symbolically_interpret(cast(Type, Return_expression), symb(Type, Symbolic_expression)) :-
    !,
    Symbolic_expression = Return_expression.    %for now
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
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, Common_type, Le_casted_exp, Ri_casted_exp).
symbolically_interpret(div_op(Le_exp, Ri_exp), symb(Common_type, Le_casted_exp / Ri_casted_exp)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, Common_type, Le_casted_exp, Ri_casted_exp).
symbolically_interpret(mod_op(Le_exp, Ri_exp), symb(Common_type, mod_op(Le_casted_exp, Ri_casted_exp))) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, Common_type, Le_casted_exp, Ri_casted_exp).
symbolically_interpret(plus_op(Le_exp, Ri_exp), symb(Common_type, Le_casted_exp + Ri_casted_exp)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, Common_type, Le_casted_exp, Ri_casted_exp).
symbolically_interpret(minus_op(Le_exp, Ri_exp), symb(Common_type, Le_casted_exp - Ri_casted_exp)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, Common_type, Le_casted_exp, Ri_casted_exp).
symbolically_interpret(minus_op(Expression), symb(Promoted_type, Result)) :-
    !,
    %mytrace,
    symbolically_interpret(Expression, symb(Type, Symbolic_expression)),
    apply_integral_promotion(Type, Promoted_type),  %special case if Promoted_type is unsigned(int), unsigned(long) or unsigned(long_long)
    ptc_solver__perform_cast(cast(Type, Promoted_type), -Symbolic_expression, Result).

%%%relational operators: todo a lot of code is repeated: refactor
%todo call IC directly rather than go through the the solver again...
symbolically_interpret(less_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    $<(Le_casted_exp, Ri_casted_exp, R).
symbolically_interpret(greater_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    $>(Le_casted_exp, Ri_casted_exp, R).
symbolically_interpret(less_or_eq_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    $=<(Le_casted_exp, Ri_casted_exp, R).
symbolically_interpret(greater_or_eq_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    $>=(Le_casted_exp, Ri_casted_exp, R).
symbolically_interpret(equal_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    $=(Le_casted_exp, Ri_casted_exp, R).
symbolically_interpret(not_equal_op(Le_exp, Ri_exp), symb(int, R)) :-
    !,
    symbolically_interpret(Le_exp, symb(Le_type, Le_Symbolic)),
    symbolically_interpret(Ri_exp, symb(Ri_type, Ri_Symbolic)),
    implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, _Common_type, Le_casted_exp, Ri_casted_exp),
    $\=(Le_casted_exp, Ri_casted_exp, R).
%%%
symbolically_interpret(postfix_inc_op(Expression), Symbolic_expression) :-
    !,
    symbolically_interpret(Expression, Symbolic_expression),
    symbolic_execute(assign(Expression, plus_op(Expression, 1)), _).    %additional side effect

symbolically_interpret(and_op(Le_exp, Ri_exp), symb(int, 1)) :-   %C semantics of && is always short circuit
    !,
    %mytrace,
    symbolically_interpret(Le_exp, symb(int, Le_Symbolic)),
    ptc_solver__sdl(Le_Symbolic),
    symbolically_interpret(Ri_exp, symb(int, Ri_Symbolic)),
    ptc_solver__sdl(Ri_Symbolic).
symbolically_interpret(or_op(Le_exp, Ri_exp), symb(int, 1)) :-   %C semantics of || is always short circuit
    !,
    %mytrace,
    random(2, R2),  %todo does this randomness still respects short-circuit evaluation of or operators? It seems to allow Ri true without imposing Le false... when R2  == 1
    (R2 == 0 ->
        (A = Le_exp,
         B = Ri_exp
        )
    ;
        (A = Ri_exp,
         B = Le_exp
       )
    ),
    (
        (symbolically_interpret(A, symb(int, Le_Symbolic)),
         ptc_solver__sdl(Le_Symbolic)
        )
    ;%deliberate choice point
        (%but only if will lead to new path todo
         symbolically_interpret(not_op(A), symb(int, Not_Le_Symbolic)),
         ptc_solver__sdl(Not_Le_Symbolic),
         symbolically_interpret(B, symb(int, Ri_Symbolic)),
         ptc_solver__sdl(Ri_Symbolic)
        )
    ).
 
symbolically_interpret(not_op(Le_exp), symb(int, Symbolic)) :-
    !,
    (var(Le_exp) ->         %for SEAVs (often as part of an evaluated reif)
        (symbolically_interpret(Le_exp, symb(int, Le_Symbolic)),
         Symbolic = not(Le_Symbolic)
        )
    ;
     Le_exp = and_op(L, R) ->
        symbolically_interpret(or_op(not_op(L), not_op(R)), symb(int, Symbolic))
    ;
     Le_exp = or_op(L, R) ->
        symbolically_interpret(and_op(not_op(L), not_op(R)), symb(int, Symbolic))
    ;
     Le_exp = not_op(L) ->  %double negation
        symbolically_interpret(L, symb(int, Symbolic))
    ;
        (symbolically_interpret(Le_exp, symb(int, Le_Symbolic)),
         Symbolic = not(Le_Symbolic)
        )
    ).
symbolically_interpret(Unhandled_expression, _Symbolic_expression) :-
    common_util__error(10, "Expression is not handled", "Cannot perform symbolic interpretation", [('Unhandled_expression', Unhandled_expression)], '10_020824', 'se_symbolically_interpret', 'symbolically_interpret', no_localisation, no_extra_info).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
implicit_type_casting(Same_type, Same_type, Le_Symbolic, Ri_Symbolic, Same_type, Le_Symbolic, Ri_Symbolic) :-   %Types are equal: no casting needed
    !.
implicit_type_casting(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, Common_type, Le_casted_exp, Ri_casted_exp) :-
    %mytrace,
    (float_conversion(Le_type, Ri_type, Le_Symbolic, Ri_Symbolic, Common_type, Le_casted_exp, Ri_casted_exp) ->
        true
    ;
        (apply_integral_promotion(Le_type, Le_type_c),
         apply_integral_promotion(Ri_type, Ri_type_c),
         (Le_type_c == Ri_type_c ->     %both integral types are equal after promotion: no casting needed
            (Common_type = Le_type_c,
             Le_casted_exp = Le_Symbolic,
             Ri_casted_exp = Ri_Symbolic
            )
         ;
            integer_conversion(Le_type_c, Ri_type_c, Le_Symbolic, Ri_Symbolic, Common_type, Le_casted_exp, Ri_casted_exp)
         )
        )
    ).
    %%%
    %may need indexing, but order is important so be careful
    integer_conversion(unsigned(long_long), From_type, Le_Symbolic, Ri_Symbolic, unsigned(long_long), Le_Symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(long_long), From_type), Ri_Symbolic, Ri_casted_exp).
    integer_conversion(From_type, unsigned(long_long), Le_Symbolic, Ri_Symbolic, unsigned(long_long), Le_casted_exp, Ri_Symbolic) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(long_long), From_type), Le_Symbolic, Le_casted_exp).
    integer_conversion(long_long, From_type, Le_Symbolic, Ri_Symbolic, long_long, Le_Symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(long_long, From_type), Ri_Symbolic, Ri_casted_exp).
    integer_conversion(From_type, long_long, Le_Symbolic, Ri_Symbolic, long_long, Le_casted_exp, Ri_Symbolic) :-
        !,
        ptc_solver__perform_cast(cast(long_long, From_type), Le_Symbolic, Le_casted_exp).
    integer_conversion(unsigned(long), From_type, Le_Symbolic, Ri_Symbolic, unsigned(long), Le_Symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(long), From_type), Ri_Symbolic, Ri_casted_exp).
    integer_conversion(From_type, unsigned(long), Le_Symbolic, Ri_Symbolic, unsigned(long), Le_casted_exp, Ri_Symbolic) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(long), From_type), Le_Symbolic, Le_casted_exp).
    integer_conversion(long, From_type, Le_Symbolic, Ri_Symbolic, long, Le_Symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(long, From_type), Ri_Symbolic, Ri_casted_exp).
    integer_conversion(From_type, long, Le_Symbolic, Ri_Symbolic, long, Le_casted_exp, Ri_Symbolic) :-
        !,
        ptc_solver__perform_cast(cast(long, From_type), Le_Symbolic, Le_casted_exp).
    integer_conversion(unsigned(int), From_type, Le_Symbolic, Ri_Symbolic, unsigned(int), Le_Symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(int), From_type), Ri_Symbolic, Ri_casted_exp).
    integer_conversion(From_type, unsigned(int), Le_Symbolic, Ri_Symbolic, unsigned(int), Le_casted_exp, Ri_Symbolic) :-
        !,
        ptc_solver__perform_cast(cast(unsigned(int), From_type), Le_Symbolic, Le_casted_exp).
    integer_conversion(Le_type, Ri_type, _, _, _, _, _) :-
        !,
        common_util__error(10, "Should not happen", "Cannot perform symbolic interpretation", [('Le_type', Le_type), ('Ri_type', Ri_type)], '10_040924_3', 'se_symbolically_interpret', 'integer_conversion', no_localisation, no_extra_info).
    %%%
    %may need indexing, but order is important so be careful
    float_conversion(long_double, From_type, Le_Symbolic, Ri_Symbolic, long_double, Le_Symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(long_double, From_type), Ri_Symbolic, Ri_casted_exp).
    float_conversion(From_type, long_double, Le_Symbolic, Ri_Symbolic, long_double, Le_casted_exp, Ri_Symbolic) :-
        !,
        ptc_solver__perform_cast(cast(long_double, From_type), Le_Symbolic, Le_casted_exp).
    float_conversion(double, From_type, Le_Symbolic, Ri_Symbolic, double, Le_Symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(double, From_type), Ri_Symbolic, Ri_casted_exp).
    float_conversion(From_type, double, Le_Symbolic, Ri_Symbolic, double, Le_casted_exp, Ri_Symbolic) :-
        !,
        ptc_solver__perform_cast(cast(double, From_type), Le_Symbolic, Le_casted_exp).
    float_conversion(float, From_type, Le_Symbolic, Ri_Symbolic, float, Le_Symbolic, Ri_casted_exp) :-
        !,
        ptc_solver__perform_cast(cast(float, From_type), Ri_Symbolic, Ri_casted_exp).
    float_conversion(From_type, float, Le_Symbolic, Ri_Symbolic, float, Le_casted_exp, Ri_Symbolic) :-
        !,
        ptc_solver__perform_cast(cast(float, From_type), Le_Symbolic, Le_casted_exp).
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