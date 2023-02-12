// #include "addition.h"
#include "linkedList.h"
// #include "subtraction.h"

typedef struct NodeforStack{
    Node* data;
    struct NodeforStack *up;
}NodeforStack;

typedef struct Stack{
    // Node* data ;
    // int data;
    NodeforStack* top ;
}Stack;


char* inputExpression();
void controlEverything();

void initStack(Stack*);
void push(Stack*);
Node* pop(Stack*);
Node* top(Stack);
