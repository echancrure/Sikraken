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