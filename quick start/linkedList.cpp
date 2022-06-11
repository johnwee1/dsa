// I got stuck for almost 2 hours because of pointers.. had to pass pointer to pointer then dereference
// when I did A = temp, i was merely changing the local pointer A rather than the actual pointer
// Avoid this problem by declaring struct Node globally
#include <iostream>

struct Node{
    int data;
    Node* link;
};


int insert(int a, Node** A); //Insertion at list end
void insert_beginning(int a, Node** A); //Insertion at beginning
void printlist(Node* A); //Traversal
   
int main(){
    Node* A = NULL; //Initializes a new pointer (beginning of a linked list)
    insert(5,&A);
    insert(4,&A);
    insert(3,&A);
    insert(2,&A);
	insert_beginning(23, &A);
	printlist(A);
    return 0;
}

int insert(int a, Node** A){
    Node* temp = new Node();
    temp->data = a;
    temp->link = NULL;
    if (*A==NULL) {
        *A = temp;
        std::cout << "A is null \n";
        return 0;}
    Node* temp1 = *A;
    while(temp1->link != NULL){
        temp1 = temp1->link;
    }
    temp1->link = temp;
    return 1;
}

void insert_beginning(int a, Node** A){
	Node* temp = new Node();
	temp -> data = a;
	temp->link = *A; //address of where A is pointing
	*A = temp;
}

void printlist(Node* A){
	Node* temp = A;
	/*
	while(temp->link != NULL){
		std::cout<<temp->data;
		temp = temp->link;
	}
	std::cout<<temp->data;
	//More efficient code below
	*/
	while(temp != NULL){
		std::cout<<temp->data;
		temp=temp->link;
	}
}

void insert_s(int a, Node** A, int n){
	Node* new_node = new Node();
	new_node->data = a;
	if (n==1){
		//special case where its inserting at first position
		insert_beginning(a, A);
	}
	
}


	
	
    