#include "../linkedList.h"
typedef struct NodeforStack{
    Number data;
    struct NodeforStack *up;
}NodeforStack;

typedef struct Stack{
    NodeforStack* top ;
}Stack;

void initStackN(Stack*);
void pushN(Stack*,Number);
Number popN(Stack*);
Number getTopN(Stack);
int getSizeOfStackN(Stack);
void displayN(Stack s);
