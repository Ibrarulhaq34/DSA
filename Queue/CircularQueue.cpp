#include<iostream>
using namespace std;
class PizzaHut{
     public:
	 int MAX;
	 int *q;
	 int front;
	 int rear; 
	 PizzaHut(){
	 	MAX = 10;
	 	q = new int[MAX];
	 	front = -1;
	 	rear = -1;
	 }	 
	  PizzaHut(int x){
	 	MAX = x;
	 	q = new int[MAX];
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
	if((rear+1) % MAX == front){
		return true;
	}else{
		return false;
	}
}
void display(){
	if(isEmpty()){
		cout<<"Cafe is Empty.No orders.:"<<endl;
	}else{
		for(int i = front; i <= rear;i++){
			cout<<"Order number: "<<i<<" is "<<q[i]<<endl;
		}
	}
}
void addOrder(int x){
         
	if(isFull()){
		cout<<"Limit out, Please wait. "<<endl;
	}else{
		if(isEmpty()){
			front = rear = 0;
		}else{
	
		rear = (rear+1) % MAX;
		}
	 q[rear] = x;
	}
}

int serveOrder(){
	
	if(isEmpty()){
		cout<<" No Orders in Cafe."<<endl;
	  return -1;
	}
	else{
		
		int x = q[front];
		if(front == rear){
			front = rear = -1;
		}else{
			front = (front + 1) % MAX;
			
		}
		return x;

	}
	
}
};

int main(){

int ch;
	PizzaHut q1;
	PizzaHut q2(5);
	PizzaHut q3(10);
	do{
	
	cout<<"-----------------"<<endl;
	cout<<"Welcome to Meraj Pizza Hutt"<<endl;
		cout<<"\n****Menu*****\n";
		cout<<"1. Accept order\n";
		cout<<"2. Serve order\n";
		cout<<"3. Display orders\n";
		cout<<"4. Exit";

		cout<<"\nChoice: ";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"-----------------";
			   
		cout<<"\n****Menu*****\n";
		cout<<"1. Small pizza \n";
		cout<<"2. Medium pizza\n";
		cout<<"3. Large pizza\n";
		cin>>ch;
		if(ch ==1){
			q2.addOrder(1);
		}else if(ch == 2){
			q2.addOrder(2);
		}else{
			q2.addOrder(3);
		}
		break;
		case 2:
			cout<<"served order is: "<<q2.serveOrder()<<endl;
			break;
		case 3:
			q2.display();
			break;
		}
	}while(ch != 4);
	cout<<"\nThank You.Keep Visiting.";
	
	return 0;
}
