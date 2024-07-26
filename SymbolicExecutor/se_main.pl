%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%                                 Copyright 2024 SETU - Dr Christophe Meudec 
%%                                     <https://github.com/echancrure/Sikraken>
%% This file is part of Sikraken.
%% Sikraken is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by
%%   the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
%% Sikraken is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
%%   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
%% You should have received a copy of the GNU General Public License along with Mika.  If not, see <https://www.gnu.org/licenses/>.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% main.pl
% defines module se_main
% symbolic execution of parsed C code
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- get_flag(version, '7.1').    %check for valid ECLiPSe version: issue warning only if not 
%%%
mytrace.            %call this to start debugging
:- spy mytrace/0.
%%%
:- module('se_main').
:- export se_main/5.

:- use_module('common_util').
:- import common_util__error/9 from common_util.

:- use_module('se_globals').
:- import se_globals__set_globals/2 from se_globals.

:- use_module('se_name_atts').
:- import se_name_atts__initL/1 from se_name_atts.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%se_main('//C/Users/Chris2/GoogleDrive/Sikraken/', '//C/Users/Chris2/GoogleDrive/Sikraken/SampleCode/', basic001, basic, debug)
se_main(Install_dir, Parsed_dir, Target_source_file_name, Target_raw_subprogram_name, Debug_mode) :-
    se_globals__set_globals(Install_dir, Debug_mode),
    read_parsed_file(Parsed_dir, Target_source_file_name),      %may fail if badly formed due to parsing errors
    prolog_c(Parsed_prolog_code, sikraken_xref(NamesL)),        %retrieve the entire contents of the parsed Prolog code
    se_name_atts__initL(NamesL),
    true.

%%%
read_parsed_file(Parsed_dir, Target_source_file_name) :-
    concat_atom([Parsed_dir, Target_source_file_name, '.pl'], Parsed_filename),
    (exists(Parsed_filename) ->
        (compile(Parsed_filename) ->    %may fail if parsed file contents is not well formed
            true
        ;
            common_util__error(10, "Compilation of parsed file failed", "Cannot process parsed C code", [('parsed_filename', Parsed_filename)], 102607241, 'se_main', 'read_parsed_file', no_localisation, "the parser probably produced bad Prolog code")
        )
    ;
        common_util__error(10, "Parsed file does not exist", "Cannot process parsed C code", [('parsed_filename', Parsed_filename)], 10260724, 'se_main', 'read_parsed_file', no_localisation, no_extra_info)
    ).
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%