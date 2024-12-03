%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% se_struct_atts.pl
% Defines the module for attributed struct type declarations: a very close copy of se_name_atts.pl
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- module('se_struct_atts').
%%%
:- export se_struct_atts__is_struct_atts/1, se_struct_atts__create/2, se_struct_atts__get/3.

:- meta_attribute('se_struct_atts', [unify:unify_struct/2, print:print_struct/2]).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%called to confirm unification after unification with an another attributed variable or a non-variable
%Value is a non-variable or another attributed variable
unify_struct(_, Struct_attr) :-			%ECLiPSe fails on compilation if this is not present even though the documentation says that the handler is not called in this case 
	var(Struct_attr).                    	%Ignore if no attribute for this extension
unify_struct(Term, Struct_attr) :-
	compound(Struct_attr), %todo: revisit and do the same as for SEAVs
	unify_term_struct(Term, Struct_attr).

unify_term_struct(_{AttrY}, Struct_attr) :-   %META + META
	-?->
	Struct_attr = AttrY.  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_struct(_{se_struct_atts(Field_valuesL)}, Print) :-
	-?->
	Print = struct_type(Field_valuesL).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_struct_atts__is_struct_atts(_{se_struct_atts(Field_valuesL)}) :-
    -?->
    true.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_struct_atts__create(Tag, Field_valuesL) :-
    add_attribute(Tag, se_struct_atts(Field_valuesL)).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
se_struct_atts__get(_{Attr}, 'field_values', Field_valuesL) :-
    -?->
    Attr = se_struct_atts(Field_valuesL).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%