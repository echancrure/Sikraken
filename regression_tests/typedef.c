typedef unsigned long kernel_ulong_t, u_int32_t, u_int8_t, size_t;
u_int32_t ether_crc32_le_update(u_int32_t crc, const u_int8_t *, size_t);
static struct input_device_id const mac_hid_emumouse_ids[1] = { {(kernel_ulong_t )16, (unsigned short)0, (unsigned short)0, (unsigned short)0,
      (unsigned short)0, {1UL << 1}, {0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL,
                                      0UL, 0UL, 0UL}, {0UL}, {0UL}, {0UL}, {0UL},
      {0UL}, {0UL, 0UL}, {0UL}, 0UL}};
extern struct input_device_id const __mod_input_device_table __attribute__((__unused__,
__alias__("mac_hid_emumouse_ids"))) ;
typedef int u_int, caddr_t ;
u_int mextfree_register(void (*)(caddr_t, u_int, void *));
int x = (void (*)(int *handle , unsigned int type , unsigned int code , int value ))0;
typedef unsigned int size_t;
enum strtol_error {
    LONGINT_OK = 0,
    LONGINT_OVERFLOW = 1,
    LONGINT_INVALID_SUFFIX_CHAR = 2,
    LONGINT_INVALID_SUFFIX_CHAR_WITH_OVERFLOW = 3,
    LONGINT_INVALID = 4,
};
enum strtol_error human_options(const char *spec, int *opts, size_t *block_size);
typedef int FILE;
int add_exclude_fp(void (*add_func)(struct exclude_62137*, const char*, int, void*), struct exclude_62137 *ex, FILE *fp, int options, char line_end, void *data);
int _obstack_begin(struct obstack_186180 *h, size_t size, size_t alignment, void *(*chunkfun)(size_t), void (*freefun)(void*));
int _obstack_begin_1(void *(*chunkfun)(void*, size_t));
enum stv090x_modcod {
    STV090x_DUMMY_PLF = 0,
    STV090x_QPSK_14 = 1,
    STV090x_QPSK_13 = 2,
    STV090x_QPSK_25 = 3,
    STV090x_QPSK_12 = 4,
    STV090x_QPSK_35 = 5,
    STV090x_QPSK_23 = 6,
    STV090x_QPSK_34 = 7,
    STV090x_QPSK_45 = 8,
    STV090x_QPSK_56 = 9,
    STV090x_QPSK_89 = 10,
    STV090x_QPSK_910 = 11,
    STV090x_8PSK_35 = 12,
    STV090x_8PSK_23 = 13,
    STV090x_8PSK_34 = 14,
    STV090x_8PSK_56 = 15,
    STV090x_8PSK_89 = 16,
    STV090x_8PSK_910 = 17,
    STV090x_16APSK_23 = 18,
    STV090x_16APSK_34 = 19,
    STV090x_16APSK_45 = 20,
    STV090x_16APSK_56 = 21,
    STV090x_16APSK_89 = 22,
    STV090x_16APSK_910 = 23,
    STV090x_32APSK_34 = 24,
    STV090x_32APSK_45 = 25,
    STV090x_32APSK_56 = 26,
    STV090x_32APSK_89 = 27,
    STV090x_32APSK_910 = 28,
    STV090x_MODCODE_UNKNOWN = 29
} ;
typedef int s32;
typedef unsigned char u8;
static u8 stv090x_optimize_carloop(struct stv090x_state *state , enum stv090x_modcod modcod ,
                                   s32 pilots ) {;}
struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};
typedef unsigned int size_t;
typedef int locale_t;
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
register n = 5;
typedef int INT99;
int arr[] = {   //not hanlded at all in symbolic executor
        [0] = sizeof(typeof(int)),
        [1] = (INT99)30,
        [2] = arr[0] + 5 
    };
struct {
  int a, b, c;
} var44 = {sizeof(struct ddddd), (INT99)30};
typedef int MY_INT, MY_INT2, MY_INT3, MY_INT4;
void fn42(void) {
    int MY_INT; //shadowing declaration
    MY_INT = (MY_INT2) 56;  //MY_INT2 may trigger a shadow declaration, if you do not differentiate between statements and declarations
    typeof(MY_INT) MY_INT2; //MY_INT2 shadows the typedef//enum {MY_INT3} MY_INT4; //MY_INT3 shadows the typedef, so does MY_INT4
}
int v1, v2, v3;
struct tabletop;
typedef struct tabletop tabletop;
typedef int entier;
static int *inSpecMode(int tabletop, int x);  //tabletop is wrongly identified as a TYPEDEF_NAME here
static int *allocate_entry_120489(int entier);  //entier is wrongly identified as a TYPEDEF_NAME here
extern int __VERIFIER_nondet_int();
typedef int my_int44, my_int45, my_int46;//21 Nov
struct {
  int my_int44, my_int45;   //members who match a typedef_name should return an IDENTIFIER
  my_int46 my_int99;        //my_int46 is a typedefname
} var44;
typedef int my_int42;//20 Nov 2025
typedef my_int42 my_int43;
__extension__ typedef long int __time_t;
__extension__ typedef long int __syscall_slong_t;
typedef __time_t time_t;
struct timespec {
  __time_t tv_sec;  //__time_t is a typedef
  __syscall_slong_t tv_nsec;
};
struct lock_class_key { //15 Nov 2025//valid: GCC and (Clang?) allow empty struct_declaration_list but C11 does not (C++ does...)
};
extern void abort(void);
typedef int claude1;
int main_claude1() {
    int claude1 = 5;
    int x = (int)3.14 + claude1;  // OK: uses the shadow claude1
}
typedef long claude; //or clause both work
int main_claude() {
    int claude = 5;     //shadow identifier declaration
    int x = _Alignof(claude);   //accept type_name and expression, here it is an expression because claude is an identifier
}
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
typedef unsigned long __kernel_ulong_t;//typedef unsigned int __kernel_uid32_t;//typedef unsigned int __kernel_gid32_t;
typedef __kernel_ulong_t __kernel_size_t;
struct tabX{ 
        const char *name;
        int type;
        int value;
    };
typedef struct tabX tableX;//int table = 0;  //OK: GCC error redeclaration of a different symbol is not allowed
struct table;   //struct table is declared
typedef struct table table; //typedef is used to define table as struct table
union anonymous_62146 {
    int *table;  // table is a member, just an identifier
    int pat;
};
struct table {  //struct table is defined
    const char *name;
    int type;
    int value;
};
int my_array[5];
static const table universal_time_zone_table_200015[4]; //table is a typedef name denoting struct table
static table tt; //table is a typedef name denoting struct table
table t3;
static table ttt; //table is a typedef name denoting struct table
typedef int my_int;
int a = 1;
int y = (my_int)1;  //my_int is a typedef name
typedef struct node {
 int is_typedef_name;
 char* name;
 struct node* next;
} list_node;
void free_list_node(list_node* node) {
     // list_node* temp = node;
 while (node != ((void *)0)) {
   // int gh = 0;
  list_node* temp = node;
 }
}
typedef int my_int2;        //declared TYPEDEFNAME my_int2
int hello0(int my_int2);    //my_int2 should shadow
int hello1(int my_int2) {   //my_int2 should shadow
    my_int2++;
}    
int hello2(int my_int3) {
    return 0;
}
int hello3(my_int2 *y) { 
    while (y != ((void *)0)) {
        my_int2* z = y; 
        int a = 1;
        int my_int = 42;        //IDENTIFIER declaration shadows the TYPEDEFNAME my_int defined above, lexer must return IDENTIFIER and add as a shadow
        //my_int new_id = 42;     //gcc error
        int hello3 = sizeof(my_int);
    }//int x = (my_int); //gcc error: my_int  is a type here 
    return 0;
}
int hello4(table tt) { //table is the typedef
    typedef char my_int;
    return 0;
}
int main() {
    int table = 0; //table is a variable, not a typedef name //table t;  //gcc error: conflict as table represent a var and a typedef in the same scope and the same namespace [although the programmer's intent is clear and our parser can handle this]
    int x = 6 + table; //causes parser error because shadowing is not implemented
    table : a = sizeof(table); //1st table is a label, not a typedef name, 2nd table is a TYPDEFNAME
    int v = __VERIFIER_nondet_int();
    if (v == x) {
        x++;
    }
    return table; //causes parser error if shadowing is not implemented
}