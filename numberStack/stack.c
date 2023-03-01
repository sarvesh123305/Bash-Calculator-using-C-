#include "stack.h"
#include<stdio.h>
#include<stdlib.h>


void initStackN(Stack* s){
    s -> top = NULL;
}
int isEmptyN(Stack s){
    return s.top == NULL;
}

void displayN(Stack s){
   if(isEmptyN(s))
   return ;

   NodeforStack* temp = s.top;
   printf("%c",temp -> data.sign);
   while(temp){
    Number go = temp -> data;
    while(go.num){
        printf("%d",go.num -> data);
        // printf("Yes");
        go.num = go.num -> next;
    }
    printf("\n");
    temp = temp -> up;
   }
}

Number getTopN(Stack s){
    Number newnode ;
    newnode.num = (List)malloc(sizeof(Node));
    newnode.num -> data = -1;
    newnode.num -> next = NULL;
    if(!s.top)
    return newnode;
    return s.top -> data;
}


void pushN(Stack* s,Number data){
    
    NodeforStack* newnode = (NodeforStack*)malloc(sizeof(NodeforStack));
    newnode -> data = data;
    newnode -> up = NULL;

    if(isEmptyN(*s))
    {
        s -> top = newnode;
    }
    else
    {
        newnode -> up = s -> top;
        s -> top = newnode;
    }
    return ;
}

Number popN(Stack *s){
    if(isEmptyN(*s)){
        Number result ;
        initNumber(&result);
        return result;
    }
    NodeforStack* deleteNode = s -> top;
    
    Number actualList = deleteNode -> data;
    // free(deleteNode);
    // display(actualList);
    s -> top = s -> top -> up;
    return actualList;
}
// Node* top(Stack);

int getSizeOfStackN(Stack s){
    if(isEmptyN(s))
    return 0;
    int ct = 0;
    NodeforStack* temp = s.top;
    while(temp){
        ct++;
        temp = temp -> up;
    }
    return ct;
}