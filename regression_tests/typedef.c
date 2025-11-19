//15 Nov 2025
struct lock_class_key { //valid: GCC and (Clang?) allow empty struct_declaration_list but C11 does not (C++ does...)
};
extern void abort(void);

typedef int claude1;
int main_claude1() {
    int claude1 = 5;
    int x = (int)3.14 + claude1;  // OK: uses the shadow claude1
}


typedef int claud; //or clause both work
int main_claude() {
    int claude = 5;
    int x = _Alignof(claude);   //accept type_name and expression
}

extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

typedef unsigned long __kernel_ulong_t;
//typedef unsigned int __kernel_uid32_t;
//typedef unsigned int __kernel_gid32_t;
typedef __kernel_ulong_t __kernel_size_t;
    
struct tabX{ 
        const char *name;
        int type;
        int value;
    };
typedef struct tabX tableX;
//int table = 0;  //OK: GCC error redeclaration of a different symbol is not allowed

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
int hello0(int my_int2); //function prototype: should not define my_int2 as shadowing the typedef name just as an IDENTIFIER

int hello0(int my_int3) {
    return 0;
}

int hello1(my_int2 *y) { 
    while (y != ((void *)0)) {
        my_int2* z = y; 
        int a = 1;
        int my_int = 42;        //IDENTIFIER declaration shadows the TYPEDEFNAME my_int defined above, lexer must return IDENTIFIER and add as a shadow
        //my_int new_id = 42;     //gcc error
        int hello1 = sizeof(my_int);
    }
    //int x = (my_int);   //causes parser error because shadowing is not implemented
    return 0;
}

int hello2(table tt) { //table is the typedef
    typedef char my_int;
    return 0;
}

int main() {
    int table = 0; //table is a variable, not a typedef name
    //table t;  //gcc error: conflict as table represent a var and a typedef in the same scope and the same namespace [although the programmer's intent is clear and our parser can handle this]
    int x = 6 + table; //causes parser error because shadowing is not implemented
    table : a = sizeof(table); //1st table is a label, not a typedef name, 2nd table is a TYPDEFNAME
    return table; //causes parser error because shadowing is not implemented
}