%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                                 Copyright 2025 SETU - Dr Christophe Meudec 
%%                                     <https://github.com/echancrure/Sikraken>
%% This file is part of Sikraken.
%% Sikraken is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
%%   the Free Software Foundation.
%% Sikraken is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
%%   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
%% GNU Lesser General Public License v3.0 only
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Contains the predicate to create the CFG by covering the entire code under test
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- dynamic cfg_branch/3.                    %dynamic predicate to store the CFG's branches: cfg_branch(From, Truth_value, To)
:- local reference(current_node, start).          %the current node id during CFG building
:- local reference(current_truth_value, true).    %the current truth value during CFG building
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Build the CFg of the code under test
cfg_build__build_cfg(Parsed_prolog_code) :-
    init,
    (cover(Parsed_prolog_code) *->      %'soft-cut' to enumerate all choice points in cover
        create_branch(end)
    ;
        common_util__error(10, "Fatal error in cover/1", "Failed without leaving a choice point: Should never happen", [], '10_010825_1', 'se_main', 'cfg_build__build_cfg', no_localisation, no_extra_info)
    ),
    fail.   %induces bactracking within cover/1
cfg_build__build_cfg(_) :-
    !,
    true.   %build successors etc.
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %necessary initialisations during development to start from a clean empty CFG
    init :- 
        retractall(cfg_branch(_, _, _)),    
        setref(current_node, start),
        setref(current_truth_value, true).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    cover(_).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    create_branch(_).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%