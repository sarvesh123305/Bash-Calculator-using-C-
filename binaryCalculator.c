#include "binaryCalculator.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void convertCharArray(char *expression){
  
    int count1 = 0 , count2 = 0;
    for(int i = 0 ; expression[i] != '\0' ;i++){
        char ch = expression[i];

        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            count1++;
            count1++;
        }
    }
    printf("\n%d\n",++count1);
    char **ans = (char**)malloc(sizeof(char*)*count1)  ;
    int space = 0;
    char *str = (char*)malloc(sizeof(char)*space) ;
    int k = 0,a = 0;
    strcpy(str,"");
     for(int i = 0 ; expression[i] != '\0' ; i++){
        char ch = expression[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            ans[k] = (char*)malloc(sizeof(str));
            strcpy(ans[k++],str);
            
            strcpy(str,"");
            space = 1;
            str = realloc(str, space); // allocate new space
            str[a++] = (char)(ch);

            ans[k] = (char*)malloc(sizeof(str));
            strcpy(ans[k++],str);
            strcpy(str,"");
            space = 1;
            str = realloc(str, space); // allocate new space

        }
        else{
            str[a++] = (char)(ch);
            space++;              
            str = realloc(str, space); // allocate new space

        }
     } 
    //  printf("\n%s",str);
    // for(int i = 0 ; expression[i] != '\0' ; i++){
     

        // if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            // strcpy(ans[k++],str);
            // strcpy(str,"");
            
            // strcpy(str[i],ch);
            // strcat(str, ch);

            // strcpy(ans[k++],str);
            // 
        // }
        // else{
            // str[i] += ch;

        // }
    // }
   
}

void controlEverything(){
    // char* expression = inputExpression();
        // convertCharArray(expression);
     convertCharArray("2+1*3");

}


char* inputExpression(){

    printf("\nEnter a expression : ");
    
    char *expression = NULL;
    printf (" enter a string of any length, whitespace is OK: ");
    scanf ("%m[^\n]%*c", &expression);
    printf ("\n str: %s\n\n", expression);
    return expression;
}




void initStack(Stack* s){
    s -> top = NULL;
}
int isEmpty(Stack s){
    return s.top == NULL;
}

void displayS(Stack s){
   if(isEmpty(s))
   return ;

   NodeforStack* temp = s.top;
   while(temp){
    Node* go = temp -> data;
    while(go){
        printf("%d",go -> data);
        go = go -> next;
    }
    printf("\n");
    temp = temp -> up;
   }
}

void push(Stack* s){
    
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = 1;
    newnode -> next = NULL;
    Node* newnode1 = (Node*)malloc(sizeof(Node));
    newnode1 -> data = 2;
    newnode1 -> next = NULL;
    newnode -> next = newnode1;

    NodeforStack* abc = (NodeforStack*)malloc(sizeof(Node));
    abc -> data = newnode;
    abc -> up = NULL;

    if(isEmpty(*s))
    {
        s -> top = abc;
    }
    else
    {
        s -> top -> up = abc;
        s -> top = abc;
    }
     displayS(*s);
}

// Node* pop(Stack*);
// Node* top(Stack);