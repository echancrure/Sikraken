%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% SEAV
% Defines the module seav for Symbolic Execution Attributed Variables
% The attribute is of the form: se_seav_atts(Type_name, Input_value, Output_value)    
%   Type_name    : just the type_name of the variable
%   Input_value  : the input value of the variable: free for uninitialised variables, immutable during symbolic execution
%   Output_value : the current value of the variable: initially Input_value, mutated via assignments
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- module('se_seav_atts').
:- export seav__create_var/2, seav__is_seav/1, seav__get/3, seav__update/3.

:- meta_attribute('se_seav_atts', [unify:unify_seav/2, print:print_seav/2]).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%internal attributed variable handlers
%called to confirm unification after unification with an another attributed variable or a non-variable
%Value is a non-variable or another attributed variable
unify_seav(_, Attr) :-          %ECLiPSe fails on compilation if this is not present even though the documentation says that the handler is not called in this case 
    var(Attr).                  %Ignore if no attribute for this extension
unify_seav(Term, _Attr) :-
    meta(Term),                 %fails otherwise: e.g. when unified with an atom
    fail.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
print_seav(_{se_seav_atts(Type_name, Input, Output)}, Print) :-
	-?->
	Print = seav(Type_name, Input, Output).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
seav__create_var(Type_name, SEAV):-
    add_attribute(SEAV, se_seav_atts(Type_name, _, _)).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
seav__is_seav(_{Attr}) :-
    -?->
    compound(Attr),
    Attr = se_seav_atts(_, _, _).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
seav__get(_{Attr}, 'type', Type_name) :-        
    -?->
   Attr = se_seav_atts(Type_name, _, _).
seav__get(_{Attr}, 'input', Input) :-        
    -?->
   Attr = se_seav_atts(_, Input, _).
seav__get(_{Attr}, 'output', Output) :-        
    -?->
   Attr = se_seav_atts(_, _, Output).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
seav__update(_{Attr}, 'input', Input) :-        
    -?->
   setarg(2, Attr, Input).
seav__update(_{Attr}, 'output', Output) :-        
    -?->
   setarg(3, Attr, Output).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%