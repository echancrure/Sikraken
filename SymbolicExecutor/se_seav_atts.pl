%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% SEAV
% Defines the module seav for Symbolic Execution Attributed Variables
%   briefly the attribute is of the form : mika_seav(Name, Type_name, Input_value, Output_value)
%                                                    N     T          I            O        
%   Name         : name of the variable
%   Type_name    : just the type_name of the variable
%   Input_value  : the input value of the variable: free for uninitialised variables, immutable during symbolic execution
%   Output_value : the current value of the variable: initially Input_value, mutated via assignments
%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- module('se_seav_atts').
:- export se_seav__create_var/3, seav__is_seav/1, seav__get/3, seav__update/2.

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
print_seav(_{se_seav_atts(Attr)}, Print) :-
	-?->
	Print = seav(Attr).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
seav__create_var(Var, Type_name, SEAV):-
    add_attribute(Seav, se_seav_atts(Name, Type_name, _, _)).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
seav__is_seav(_{Attr}) :-
    -?->
    compound(Attr),
    Attr = se_seav_atts(_Name, _, _, _).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
seav__get(_{Attr}, name, Name) :-        
    -?->
   Attr = seav(Name, _, _, _).
seav__get(_{Attr}, type, Type_name) :-        
    -?->
   Attr = seav(_, Type_name, _, _).
seav__get(_{Attr}, input, Input) :-        
    -?->
   Attr = seav(_, _, Input, _).
seav__get(_{Attr}, output, Output) :-        
    -?->
   Attr = seav(_, _, _, Output).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
seav__update(_{Attr}, input, Input) :-        
    -?->
   setarg(3, Attr, Input).
seav__update(_{Attr}, output, Output) :-        
    -?->
   setarg(4, Attr, Output).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%