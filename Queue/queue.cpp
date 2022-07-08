#include<iostream>
using namespace std;
class que{
     public:
	 int size;
	 int *q;
	 int front;
	 int rear; 
	 que(){
	 	size = 10;
	 	q = new int[size];
	 	front = -1;
	 	rear = -1;
	 }	 
	  que(int x){
	 	size = x;
	 	q = new int[size];
	 	front = -1;
	 	rear = -1;
	 }	 
bool isEmpty(){
	if(rear == -1){
		return true;
	}else{
		return false;
	}
}
bool isFull(){
	if(rear == size-1){
		return true;
	}else{
		return false;
	}
}
void display(){
	if(isEmpty()){
		cout<<"Qrea is empty"<<endl;
	}else{
		for(int i = front; i <= rear;i++){
			cout<<"Value at index "<<i<<" is "<<q[i]<<endl;
		}
	}
}
void Enque(int x){
	if(isFull()){
		cout<<"No sppace "<<endl;
	}else{
		if(isEmpty()){
			front = rear = 0;
		}else{
			rear++;
		}
		q[rear] = x;
	}
}
//void ind(){
 //shift left
//	for(int i = front ; i <= rear-1;i++){
//		q[i] = q[i-1];
//	}
//}
int Deque(){
	
	if(isEmpty()){
		cout<<"Empty "<<endl;
	  return -1;
	}
	else{
		
		int x = q[front];
		if(front == rear){
			front = rear = -1;
		}else{
			front++;
			
		}
		return x;
//	ind();
	}
}
};
int main(){
	que q1;
	que q2(5);
	que q3(10);
	q1.Enque(4);
	q1.Enque(5);
	q2.Enque(7);
	q2.Enque(8);
	q2.Enque(3);
	q2.Enque(9);
	q3.Enque(9);
//	int x = q2.Deque();
	//cout<<"Deque element is: "<< q2.Deque()<<endl;
	cout<<"Deque element is: "<< q2.Deque()<<endl;
		cout<<"Deque element is: "<< q2.Deque()<<endl;
	q2.display();
	return 0;
}
