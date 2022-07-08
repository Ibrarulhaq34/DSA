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
		cout<<"Que is empty"<<endl;
	}else{
		for(int i = front; i <= rear;i++){
			cout<<"Value at index "<<i<<" is "<<q[i]<<endl;
		}
	}
}
void EnqueRear(int x){
	if(isFull()){
		cout<<"No sppace "<<endl;
	}else{
		if(isEmpty()){
			front = rear = 0;
		} else if (rear == size - 1)
            {
                int i = front;
                while (i <= rear)
                {
                    q[i - 1] = q[i];
                    i++;
                }
                front--;
            }
		else{
			rear++;
		}
		q[rear] = x;
	}
}
void Enquefrt(int x){
	if(isFull()){
		cout<<"No sppace "<<endl;
	}else{
		if(isEmpty()){
			front = rear = 0;
		}
		 else if (front == 0)
            {
                int i = rear;
                while (i >= front)
                {
                    q[i + 1] = q[i];
                    i--;
                }
                rear++;
            }
		else{
				front--;
	
		}
		q[front] = x;
	}
}
int DequeFrt(){
	
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

	}
}
int DequeRear(){
	
	if(isEmpty()){
		cout<<"Empty "<<endl;
	  return -1;
	}
	else{
		
		int x = q[rear];
		if(front == rear){
			front = rear = -1;
		}else{
			rear--;
			
		}
		return x;
//	ind();
	}
}


};
int main(){
	int size;
    cout << "Enter size of queue: ";
    cin >> size;
    que que(size);
    int exit = 1;
    do
    {
        cout << "Enter number: \n"
             << "1. Enqueue start\n"
             << "2. Dequeue start\n"
             << "3. Display Queue\n"
             << "4. Enqueue end\n"
             << "5. Dequeue end\n"
             << "0. Exit\n";
        cin >> exit;

        switch (exit)
        {
        case 0:
            cout << "Exit...\n";
            break;
        case 1:
            cout << "\n";
            int num;
            cout << "Enter element for Enqueue: ";
            cin >> num;
            que.Enquefrt(num);
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            cout << "Dequeued element is: " << que.DequeFrt() << "\n";
            cout << "\n";
            break;
        case 3:
            que.display();
            break;
        case 4:
            cout << "\n";
            cout << "Enter element fot Enqueue: ";
            cin >> num;
            que.EnqueRear(num);
            cout << "\n";
            break;
        case 5:
            cout << "\n";
            cout << "Dequeued element is: " << que. DequeRear() << "\n";
            cout << "\n";
            break;
        default:
            cout << "Wrong input\n";
            break;
        }
    } while (exit != 0);
	return 0;
}
