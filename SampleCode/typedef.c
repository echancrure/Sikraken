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
static const table universal_time_zone_table_200015[4]; //table is a typedef name denoting struct table
static table tt; //table is a typedef name denoting struct table
table t3;
static table ttt; //table is a typedef name denoting struct table
typedef int my_int;
int a = 1;
int y = (my_int)1;  //my_int is a typedef name

int hello1(int *table) { //table is a parameter, an identifier, not a typedef name, it SHADOWS the typedef name table
    int a = 1;
    int my_int = 42;    //shadowing of typedef name my_int
    //int x = (my_int);   //causes parser error because shadowing is not implemented
    return 0;
}

int hello2(table tt) { //table is the typedef
    return 0;
}

int main() {
    int table = 0; //table is a variable, not a typedef name
    //table t;  //gcc error: conflict as table represent a var and a typedef in the same scope and the same namespace
    //int x = 6 + table; //causes parser error because shadowing is not implemented
    table : a = 6; //table is a label, not a typedef name
    //return table; //causes parser error because shadowing is not implemented
}