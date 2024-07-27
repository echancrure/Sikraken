%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% the heap!
% a global reference maintaining the memeory organisation of the SEAVs during symbolic execution
% it is directly modified (it grows) when a new SEAV is created or when memory is allocated during symbolic execution (e.g. via C malloc)
% it is accessed for reading when a SEAV pointer is deferenced
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
:- module('se_heap').
:- export se_heap__init/0, se_heap__create_var/3.

:- lib(hash).
:- local reference(heap).

se_heap__init :-
    setval('free_address', 100),
    hash_create(Heap),
    setref(heap, Heap).
%%%
%creates a seav and allocate it on the heap
se_heap__create_var(Var, Type_name, Init) :-
    getval('free_address', Free_address),
    seav__create_var(Var, Type_name, Init, Free_address),
    getref(heap, Heap),
    hash_set(Heap, Free_address, Var),
    get_type_size(Type_name, Type_byte_size),
    Next_free_address is Free_address + Type_byte_size,
    setval(free_address, Next_free_address).
%%%
se_heap__derefence(Address, SEAV) :-
    getref(heap, Heap),
    (hash_get(Heap, Address, SEAV) ->
        true
    ;
        common_util__error(10, "Deference of an invalid address", "Could return junk?", [('Address', Address)], 102707242, 'se_heap', 'se_heap__derefence', no_localisation, no_extra_info).
    ).
%%%
get_type_size(int, 4).