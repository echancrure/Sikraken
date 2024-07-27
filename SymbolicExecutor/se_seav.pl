%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% SEAV
% Defines the module seav for Symbolic Execution Attributed Variables
%   briefly the attribute is of the form : mika_seav(Name, Address, Input_value, Output_value, Type)
%                                                    N     A        I            O             T
%   Name         : name of the variable
%   Address      : address of the vraiable
%   Input_value  : the input value of the variable: free for uninitialised variables, immutable during symbolic execution
%   Output_value : the current value of the varaible: initially Input_value, mutated via assignments
%   Type         : just the type_name of the variable
%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- module('se_seav').
:- export se_seav__create_var/3.

seav__create_var(42, Type_name, Init).