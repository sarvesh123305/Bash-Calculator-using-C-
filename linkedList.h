typedef struct Node{
    int data;
    struct Node *next;
}Node;

typedef Node* List;

void initList(List* l);
void append(List* head,int data);
void reverse(List *L1);
void display(List head);





