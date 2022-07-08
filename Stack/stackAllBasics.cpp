#include<iostream>
using namespace std;
class stu{
	public:     //in c++ it is public
	int size;
	int top;
	int s[5];
	stu(){
		size = 5;
		top = -1;
	}
	void push(int x){
		if(isFull()){
			cout<<"No spaace:"<<endl;
		}else{
			s[++top]  = x;
		}
	}
	int pop(){
		int x = -1;
		if(isEmpty()){
			cout<<"Stack is empty"<<endl;
			return 0;
		}
		else{
            int popVal = s[top];
            s[top] = 0;
            top--;
            return popVal;
	//	return 	x = s[top--];
		}
		return x;
	}
	bool isFull(){
		if(top == size-1){
			return true;
		}
		else{
			return false;
		}
	}
	bool isEmpty(){
		if(top == -1){
			return true;
		}
		else{
			return false;
		}
	}
	int count(){
		return (top+1);
	}
	int peek(int pos){
		if(isEmpty()){
			cout<<"Stack over flow "<<endl;
		}else{
			return s[pos];
		}
	}
	void change(int pos,int val){
		s[pos] = val;
		cout<<"val change at "<<pos<<endl;
	}
		void display(){
	cout<<"All values in the stack are:"<<endl;
			for(int i = top;i >= 0;i--){
				cout<<"vlaue is "<<s[i]<<endl;
			}
}
};
int main(){
	stu s1;
	int position,option,value;
	do{
	
	cout<<"Enter number on which you want operation: "<<endl;
	cout<<"0. Exit "<<endl;
	cout<<"1. push "<<endl;
	cout<<"2. pop "<<endl;
	cout<<"3. isEmpty "<<endl;
	cout<<"4. isFull "<<endl;
	cout<<"5. peek "<<endl;
	cout<<"6. count "<<endl;
	cout<<"7. change"<<endl;
	cout<<"8. display "<<endl;
	cout<<"9. check for palindrome "<<endl;
	cin>>option;
	switch(option){
		case 0:
			break;
			case 1:
				cout<<"Enter item you want to push"<<endl;
				cin>>value;
				s1.push(value);
				break;
			case 2:
				cout<<"pop value is"<<s1.pop()<<endl;
				break;
			case 3:
				if(s1.isEmpty()){
					cout<<"Stack is empty"<<endl;
				}else{
					cout<<"Stack is not empty"<<endl;
				}
				break;
				case 4:
				if(s1.isFull()){
					cout<<"Stack is Full"<<endl;
				}else{
					cout<<"Stack is not full"<<endl;
				}
				break;
				case 5 :
					cout<<"Enter position on which you wnat to peek "<<endl;
					cin>>position;
					cout<<"peek fuction called --peek value is "<<position<<"is "<<s1.peek(position)<<endl;
					break;
				case 6:
					cout<<"no of items in the stack "<<s1.count()<<endl;
					break;
				case 7:
					cout<<"Enter position on which you want to change "<<endl;
					cin>>position;
					cout<<endl;
					cout<<"Enter value you want to change "<<endl;
					cin>>value;
					s1.change(position,value);
					break;
				case 8:
					s1.display();
					break;
				
				default :
					cout<<"Enter proper opertaion "<<endl;
	}
}while(option != 0);
	return 0;
}

