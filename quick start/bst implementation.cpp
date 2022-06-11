#include <iostream>
#include <queue> //for level order traversal

struct Node{
	int data;
	Node* left;
	Node* right;
	int height;
};


Node* findMax(Node* root){
	if (root->right!=NULL) return findMax(root->right);
	else return root;
}
//recursive sol

Node* deleteNode(Node* root, int a){
//should return pointer to root because the root may change after deletion and that whatever is passed is passed by value (local)
	if (root==NULL) return root;
	if (a>root->data){
		root->right = deleteNode(root->right, a);
	}
	else if (a<root->data){
		root->left = deleteNode(root->left, a);
	}
	return root;
	if (root->left==NULL && root->right==NULL){//nochild
		delete root; //deletes the root node
		root = NULL;
		return root; //makes sure that dangling pointer is deleted
	}
	else if (root->left==NULL){ //Case for 1 child
		Node* temp = root;
		delete root; //deletes the intermediate node
		return temp->right; //returns pointer to the next node so that the tree edges can be "repaired"
							//refer to case of 2 children, where function returns a null pointer
	}
	else if (root->right==NULL){
		Node* temp = root;
		delete root;
		return temp->left;
	}
	else{//for case of 2 children, need to find min in right subtree or max in left subtree
		Node* temp = findMax(root->left);//Returns ptr to max at bottom of the tree
		root->data = temp->data;//Overwrites the data of the bottom to the "deleted node"
		root->left = deleteNode(root->left,temp->data); //recursively delete the bottom pointer
		return root; 
	}
}


Node* findMin(Node* root){
	Node* temp = root;
	while(temp->left != NULL) temp=temp->left;
	return temp;
}

bool search_node(Node* root, int data){
	if (root == NULL) return false;
	if (root->data == data) return true;
	else if (data>root->data) return search_node(root->right, data);
	else return search_node(root->left, data);
}

Node* getNewNode(int a){
	Node* newNode = new Node();
	newNode->data = a;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

//Recursive findHeight function
int findHeight(Node* root){
	if (root == NULL) return -1;
	return std::max(findHeight(root->left),findHeight(root->right)) + 1;
}

Node* insert(Node* root, int a){
	//Insert operation essentially means linking pointers
	if (root==NULL){ //Base case
		root = getNewNode(a);
		return root;
	}
	else if (a <= root->data){
		root->left = insert(root->left, a);
	}
	else root->right = insert(root->right, a);
	return root;
}

//Extremely crude function to level order traverse and print tree inline
void printTree(Node* root){
	std::queue<Node*> pq;
	Node* temp = new Node;
	temp->data = 0;
	temp->left = temp->right = NULL;
	pq.push(root);
	while(!pq.empty()){
		std::cout << pq.front()->data << " ";
		if (pq.front()->left != NULL) pq.push(pq.front()->left);
		if (pq.front()->right != NULL) pq.push(pq.front()->right);
		if (pq.front()->left != NULL && pq.front()->right==NULL) pq.push(temp);
		if (pq.front()->right != NULL && pq.front()->left==NULL) pq.push(temp);
		pq.pop();
	}
}

int main(){
	Node* root = NULL;
	root = insert(root, 13);
	root = insert(root, 12);
	root = insert(root, 14);
	root = insert(root, 8);
	root = insert(root, 3);
	printTree(root);
	return 0;
}