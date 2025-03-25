#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void join_nodes();
void populate_dot_file();

typedef struct Node{
    int branch_nb;
    int inDoWhile;
    int breakOn;
    int loopNo;
    struct Node *true_path;
    struct Node *false_path;
    struct Node *next_node;

}Node;

Node    *top = NULL; //keeps track of nodes when pushed onto the stack
Node    *head = NULL; //keeps track of nodes when poped out of stack. 
Node    *breakPoint = NULL;
Node    *helperNode = NULL;
Node    *tempNode = NULL;
Node    *terminalNode = NULL;
bool    startNode = true;
int     stack_count = 0;

Node* makeNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        exit(EXIT_FAILURE);  // Proper exit call
    }
    newNode -> branch_nb = 0;
    newNode -> inDoWhile = 0;
    newNode -> breakOn = 0;
    newNode -> loopNo = 0;
    newNode -> inDoWhile = false;
    newNode -> true_path = NULL;
    newNode -> false_path = NULL;
    newNode->next_node = top;  // Assign the top pointer (if relevant)
    return newNode;
}

void push(bool isFalse, int loopNo) {	
    Node *temp = makeNode();  // Create a new node

    if (top == NULL) {
        temp->loopNo = loopNo;
        top = temp;  // Initialize first node
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
    printf("join nodes called\n");
    if (head == NULL || node == NULL) {
        return;  // Prevent segmentation fault
    }
    Node *temp = head; // Start traversal from head
    
    while (temp != NULL) {
        if (temp->true_path == NULL) {
            printf("true path becomes true\n");
            temp->true_path = node;
        }
        if (temp->false_path == NULL) {
            temp->false_path = node;
        }
        temp = temp->next_node; // Move to the next node
    }
}

void populate_dot_file(FILE *dot_file, char* funName) {
    if (head != NULL) {
        Node *temp = head; // Start traversal from head
        while (temp != NULL) {
            if (temp->true_path != NULL && temp->true_path != terminalNode)
                fprintf(dot_file, "\"%d\" -> \"%d\" [label = \"T\"];\n", temp->branch_nb, temp->true_path->branch_nb);
            else
                fprintf(dot_file, "\"%d\" -> \"End %s\" [label = \"T\"];\n", temp->branch_nb, funName);

            if (temp->false_path != NULL && temp->false_path != terminalNode)
                fprintf(dot_file, "\"%d\" -> \"%d\" [label = \"F\"];\n", temp->branch_nb, temp->false_path->branch_nb);
            else
                fprintf(dot_file, "\"%d\" -> \"End %s\" [label = \"F\"];\n", temp->branch_nb, funName);

            temp = temp->next_node; // Move to the next node
        }
        head = NULL;
    } else {
        fprintf(dot_file, "\"Start %s\" -> \"End %s\";\n",funName, funName);
    }
}

void attach_start(FILE *dot_file, char* funName){
    if(startNode && stack_count == 0){
        printf("attach start called \n");
        fprintf(dot_file, "\"Start %s\" -> \"%d\"	 \n",funName, head->branch_nb);
        startNode = false;
    }else{
        return;
    }
}
void connectDoWhile(int doWhile){
    Node *temp = head; // Start traversal from head
    
    while (temp != NULL) {
        if (temp->inDoWhile == doWhile) {
            top->true_path = temp;
            temp->inDoWhile --;
        }
        temp = temp->next_node; // Move to the next node
    }


    // Ensure top->true_path is valid before modifying top->inDoWhile
    if(top->inDoWhile>0){
        top->inDoWhile--;
        if(top->true_path == NULL){
            top->true_path = top;
        }
    } 
}

Node* getBreakPoint(){
    if(breakPoint == NULL){
        breakPoint = makeNode();
    }
    return breakPoint;
}

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

void terminateNode(){
    if(terminalNode == NULL){
        terminalNode = makeNode();
        terminalNode->branch_nb = -1;
    }
    if(top != NULL && top->true_path == NULL){
        top->true_path = terminalNode;
    }else{
        join_nodes(terminalNode);
    }   
}