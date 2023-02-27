#include "../linkedList.h"
typedef struct NodeforStack{
    Node* data;
    struct NodeforStack *up;
}NodeforStack;

typedef struct Stack{
    NodeforStack* top ;
}Stack;




void initStackN(Stack*);
void pushN(Stack*,Node*);
Node* popN(Stack*);
Node* getTopN(Stack);
int getSizeOfStackN(Stack);
void displayN(Stack s);
