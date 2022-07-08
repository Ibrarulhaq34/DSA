#include<iostream>
using namespace std;
class sta{
	public:
	int size, top;
	int *s;
		sta()
		{
			size=5;
			s=new int[size];
			top=-1;
		}
	sta(int s1)
	{
		size=s1;
		s=new int[size];
		top=-1;
	}
	void push(int x)	
		{
			if(is_full())
			{
				cout<<"\n No space ";
			}
			else
			{
				s[++top]=x;
				cout<<"\n Value pushed is: "<<s[top];
				
			}
		}
		
		
	int pop()
	{
		int x=-1;
		if(is_empty())
		{
			cout<<"\n Stack is empty";
		}
		else
		{
			x=s[top--];
		}
		return x;
	}
	
	bool is_full()
	{
		if(top==size-1)
			return true;
		else
			return false;
	}
	
	bool is_empty()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	void display()
	{
		cout<<"\n In Display method";
		if(top==-1)
			cout<<"\n No element to dispaly";
		else
			for(int i=top; i>=0; i--){
			
				cout<<"\n Value at index "<<i<<" is: "<<s[i];
	}}
};

int main()
{
//	int s[10];
     sta s1, s2(7);
//cout<<"\n Enter string to reverse: ";
//gets(s);
//cout<<"\n Entered string is: ";
//puts(s);

s1.push(3);
s1.push(4);
s1.push(5);

 s1.display();
cout<<"\n Poped value is: "<<s1.pop();	
cout<<"\n Poped value is: "<<s1.pop();	
 s1.display();

cout<<"\n Poped value is: "<<s1.pop();	

cout<<"\n Poped value is: "<<s1.pop();	

s2.push(3);
s2.push(4);
s2.push(5);

 s2.display();
cout<<"\n Poped value is: "<<s2.pop();	
cout<<"\n Poped value is: "<<s2.pop();	
 s2.display();


}

