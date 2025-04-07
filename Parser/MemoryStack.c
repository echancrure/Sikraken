#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void join_nodes();
void populate_dot_file();
void init_storage();

typedef struct Node{
    int branch_nb;
    int inDoWhile;//true if node is part of dowhile loop
    int breakOn;//true if node has nested break statement
    int loopNo;//no of loop nested.
    struct Node *true_path;
    struct Node *false_path;
    struct Node *next_node;

}Node;

Node    *top = NULL; //keeps track of nodes when pushed onto the stack
Node    *head = NULL; //keeps track of nodes when poped out of stack. 
Node    *breakPoint = NULL;//for nodes with break statements
Node    *tempNode = NULL;//useful with continue statements
Node    *terminalNode = NULL;//for nodes leading to the end of function
bool    startNode = true;// for the first node inside a function. 
int     stack_count = 0;// number of nodes onto the stack.

//initialize a new node
Node* makeNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        exit(EXIT_FAILURE);  
    }
    newNode -> branch_nb = 0;
    newNode -> inDoWhile = 0;
    newNode -> breakOn = 0;
    newNode -> loopNo = 0;
    newNode -> inDoWhile = false;
    newNode -> true_path = NULL;
    newNode -> false_path = NULL;
    newNode->next_node = top;  
    return newNode;
}

//create a new node and push it onto the memory stack.
void push(bool isFalse, int loopNo) {	
    Node *temp = makeNode(); 

    if (top == NULL) {
        temp->loopNo = loopNo;
        top = temp; 
    } else {
        if (isFalse) {
            top->false_path = temp;
        } else if (top->true_path == NULL) {
            top->true_path = temp;
        } 
        temp->loopNo = loopNo;
        temp->next_node = top;
        top = temp;
    }

    stack_count++;
}

//pop node off from stack
void pop(int branch_num){
    Node *temp = makeNode();
    temp = top;
    top = top->next_node;
    temp->branch_nb = branch_num;
    temp -> next_node = head;
    head = temp;
    stack_count--;
}
void join_nodes(Node *node) {
    if (head == NULL || node == NULL) {
        return;  // Prevent segmentation fault
    }
    Node *temp = head;
    
    while (temp != NULL) {
        if (temp->true_path == NULL) {
            temp->true_path = node;
        }
        if (temp->false_path == NULL) {
            temp->false_path = node;
        }
        temp = temp->next_node;
    }
}
void loopAround(){
    if(top->true_path == NULL){
        top->true_path = top;
     }else{
        join_nodes(top);// The nested node will go back to iteration node
     }
}
// method to write dot file.
void populate_dot_file(FILE *dot_file, char* funName) {
    if (head != NULL) {
        Node *temp = head; 
        while (temp != NULL) {
            if (temp->true_path != NULL && temp->true_path != terminalNode)
                fprintf(dot_file, "\"%d\" -> \"%d\" [label = \"T\"];\n", temp->branch_nb, temp->true_path->branch_nb);
            else
                fprintf(dot_file, "\"%d\" -> \"End %s\" [label = \"T\"];\n", temp->branch_nb, funName);

            if (temp->false_path != NULL && temp->false_path != terminalNode)
                fprintf(dot_file, "\"%d\" -> \"%d\" [label = \"F\"];\n", temp->branch_nb, temp->false_path->branch_nb);
            else
                fprintf(dot_file, "\"%d\" -> \"End %s\" [label = \"F\"];\n", temp->branch_nb, funName);

            temp = temp->next_node;
        }
        head = NULL;
    } else {
        fprintf(dot_file, "\"Start %s\" -> \"End %s\";\n",funName, funName);
    }
}

//method to attack start node to the first node of a function
void attach_start(FILE *dot_file, char* funName){
    if(startNode && stack_count == 0){
        fprintf(dot_file, "\"Start %s\" -> \"%d\"	 \n",funName, head->branch_nb);
        startNode = false;
    }else{
        return;
    }
}
//method to connect nodes nested in dowhile loop
void connectDoWhile(int doWhileNum){
    Node *temp = head; 
    
    while (temp != NULL) {
        if (temp->inDoWhile == doWhileNum) {
            top->true_path = temp;
            temp->inDoWhile --;
        }
        temp = temp->next_node; 
    }
    if(top->inDoWhile>0){
        top->inDoWhile--;
        if(top->true_path == NULL){
            top->true_path = top;
        }
    } 
}
//get the break points to attach for the nodes with nested break statements
Node* getBreakPoint(){
    if(breakPoint == NULL){
        breakPoint = makeNode();
    }
    return breakPoint;
}
//remove break nodes
void removeBreaks(int loopNo){
    Node *temp = head;
    while(temp != NULL){
        if(temp->true_path == breakPoint && temp->breakOn == loopNo){
            temp->true_path = NULL;
        }
        if(temp->false_path == breakPoint && temp->breakOn == loopNo){
            temp->false_path = NULL;
        }
        temp = temp->next_node;
    }
}

//return the loop with continue statement
Node* find_loop(int loopNo){
    Node* temp = top;
    while(temp != NULL){
        if(temp->loopNo = loopNo){
            tempNode = temp;
        }
        temp = temp->next_node;
    }
    return tempNode;
}
//attach terminal nodes with the nodes leading to the end of function
void terminateNode(bool isFalse){
    if(terminalNode == NULL){
        terminalNode = makeNode();
        terminalNode->branch_nb = -1;
    }
    if(top != NULL){
        if(!isFalse && top->true_path == NULL){
            top->true_path = terminalNode;
        }else if(top->false_path == NULL){
            top->false_path = terminalNode;
        }else{
            join_nodes(terminalNode);
        }
            
        
    }else{
        join_nodes(terminalNode);
    }   
}

//Goto statements are a bit complex to deal with due to different cases in which 
//it is used. The below function keeps track of all the goto statemnents and 
//their labels and resolve them after the function is fully parsed.

#define INIT_SIZE 5
typedef struct {
    char    label_name[50];
    Node*   targetNode;//the node after goto.
} LabelInfo;

LabelInfo* labels = NULL;
int label_count = 0;
int label_capacity = INIT_SIZE;
typedef struct {
    char    target_label[50];
    Node*   jumpNode;//the node immidiatly before goto
    bool    isFalse;
} GotoInfo;

GotoInfo* gotos = NULL;
int goto_count = 0;
int goto_capacity = INIT_SIZE;

void init_storage() {
    labels = (LabelInfo *)malloc(label_capacity * sizeof(LabelInfo));
    gotos = (GotoInfo *)malloc(goto_capacity * sizeof(GotoInfo));
    if (!labels || !gotos) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

//adds labels where goto directs.
void add_label(const char *name, Node *targetNode) {
    if (!name || !targetNode) {
        fprintf(stderr, "Invalid label or targetNode\n");
        return;
    }
    if(!labels){
        init_storage();
    }
    if (label_count >= label_capacity) {
        label_capacity *= 2;
        labels = (LabelInfo *)realloc(labels, label_capacity * sizeof(LabelInfo));
        if (!labels) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(1);
        }
    }
    strcpy(labels[label_count].label_name,name);
    if (!labels[label_count].label_name) {
        fprintf(stderr, "Memory allocation for label name failed\n");
        exit(1);
    }
    labels[label_count].targetNode = targetNode;
    label_count++;
}
// adds labels with goto keyword
void add_goto(const char *name, Node *jumpNode, bool isFalse) {
    if (!name || !jumpNode) {
        fprintf(stderr, "Invalid goto or jumpNode\n");
        return;
    }
    if(!gotos){
        init_storage();
    }
    if (goto_count >= goto_capacity) {
        goto_capacity *= 2;
        gotos = (GotoInfo *)realloc(gotos, goto_capacity * sizeof(GotoInfo));
        if (!gotos) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(1);
        }
    }
    strcpy(gotos[goto_count].target_label, name);
    gotos[goto_count].jumpNode = jumpNode;
    gotos[goto_count].isFalse = isFalse;
    goto_count++;
}
//compare all the labels with goto labels and join the nodes accordingly
void resolve_gotos(){
    for(int i = 0; i < goto_count; i++){
        for(int j = 0; j < label_count; j++){
            if(strcmp(gotos[i].target_label, labels[j].label_name) == 0){
                if(gotos[i].isFalse){
                    gotos[i].jumpNode->false_path = labels[j].targetNode;
                }else{
                    gotos[i].jumpNode->true_path = labels[j].targetNode;
                }
            }
        }
    }
}


void free_storage() {
    free(labels);
    free(gotos);
}