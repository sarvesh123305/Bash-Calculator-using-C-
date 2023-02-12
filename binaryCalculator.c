#include "binaryCalculator.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void convertCharArray(char *expression){
    
    int count1 = 0 ;
    int flag = 1;
    char ch;
    for(int i = 0 ; expression[i] != '\0' ;i++){
         ch = expression[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'||ch == '(' || ch == ')'){
            
            if(flag){
                count1 += 2;
            }
            else{
                count1++;
            }
            flag = 0;
        }
        else{
            flag = 1;
        }


    }
    if(ch != '(' || ch != ')')
    ++count1;

    printf("\n%d\n",count1);
    char **ans = (char**)malloc(sizeof(char*)*count1)  ;
    int space = 0;
    char *str = (char*)malloc(sizeof(char)*space) ;
    int k = 0, a = 0;
    strcpy(str,"");
     for(int i = 0 ; expression[i] != '\0' ; i++){
        char ch = expression[i];
        // if(ch == ' ')
        // continue;
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')'){
            ans[k] = (char*)malloc(sizeof(str));
            strcpy(ans[k++],str);
            a = 0;
            space = 1;
            str = realloc(str, space); // allocate new space
            strcpy(str," ");

        
            char operator[1] ;
            operator[0] = ch;
            ans[k] = (char*)malloc(sizeof(1)); 
            strcpy(ans[k++],operator);
            

        }
        else{
            str[a++] = (char)(ch);
            space++;              
            str = realloc(str, space); // allocate new space
        }
     }
            ans[k] = (char*)malloc(sizeof(str)); 
            strcpy(ans[k++],str);

    for(int i = 0 ; i < count1 ; i++){
        printf("%s\t",ans[i]);
    }
      
}

void convertToPostfix(char *expression,int n){
         Stack s;
     initStack(&s,n);

    static char ans[50];
//priority () * / + - 
   int k = 0;
    for(int i = 0 ; expression[i] != '\0' ; i++){
        char ch = expression[i];
       
        if(isAlphabetOrNumber(ch)){
                 ans[k++] = expression[i];
        }
        else  if(ch == '(' )
            {
                push(&s,ch);
            }
        else if(ch == ')'){
             while( top(s) != ' ' && top(s) != '(')
            {
                 ans[k++] = top(s);
                pop(&s);
             }
             pop(&s);
        }else{
            char ch = expression[i];

                while(top(s) != ' ' &&  precendence(top(s)) >= precendence(ch)){
                 ans[k++] = top(s);
                    pop(&s);
                }
                
                push(&s,ch);
        }

    }
    
    while(!isEmpty(s)){
        char ch = top(s);
         ans[k++] = ch;

        pop(&s);
    }
}
 

void controlEverything(){
    // char* expression = inputExpression();
        // convertCharArray(expression);
    //  convertCharArray("2+1*1");
    //  convertToPostfix(expression,n);

}


char* inputExpression(){

    printf("\nEnter a expression : ");
    
    char *expression = NULL;
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