typedef unsigned short umode_t; //22nd November 2025
struct kobject;                 // example from 2_1_cilled_ok_nondet_linux-3.4-32_1-drivers--macintosh--mac_hid.ko-ldv_main0_sequence_infinite_withcheck_stateful.cil.out.i
struct attribute {
   char const *name ;
   umode_t mode ;
};
umode_t (*is_visible)(struct kobject * , struct attribute * , int ) ;    //works mode in DM_NONE
struct attribute_group {
   char const *name ;
   umode_t (*is_visible)(struct kobject * , struct attribute * , int ) ;    //Sikraken Parsing error: syntax error, unexpected IDENTIFIER, at line 344, near token '' (token code: 258)
   struct attribute **attrs ;
};