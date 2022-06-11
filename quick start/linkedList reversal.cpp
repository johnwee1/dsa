#include <iostream>
/* delete linked node, and reversing a linked list */
struct Node{
  int data;
  Node* next;
};

Node* head;

void insert(int data){
  /*straightforward implementation */
  Node* temp = new Node();
  temp->data = data;
  temp->next = NULL;
  Node* temp1 = head;
  while(temp1->next != NULL){
    temp1 = temp1->next;
  }
  temp1->next = temp;
  return;
}

void print(){
  Node* temp = head;
  while(temp!=NULL){
    std::cout<<temp->data;
    temp = temp->next;
  }
  std::cout<< "\n";
  return;
}

void delete_entry(int n){
  Node* temp1 = head;
  if (n==1){
    head = temp1->next;
    free(temp1);
    return;
  }
  for(int i=0;i<n-2;i++){
    temp1 = temp1->next;
  }
  Node* temp2 = temp1->next; //points to 3 originally
  temp1->next = temp2->next;
  free(temp2); //delete temp2
}

void reverseList(){
  Node* counter = head;
  Node* counterBehind = NULL;
  Node* counterFront = NULL;
  //Node* counterFront = head->next;  No real need to initialize it outside the loop - keep it self contained
  while(counter != NULL){
    counterFront = counter->next; //counternext still points to next node. counterfront increments once
    counter->next = counterBehind; //counternext points back now
    counterBehind = counter; //counterbehind now increments once
    counter = counterFront; //counter now catches up to the counterfront (increments by one)
    //Edge case = now counter becomes null!!!!!!!!!!!!!!!!
  }
  /*
  Takeaway: If you find a statement repeated once outside of the loop, is it possible to subsume eveything in the loop? 
  PAY ATTENTION TO HOW YOUR LOOP TERMINATES! Can you find similar lines of code in your program that hints at a possibly inefficient termination?
  */
  head = counterBehind;
}

int main(){
  head = NULL;
  Node* temp = new Node();
  temp->data = 2;
  temp->next = NULL;
  head = temp;
  insert(3);
  insert(4); // insert 2, 3, 4, 5
  print();
  /*int pos;
  std::cin >> pos;
  delete_entry(pos);
  print();
  std::cout<<"Above is deleted, below is reversed list\n"; */
  reverseList();
  print();
}