#include <iostream>

using namespace std;
bool IsOperator(char C);
bool IsOperand(char C);
int HasHigherPrecedence(char operator1, char operator2);
char stack[50];
int top = -1;
int postfix[50];
int top_post = -1;
	bool isFull(){
		if(top == 50){
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
void push(char element)
{
    if (top < 20)
    {
        stack[++top] = element;
    }
    else
    {
        cout << "Stack is full\n";
    }
}

char pop()
{
    if (top > -1)
    {
        return stack[top--];
    }
    char a;
    cout << "Stack empty\n";
    return a;
}

void display()
{
    cout << "\n";
    if (top > -1)
    {
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << "\n";
        }
    }
    else
    {
        cout << "Stack is empty\n";
    }
    cout << "\n";
}
bool check_palindrome()
{
    string str;
    cout << "Enter string to check palindrome: ";
    cin >> str;
    top = -1;
    cout << "\n";
    for (int i = 0; i < str.length(); i++)
    {
        push(str[i]);
    }
    for (int i = 0; i < str.length(); i++)
    {
        if ((pop() != str[i]))
        {
            return false;
        }
    }
    return true;
}
void reverse(){
	 string str;
    cout << "Enter string you want to reverse: "<<endl;
    cin >> str;
    top = -1;
    for(int i = 0; i <str.length();i++){
    	push(str[i]);
	}
	for(int i = 0; i < str.length();i++){
		cout<<pop();
			}
}
bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool AreParanthesesBalanced(string exp)
{

	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(isEmpty() || !ArePair(stack[top],exp[i]))
	
				return false;
			else
				pop();
		}
	}
	return isEmpty() ? true:false;
}
string InfixToPostfix(string expression)
{

	string postfix = "";
	for(int i = 0;i< expression.length();i++) {
		if(expression[i] == ' ' || expression[i] == ',') continue; 

		 
		else if(IsOperator(expression[i])) 
		{
			while(!isEmpty() && stack[top] != '(' && HasHigherPrecedence(stack[top],expression[i]))
			{
				postfix+= stack[top];
				pop();
			}
			push(expression[i]);
		}
	
		else if(IsOperand(expression[i]))
		{
			postfix +=expression[i];
		}

		else if (expression[i] == '(') 
		{
			push(expression[i]);
		}

		else if(expression[i] == ')') 
		{
			while(!isEmpty() && stack[top] !=  '(') {
				postfix += stack[top];
				pop();
			}
			pop();
		}
	}

	while(!isEmpty()) {
		postfix += stack[top];
		pop();
	}

	return postfix;
}

bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}
 
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;
}
 
int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}

 
int GetOperatorWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}
int HasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
	
}
void push_int(int element)
{
    if (top_post < 20)
    {
        postfix[++top_post] = element;
    }
    else
    {
        cout << "Stack is full\n";
    }
}

char pop_int()
{
    if (top_post > -1)
    {
        return postfix[top_post--];
    }
    int a;
    cout << "Stack empty\n";
    return a;
}
int top_int()
{
    int c;
    if (top_post > -1)
    {
        return postfix[top_post];
    }
    return c;
}
double evaluate_postfix()
{
    string exp, out_exp = "";
    cout << "Enter expression: ";
    cin >> exp;
    top_post = -1;
    int a, b;
    cout << "\n";
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/')
        {
            push_int(exp[i] - 48);
        }
        else if (exp[i] == '+')
        {
            a = pop_int();
            b = pop_int();
            push_int(b + a);
        }
        else if (exp[i] == '-')
        {
            a = pop_int();
            b = pop_int();
            push_int(b - a);
        }
        else if (exp[i] == '*')
        {
            a = pop_int();
            b = pop_int();
            push_int(b * a);
        }
        else if (exp[i] == '/')
        {
            a = pop_int();
            b = pop_int();
            push_int(b / a);
        }
    }
    return top_int();
}
void D_TO_B(int n){
	int rem;
	while(n > 0){
		n = n / 2;
		rem = n % 2;
		push(rem);
	}
	while(!isEmpty()){
		int item;
		item = stack[top];
		pop();
		cout<<item;
			}
}
int main(){
	int exit = -1;
	do{
		cout << "Enter number to perform operation\n"
             << "1. Push\n"
             << "2. Pop\n"
             << "3. Display Stack\n"
             << "4. Check palindrome\n"
             << "5. Reverse string\n"
             << "6. Check balanced braces in a expression\n"
             << "7. Convert expression infix to postfix\n"
             << "8. Evaluate postfix expression\n"
             << "9. To convert decimal to binary \n"
             << "0. Exit\n";
        cin >> exit;
        switch(exit){
        	case 0:
        		cout << "Exit...\n";
            break;
        case 1:
            cout << "\n";
            char element;
            cout << "Enter element too add: ";
            cin >> element;
            push(element);
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            char poped;
            poped = pop();
            cout << "Char poped is: " << poped << "\n";
            cout << "\n";
            break;
        case 3:
            display();
            break;
        case 4:
        cout << "\n";
        if (check_palindrome())
            {
                cout << "String is palindrome\n";
            }
            else
            {
                cout << "Not a palindrome\n";
            }
            cout << "\n";
            break;
            case 5:
            	reverse();
            	break;
            case 6:{
            	string expression;
           	cout<<"Enter an expression:  "; 
             	cin>>expression;
           	if(AreParanthesesBalanced(expression)){
         	cout<<"Balanced\n";
              	}
           	else{
			cout<<"Not Balanced\n";
				break;
			}
		}
	case 7:{
		string expression; 
	cout<<"Enter Infix Expression \n";

cin>>expression;
	string postfix = InfixToPostfix(expression);
	cout<<"Output = "<<postfix<<"\n";
		break;
	}
	case 8:{
		cout<<evaluate_postfix()<<endl;
		break;
	}
	case 9:{
		int num;
		cout<<"Enter number you want to convert to binary :"<<endl;
		cin>>num;
		D_TO_B(num);
		break;
	}

  		}
	}while(exit != 0);
		return 0;
}


