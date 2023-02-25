#include "binaryCalculator.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** convertCharArray(char *expression,int *n){
    
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
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')'){
            
            ans[k] = (char*)malloc(sizeof(str));
            int ct = 0;
            for(int i = 0 ; str[i] != '\0';i++){
                ct++;
            }
            // printf("Count : %d",ct);
            // printf("%s",str);
            strcpy(ans[k++],str);
            a = 0;
            space = 1;
            str = realloc(str, space); // allocate new space
            for(int i = 0 ;  str[i] != '\0' ;i++){
                str[i] = '\0';
            }

            char operator[1] ;
            operator[0] = ch;
            ans[k] = (char*)malloc(sizeof(1)); 
            strcpy(ans[k++],operator);

        }
        else{
            str[a++] = (char)(ch);//-312+311
            space++;              
            str = realloc(str, space); // allocate new space
        }
     }
            ans[k] = (char*)malloc(sizeof(str)); 
            strcpy(ans[k++],str);

    for(int i = 0 ; i < count1 ; i++){
        // printf("%s\t",ans[i]);
    }
    *n = count1;
      return ans;

}
int precendence(char ch){  
    if(ch == '(')
    return 0;
   
    if(ch == '+' || ch == '-')
    return 1;

     if(ch == '*' || ch == '/')
    return 2;

    return 0;
}

int isNumber(char *ch){
return (strcmp("+",ch) && strcmp("-",ch) && strcmp("/",ch) && strcmp("*",ch) && strcmp("(",ch) && strcmp(")",ch)  );
}

char** convertToPostfix(char **expression,int n){
     charStack s;
    //  initStackC(&s,n);
     initStackC(&s,n+1);

     char **ans = (char**)malloc(sizeof(char*)*n);

// //priority () * / + - 
      int k = 0;
    //   printf("\nCOnversion\n");
    for(int i = 0 ; i <= n ; i++){
        char *ch = expression[i];
    //    printf("%s\n",ch);
    
         if(isNumber(ch))
         {
            ans[k] = (char*)malloc(sizeof(ch));
            strcpy(ans[k++],ch);
            // printf("%s",ans[k-1]);
         }
         else  if(!strcmp("(",ch))
           {
            // printf("\nCheck\n");
                pushC(&s,'(');   
         }
           else if(!strcmp(")",ch))
            {
                 while( topC(s) !=  ' ' && topC(s) != '(')
                 {
                char temp = topC(s);
                char temp1[1] ;
                 temp1[0] = temp;
                 ans[k] = (char*)malloc(sizeof(temp));
                strcpy(ans[k++],temp1);
                popC(&s);
              }
               popC(&s);
            }
            else{
            char abc = ch[0];
            // printf("%c\t",abc);
                while(topC(s) != ' ' &&  precendence(topC(s)) >= precendence(abc)){
                    ans[k] = (char*)malloc(sizeof(topC(s)));
                    char temp[1] ;
                    temp[0] = topC(s);
                    strcpy(ans[k++],temp);
                    popC(&s);
                }
                pushC(&s,abc);
    }
   
}
 while(!isEmptyC(s)){
        char ch = topC(s);
        // printf("\n\n%c",ch);
        // printf("%d",k);
        ans[k] = (char*)malloc(sizeof(char));
        char temp[1] ;
        temp[0] = topC(s);
        strcpy(ans[k++],temp);
        popC(&s);
    }
// printf("\nPrinting Postfix :\n");
//  for(int i = 0 ; i < n ;i++){
                // printf("Yes");
        // printf("%s\n",ans[i]);
        // printf("\n");
    // }
    return ans;


}

 Node* postfixEvaluationWithCreatingLinkedLists(char **ans,int n){
    
    Stack s;
    initStack(&s);

    List result;
    initList(&result);
    // printf("\nPrinting Postfix Evaluation\n");
    for(int i = 0 ; i <= n; i++){
         printf("%s\t",ans[i]);
    }
    for(int i = 0 ; i <= n; i++){
       
        char *ch = ans[i];
        
        if(isNumber(ch)){
            
            List l1;
            initList(&l1);
            int ct = 0;
            for(int i = 0 ; ch[i] != '\0'; i++){
                ct++;
            }
            // printf("Count %d ",ct);
            for(int i = 0 ; i < ct ;i++){
                int num = ch[i] - '0';
                append(&l1,num);
            }

            // display(l1);
            push(&s,l1);
            // printf("\nsize = %d\n",getSizeOfStack(s));
        }
        else 
        {
            // Node* b = getTop(s) ;
            // pop(&s);
            // Node* a = getTop(s);
            // pop(&s);
            Node* b = pop(&s);
            Node* a = pop(&s);
    printf("\n Sign (%c) (%c)\n", a -> sign,b -> sign);
            //  display(b);
            //  display(a);
            //  display(c);


            if(!strcmp("*",ch)){
                // if(a -> sign == '+' && b -> sign == '+'){
                //     result -> sign = '+';
                // }else if(a -> sign == '-' && b -> sign == '+' || a -> sign == '+' && b -> sign == '-')
                // {
                //     result -> sign = '-';
                // }
                // else{
                //     result -> sign = '+';
                // }
                result = multiply(a,b); 
                // display(result);

            }
            else if(!strcmp("/",ch)){
               result =  divideTwoLinkedLists(a,b);
            }
             else if(!strcmp("+",ch)){
                 if((a -> sign == '+' && b -> sign == '+')  ){     
                    result -> sign = '+';
                    result = addTwoLinkedLists(a,b);
                 }               
                else if((a -> sign == '-' && b -> sign == '+') || (a -> sign == '+' && b -> sign == '-'))
                {
                    result = subtractTwoLinkedLists(a,b);
                }
                else{
                    result = addTwoLinkedLists(a,b);
                    result -> sign = '-';
                }
                // printf("Sign %c" , result -> sign);
            }
            else if(!strcmp("-",ch)){
                //311-312
                if(a -> sign == '+' && b -> sign == '+'){
                    printf("Ye ki re");     
                    result = subtractTwoLinkedLists(a,b);
                 }               
                else if((a -> sign == '-' && b -> sign == '+') || (a -> sign == '+' && b -> sign == '-'))
                {
                    //-10 - 12
                    //10 - - 12
                    if( a -> sign == '-'){
                        result = addTwoLinkedLists(a,b);
                        result -> sign = '-';
                    }
                    else{
                        result = addTwoLinkedLists(a,b);
                        result -> sign = '+';
                    }
                }
                else{
                    result = addTwoLinkedLists(a,b);
                    result -> sign = '-';
                }
                // result =  subtractTwoLinkedLists(a,b);
            }
                push(&s,result);
        }
    }
    display(result);
    return result;

}


void controlEverything(){
    // char* expression = inputExpression();
        // convertCharArray(expression);
        int n = 0;
    char **temp = convertCharArray("311-312",&n);

    printf("\n");
    // for(int i = 0 ; i <= n-1 ;i++){
        // printf("%s\t",temp[i]);
    // }
    char **ans =  convertToPostfix(temp,n-1);
//    for(int i = 0 ; i <= n-1 ;i++){
//                 // printf("Yes");
        // printf("%s\n",ans[i]);
    // }
// 
    Node* storageOfAnswer = postfixEvaluationWithCreatingLinkedLists(ans,n-1);

        // printf("Answer\n");
    // display(storageOfAnswer);
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
        // printf("%d",go -> data);
        go = go -> next;
    }
    printf("\n");
    temp = temp -> up;
   }
}

Node* getTop(Stack s){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = -1;
    newnode -> next = NULL;
    if(!s.top)
    return newnode;
    return s.top -> data;
}


void push(Stack* s,Node* data){
    

    NodeforStack* newnode = (NodeforStack*)malloc(sizeof(NodeforStack));
    newnode -> data = data;
    newnode -> up = NULL;

    if(isEmpty(*s))
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

Node* pop(Stack *s){
    if(isEmpty(*s)){
        return NULL;
    }
    NodeforStack* deleteNode = s -> top;
    
    Node* actualList = deleteNode -> data;
    // free(deleteNode);
    // display(actualList);
    s -> top = s -> top -> up;
    return actualList;
}
// Node* top(Stack);

int getSizeOfStack(Stack s){
    if(isEmpty(s))
    return 0;
    int ct = 0;
    NodeforStack* temp = s.top;
    while(temp){
        ct++;
        temp = temp -> up;
    }
    return ct;
}