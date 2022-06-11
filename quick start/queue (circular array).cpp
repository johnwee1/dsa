const int N = 10;
int A[N];
int front = -1;
int rear = -1;

bool isFull(){
	//Interpreting a circular array
	return (rear+1)%N == front;
	//If index of next element = front then the array is full.
	
	/*If current position is i, the next position is logically (i+1)%N. This is valid for all values except the case where i = N-1, in which case i+1 evaluates to zero, breaking the logic. A smart way of managing this is making it (i+N-1)%N such that the logic will only break if i= 1-N, which is negative and won't come up in code. */
}

bool isEmpty(){
	if (front==-1 && rear==-1){
		return true;
	}
	else return false;
}

void Enqueue(int x){
	if (isFull()) return;
	else if (isEmpty()){
		front = 0;
		rear = 0;
	}
	else{
		rear =  (rear+1)%N; //rear++ may cause issues
	}
	A[rear] = x;
}

void Dequeue(int x){
	if (isEmpty()){
		return;
	}
	else if (front==rear){
		front = -1;
		rear = -1;
	}
	else front = (front+1)%N; //increment in circular manner
}

int frontCounter(){
	if (front != -1){
		return A[front];
	}
}
//Use the idea of a circular array
