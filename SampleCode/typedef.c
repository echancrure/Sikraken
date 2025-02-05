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

int hello(int *table) { //table is a parameter, an identifier, not a typedef name
    return 0;
}

int main() {
    int table = 0; //table is a variable, not a typedef name
    table t;
    //int x = 6 + table; //table is a variable, not a typedef name
    //table : x = 6; //table is a label, not a typedef name
    return table;
}