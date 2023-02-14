void multiply(Node* first,Node* second){

    //84 
    //26
    //5 0 4
  //1 6 8 0
//  2 1 8 4
reverse(first);
reverse(second);
Node* firstNo = first;
Node* secondNo = second;

while(secondNo){

    int carry = 0;
    while(firstNo){
        int sum = secondNo -> data * secondNo -> data;
        
        firstNo = firstNo -> next;
    }
}
}