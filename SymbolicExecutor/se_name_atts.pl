%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% se_name_atts.pl
% defines the module for attributed named variables
% 1st argument is the C source name of all identifiers in the C source code as per the output in the prsed Prolog file
%  E.g. Date_3 has for name 'date:67' or whatever information can be extracted from the parser (line number, filename, column number)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- module('se_name_atts').

:- export se_name_atts__is_name_atts/1, se_name_atts__create/2, se_name_atts__get/3, se_name_atts__initL/3.

:- meta_attribute('se_name_atts', [unify:unify_name/2, print:print_name/2]).

:- use_module('common_util').
:- import common_util__error/9 from common_util.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%internal attributed variable handlers
%called to confirm unification after unification with an another attributed variable or a non-variable
%Value is a non-variable or another attributed variable
/*unify_name(_Unified, Attr) :-          %ECLiPSe fails on compilation if this is not present even though the documentation says that the handler is not called in this case 
    var(Attr).                      %i.e. ignore and succeed: unification does not involve the attribute for this extension
unify_name(Unified, Attr) :-
    compound(Attr),    
    printf("hello there 2 unified:%w attr:%w\n", [Unified, Attr]),             
    unify_term_name(Unified, Attr).
%%%
unify_term_name(Unified, Attr) :- 
    nonvar(Unified),
    printf("hello there 3: unified:%w attr:%w\n", [Unified, Attr]),
    fail.           
unify_term_name(U{Unified_attr}, Attr) :-
    -?->
    printf("hello there 4", []),
    unify_name_name(U, Unified_attr, Attr).
unify_name_name(U, Unified_attr, Attr) :-
    printf("hello there 5", []),
    var(Unified_attr),
    Attr = Unified_attr.*/
unify_name(_, Attr) :-
	var(Attr).                       %ANY+META (false call)
unify_name(Term, Attr) :-
	compound(Attr),
	unify_term_name(Term, Attr).

unify_term_name(_{AttrY}, AttrX) :-   %META + META
	-?->
	AttrX = AttrY.  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_name(_{se_name_atts(Name)}, Print) :-
	-?->
	Print = c_id(Name).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_name_atts__is_name_atts(_{se_name_atts(Name)}) :-
    -?->
    true.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_name_atts__create(Name, Name_atts) :-
    add_attribute(Name_atts, se_name_atts(Name)).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_name_atts__get(_{Attr}, 'name', Name) :-
    -?->
    Attr = se_name_atts(Name).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%create a list of name_atts variables from a list of a(Var, Name_string) generated during parsing in foo.pl
%  e.g. a(X_353, "bool.ads:4:3:x")
se_name_atts__initL([], Target_raw_subprogram_name, _) :-
    common_util__error(10, "Target function is not a valid id", "Cannot find the target function", [('Target_raw_subprogram_name', Target_raw_subprogram_name)], 102607243, 'se_name_atts', 'se_name_atts__initL', no_localisation, no_extra_info).

se_name_atts__initL([a(Var, Name_atom)|R], Target_raw_subprogram_name, Target_subprogram_var) :-
    se_name_atts__create(Name_atom, Var),
    (Target_raw_subprogram_name == Name_atom ->
        (Target_subprogram_var = Var,
         initL(R)    %just process the rest of the list without looking for the Target_raw_subprogram_name
        )
    ;
        se_name_atts__initL(R, Target_raw_subprogram_name, Target_subprogram_var)
    ).

initL([]).
initL([a(Var, Name_atom)|R]) :-
    se_name_atts__create(Name_atom, Var),
    initL(R).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%