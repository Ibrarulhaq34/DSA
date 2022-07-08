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
	if(rear == size - 1){
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

void Enque(int x){
	if(isFull()){
		cout<<"Que us Full "<<endl;
	}
	else
	{
            int i;
            if (isEmpty())
            {
                front = rear = i = 0;
            }
            else
            {
                i = front;
                while (i <= rear && q[i] > x)
                {
                    i++;
                }
                int k = rear;
                while (k >= i)
                {
                    q[k + 1] = q[k];
                    k--;
                }
                rear++;
            }
            q[i] = x;
        }
    }

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
			 int i = front + 1;
                while (i <= rear)
                {
                    q[i - 1] = q[i];
                    i++;
                }
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
        cout << "Select number :\n"
             << "1. Enqueue\n"
             << "2. Dequeue\n"
             << "3. Display Queue\n"
             << "0. Exit\n";
        cin >> exit;

        switch (exit)
        {
        case 0:
            cout << "Exit...\n";
            break;
        case 1:
            cout << "\n";
            int element;
            cout << "Enter element to Enqueue: ";
            cin >> element;
            que.Enque(element);
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            cout << "Dequeued element is: " << que.Deque() << "\n";
            cout << "\n";
            break;
        case 3:
            que.display();
            break;
        default:
            cout << "Wrong input\n";
            break;
        }
    } while (exit != 0);
	return 0;
}
