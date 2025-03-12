#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void join_nodes();
void populate_dot_file();

typedef struct Node{
    int branch_nb;
    int inDoWhile;
    struct Node *true_path;
    struct Node *false_path;
    struct Node *next_node;

}Node;

Node    special_node = {0,false,NULL,NULL,NULL};
Node    *top = NULL; //keeps track of nodes when pushed onto the stack
Node    *head = NULL; //keeps track of nodes when poped out of stack. 
bool    startNode = true;
int     stack_count = 0;

Node* makeNode() {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        exit(EXIT_FAILURE);  // Proper exit call
    }
    newNode -> branch_nb = 0;
    newNode -> inDoWhile = false;
    newNode -> true_path = NULL;
    newNode -> false_path = NULL;
    newNode->next_node = top;  // Assign the top pointer (if relevant)
    return newNode;
}
void push(bool isFalse) {						
    Node *temp = makeNode();  // Create a new node

    if (top == NULL) {
        top = temp;  // Initialize first node
    } else {
        if (isFalse) {
            top->false_path = temp;
        } else if (top->true_path == NULL) {
            top->true_path = temp;
        } 
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
void join_nodes() {
    if (head == NULL || top == NULL) {
        return;  // Prevent segmentation fault
    }
    Node *temp = head; // Start traversal from head
    
    while (temp != NULL) {
        if (temp->true_path == NULL) {
            temp->true_path = top;
        }
        if (temp->false_path == NULL) {
            temp->false_path = top;
        }
        temp = temp->next_node; // Move to the next node
    }
}

void populate_dot_file(FILE *dot_file) {
    if (head != NULL) {
        Node *temp = head; // Start traversal from head
        while (temp != NULL) {
            if (temp->true_path != NULL && temp->true_path != &special_node)
                fprintf(dot_file, "\"%d\" -> \"%d\" [label = \"T\"];\n", temp->branch_nb, temp->true_path->branch_nb);
            else
                fprintf(dot_file, "\"%d\" -> \"End\" [label = \"T\"];\n", temp->branch_nb);

            if (temp->false_path != NULL && temp->false_path != &special_node)
                fprintf(dot_file, "\"%d\" -> \"%d\" [label = \"F\"];\n", temp->branch_nb, temp->false_path->branch_nb);
            else
                fprintf(dot_file, "\"%d\" -> \"End\" [label = \"F\"];\n", temp->branch_nb);

            temp = temp->next_node; // Move to the next node
        }
    } else {
        fprintf(dot_file, "\"Start\" -> \"End\";\n");
    }
}

void adjustDoWhile() {
    if (head == NULL || head->next_node == NULL) return; // Edge case: empty or single node

    Node *oldHead = head;           // Store current head
    Node *newHead = head->next_node; // Move head to next node
    Node *temp = head->next_node;
    Node *lastDoWhileNode = NULL;

    // Traverse the list to find the last node with inDoWhile == true
    while (temp != NULL) {  
        if (temp->inDoWhile) {
            lastDoWhileNode = temp;
        }
        temp = temp->next_node;
    }

    // If no node with inDoWhile == true exists, just update head
    if (lastDoWhileNode == NULL) {
        head = newHead;
        return;
    }

    // Move head to the next node
    head = newHead;

    // Insert oldHead after lastDoWhileNode
    oldHead->next_node = lastDoWhileNode->next_node;
    lastDoWhileNode->next_node = oldHead;
    oldHead->true_path = newHead;
}

void attach_start(FILE *dot_file){
    if(startNode && stack_count == 0){
        fprintf(dot_file, "\"Start\" -> \"%d\"	 \n", head->branch_nb);
        startNode = false;
    }else{
        return;
    }
}
void terminate_nodes(){
    Node *temp = head; // Start traversal from head
    while (temp != NULL) {
        if (temp->true_path == NULL) {
            temp->true_path = &special_node;
        }
        if (temp->false_path == NULL) {
            temp->false_path = &special_node;
        }
        temp = temp->next_node; // Move to the next node
    }
    if (top->true_path == NULL) {
        top->true_path = &special_node;
    }
    if (top->false_path == NULL) {
        top->false_path = &special_node;
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
