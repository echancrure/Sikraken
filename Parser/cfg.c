#include <igraph.h>
#include <stdio.h>
#include <string.h>
#include "safe_alloc.h"
extern void my_exit(int exit_code);
extern char *current_function_name;
extern int debugMode;

igraph_t current_cfg;               // The current unique control flow graph (CFG) within the parser, used for all functions

// Partial branches in the CFG: a branch from a node with a truth value but to unknown destination node 
typedef enum {
    PARTIAL_IF,
    PARTIAL_ELSE,
    PARTIAL_WHILE,
    PARTIAL_FOR,
    PARTIAL_SWITCH,
    PARTIAL_OTHER   // e.g. for start, end nodes
} partial_type_t;

typedef struct {    // Represents a partial branch in the CFG where only the from and truth value of the branch are known
    partial_type_t type; // type of the partial branch (e.g., if, else, while)
    igraph_integer_t from_node;
    _Bool truth_value;
} partial_branch_t;

typedef struct partial_branch_node {    // Linked list node for partial branches
    partial_branch_t *branch;
    struct partial_branch_node *next;
} partial_branch_node_t;

typedef struct cfg_scope_stack_node {       // Stack node for managing scopes of partial branches in the CFG
    igraph_integer_t node_level;
    partial_branch_node_t *branches;
    struct cfg_scope_stack_node *next;
} cfg_scope_stack_node_t;

cfg_scope_stack_node_t *cfg_scope_stack = NULL; // Stack for managing scopes of partial branches

/* Functions sub-CFGs data structure */
typedef struct {
    char *function_name;                // no scoping issue: in C all functions are global
    igraph_integer_t start_node;
    igraph_integer_t end_node;
} function_info_t;

#define MAX_FUNCS 1000
function_info_t function_cfgs[MAX_FUNCS];   // use dynamic data structure?
int function_cfgs_count = 0;

igraph_integer_t create_new_node() {
    igraph_integer_t new_node_id = igraph_vcount(&current_cfg);  // Get current vertex count as new ID
    igraph_add_vertices(&current_cfg, 1, 0);  // Add one vertex
    return new_node_id;  // Return igraph's internal node ID (0, 1, 2, ...)
}

void add_edge_labeled(igraph_integer_t from, _Bool truth_value, igraph_integer_t to) {
    igraph_add_edge(&current_cfg, from, to);
    igraph_integer_t eid = igraph_ecount(&current_cfg) - 1;  // Last edge index
    SETEAB(&current_cfg, "label", eid, truth_value);
}

void close_all_partial_branches(igraph_integer_t new_node_id) {
    partial_branch_node_t *partial_branches_list = cfg_scope_stack->branches;
    if (!partial_branches_list) {   //should never happen
        fprintf(stderr, "CFG fatal algorithm error: partial branches when trying to create new node id: %i\n", (int)new_node_id);
		my_exit(EXIT_FAILURE);
    }
    igraph_integer_t from_node;
    _Bool truth_value; 
    partial_branch_node_t *next_node;
    while (partial_branches_list) { // Iterate through all partial branches in the current scope and complete them
        from_node = partial_branches_list->branch->from_node;
        truth_value = partial_branches_list->branch->truth_value;
        add_edge_labeled(from_node, truth_value, new_node_id);
        if (debugMode) printf("CFG created a new branch [%d, %d, %d]\n", (int)from_node, truth_value, (int)new_node_id);
        next_node = partial_branches_list->next;
        free(partial_branches_list->branch);  
        free(partial_branches_list);  
        partial_branches_list = next_node;  // Move to the next node in the list
    }
}

// Push a new scope for a new single partial branch onto the stack of scopes
void cfg_push_branch_scope(partial_type_t type, igraph_integer_t from_node, _Bool truth_value) {
    cfg_scope_stack_node_t *new_scope = (cfg_scope_stack_node_t *)safe_malloc(sizeof(cfg_scope_stack_node_t));
    partial_branch_node_t *new_branch = (partial_branch_node_t *)safe_malloc(sizeof(partial_branch_node_t));
    new_branch->branch = (partial_branch_t *)safe_malloc(sizeof(partial_branch_t));
    new_branch->branch->type = type;
    new_branch->branch->from_node = from_node;
    new_branch->branch->truth_value = truth_value;
    new_branch->next = NULL;
    new_scope->node_level = from_node;
    new_scope->branches = new_branch;
    new_scope->next = cfg_scope_stack;
    cfg_scope_stack = new_scope;
    if (debugMode) printf("CFG Pushed a new scope with the partial branche [%d %s]\n", (int)from_node, truth_value ? "T" : "F");
}

// Pop the current scope from the stack and merge its branches into the previous scope
// This is called at the end of an if statement, else statement, while loop, etc
// It merges the branches of the current scope into the previous scope, freeing the current scope
// It should never be called when there is only one scope left in the stack because that would mean the parser is trying to pop the last scope
igraph_integer_t cfg_pop_branch_scope() {
    if (!cfg_scope_stack) {
        fprintf(stderr, "Fatal parsing algorithm error: trying to pop an empty scope stack\n");
        my_exit(EXIT_FAILURE);
    }
    if (!cfg_scope_stack->next) {
        fprintf(stderr, "Fatal parsing algorithm error: trying to pop the last scope stack\n");
        my_exit(EXIT_FAILURE);
    }
    cfg_scope_stack_node_t *old_scope = cfg_scope_stack;
    igraph_integer_t old_node_level = old_scope->node_level;
    //find the last branch of the previous scope
    partial_branch_node_t *last_branch = old_scope->branches;
    while (last_branch && last_branch->next) {
        last_branch = last_branch->next;                    
    }
    //append the current branches to the previous scope
    if (last_branch) {
        last_branch->next = cfg_scope_stack->branches;
    } else {
        old_scope->branches = cfg_scope_stack->branches;  // If no last branch, set the current branches as the first
    }
    cfg_scope_stack = cfg_scope_stack->next;  // Move the stack pointer to the next scope
    free(old_scope->branches);  // Free the old branches list
    free(old_scope);  // Free the old scope
    if (debugMode) printf("CFG popped the scope level %d\n", (int)old_node_level);
    return old_node_level;  // Return the node level of the popped scope
}

// Called when a new function is being parsed
void cfg_parse_start_function() {
    if (function_cfgs_count >= MAX_FUNCS) {
        fprintf(stderr, "CFG fatal error: Maximum number of functions exceeded.\n");
        my_exit(EXIT_FAILURE);
    }
    igraph_integer_t start_node = create_new_node();
    igraph_integer_t end_node = create_new_node();
	function_cfgs[function_cfgs_count].function_name = strdup(current_function_name);
    function_cfgs[function_cfgs_count].start_node = start_node;
	function_cfgs[function_cfgs_count].end_node = end_node;    
    if (debugMode) printf("CFG: Declared new function %s with start node %d and end node %d\n", current_function_name, (int)start_node, (int)end_node);
    cfg_push_branch_scope(PARTIAL_OTHER, start_node, 1); // Push the start node as a partial branch [S, T]
    function_cfgs_count++;
}

// Called when the function has been completely parsed 
void cfg_parse_end_function() {
    close_all_partial_branches(function_cfgs[function_cfgs_count - 1].end_node); // Complete all partial branches in the current function scope
    if (debugMode) printf("CFG: Completed function %s with end node %d\n", current_function_name, (int)function_cfgs[function_cfgs_count - 1].end_node);
}

void cfg_init() {
    igraph_empty(&current_cfg, 0, IGRAPH_DIRECTED);
}

// Create a new node in the CFG and return its unique ID
// Called at the start of an if statement, The ID is generated by igraph based on the current vertex count
// All the current partial branches are completed by connecting them to the new node (there should always be at least one partial branch)
// The completed branches are added to the graph
// All partial branches are freed
igraph_integer_t cfg_parse_new_node() {
    igraph_integer_t new_node_id = create_new_node();
    close_all_partial_branches(new_node_id);  // Complete all partial branches in the current scope and connect them to the new node
    return new_node_id;
}

void cfg_write_graph_dot_labelled(FILE *file) {
    long int i, n;

    fprintf(file, "digraph G {\n");

    // --- Write nodes with their id ---
    n = igraph_vcount(&current_cfg);
    for (i = 0; i < n; i++) {
        fprintf(file, "  %ld [label=%ld];\n", i, i);
    }

    // --- Write edges with labels ---
    n = igraph_ecount(&current_cfg);
    for (i = 0; i < n; i++) {
        igraph_integer_t from, to;
        igraph_edge(&current_cfg, i, &from, &to);                   //retrieve the edge endpoints
        igraph_bool_t truth_value = EAB(&current_cfg, "label", i);  //and the label
        fprintf(file, "  %d -> %d [label=\"%s\"];\n", (int)from, (int)to, truth_value ? "T" : "F");
    }
    fprintf(file, "}\n");
}
