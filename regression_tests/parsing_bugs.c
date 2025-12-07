typedef int MYINT;
MYINT myint;
struct table;
typedef struct table table;
struct table {
    const char *name;
    int type;
    int value;
};
static int *inSpecMode(int table);  //table is declared as shadow identifier
static int *allocate_entry_120489(int *table);  //table is declared as shadow identifier
struct inpcb *in_pcbffffffffffhashlookup(struct inpcbtable *, struct in_addr, int,
                                 struct in_addr, int , int, int);                               
typedef unsigned int __uint32_t;
typedef __uint32_t u_int32_t;
struct baddynamicports {
  u_int32_t tcp[((((65536) + (((sizeof(u_int32_t) * 8)) - 1)) /
                  ((sizeof(u_int32_t) * 8))))];
  u_int32_t udp[((((65536) + (((sizeof(u_int32_t) * 8)) - 1)) /
                  ((sizeof(u_int32_t) * 8))))];
};
extern struct baddynamicports baddynamicports;
extern struct baddynamicports rootonlyports;
void in_losing(struct inpcb *);
void f() {
   int x0 = ({ //statement expression in GCC
      int a = 5;
      int b = 10;
      a + b;   // last expression → value returned
   });
}
struct device {//struct device_private   *p;
};
struct A {
 int a;
 int b;
};
struct my_data {
 int lock;
 struct device dev;
 struct A shared;
};
struct device *my_dev;
struct my_data *data;
int oso = __builtin_offsetof (struct my_data, dev); //builtin function call
void g() {
   data = ({ const typeof( ((struct my_data *)0)->dev ) *__mptr = (my_dev); (struct my_data *)( (char *)__mptr - __builtin_offsetof (struct my_data, dev) );});
}
typedef void *PVOID;
typedef void *PVOID2;
void (*NormalRoutine)(PVOID NormalContext , PVOID SystemArgument1 , PVOID SystemArgument2 ) ;
struct _KAPC {
   void (*RundownRoutine)(int x) ;
   void (*NormalRoutine)(PVOID NormalContext2 , PVOID SystemArgument1 , PVOID SystemArgument2 ) ;
   int chris2[sizeof(PVOID2)];
   PVOID NormalContext3 ;
};
static __thread int tl_last_error = 0;
void aws_raise_error_private(int err) {
    tl_last_error = err;
}
    int x = .5;
    void *p = &x;      // p is a void pointer pointing to x
    void **pp = &p;    // pp is a pointer to a void pointer
extern int __VERIFIER_nondet_int();
typedef int my_int56;                              //23 November 2025
void my_f(void) {
   typedef my_int56 (MyFuncPtr)(int, int);           // my_int56 is a type, MyFuncPtr is the new type name
   typedef my_int56 (*MyFuncPtr_Pointer)(int, int); // my_int56 is a type, MyFuncPtr_Pointer is the new type name
   my_int56 (*my_callback_ptr)(void);              //my_int56 is a type
   int my_int56(int x);                            //my_int56 is a shadow identifier
}
typedef unsigned short umode_t; //22nd November 2025
struct kobject;                 // example from 2_1_cilled_ok_nondet_linux-3.4-32_1-drivers--macintosh--mac_hid.ko-ldv_main0_sequence_infinite_withcheck_stateful.cil.out.i
struct attribute {
   char const *name ;
   umode_t mode ;
};
umode_t (*is_visible)(struct kobject * , struct attribute * , int ) ;    //works mode in DM_NONE
struct attribute_group {
   char const *name ;
   umode_t (*is_visible)(struct kobject * , struct attribute * , int ) ;    //FIXED: Sikraken Parsing error: syntax error, unexpected IDENTIFIER, at line 344, near token '' (token code: 258)
   struct attribute **attrs ;
};
typedef unsigned long size_t;
typedef long ssize_t;
struct sysfs_ops {
   ssize_t (*show)(struct kobject * , struct attribute * , char * ) ;   //FIXED: Sikraken Parsing error: syntax error, unexpected IDENTIFIER, at line 360, near token '' (token code: 258)
   ssize_t (*store)(struct kobject * , struct attribute * , char const * , size_t ) ;
   void const *(*namespace)(struct kobject * , struct attribute const * ) ;
};
struct ctl_table;          //forward declaration
typedef struct ctl_table ctl_table;    //typedef
typedef long long loff_t;
typedef int proc_handler(struct ctl_table *ctl , int write , void *buffer , size_t *lenp , loff_t *ppos );  //typedef proc_handler is a function type
struct ctl_table {
   char const *procname ;
   void *data ;
   int maxlen ;
   umode_t mode ;
   struct ctl_table *child ;  //ctl_table is just a tag
   proc_handler *proc_handler ;
   struct ctl_table_poll *poll ;
   void *extra1 ;
   void *extra2 ;
};
struct __anonstruct____missing_field_name_212 {
   struct ctl_table *ctl_table ;                //FIXED: Sikraken Parsing error: syntax error, unexpected TYPEDEF_NAME, expecting IDENTIFIER or '(', at line 1237, near token 'ctl_table' (token code: 259)
   int used ;
   int count ;
   int nreg ;
};
typedef __builtin_va_list __gnuc_va_list[1U];   //FIXED: Sikraken Parsing error: syntax error, unexpected '[', expecting ';', at line 42, near token '[' (token code: 91)
typedef unsigned long int __uint64_t;
typedef __uint64_t uint64_t;
typedef uint64_t(aws_hash_fn)(const void *key);
int my_func() {
   asm("nop");
   __asm__("nop");
   __asm("nop");
}; //gcc allows this
int main() {
    int v = __VERIFIER_nondet_int();
    int x = 42;
    if (v == x) {
        x++;
    }
    return x;
}