#include<iostream>
using namespace std;
struct stu{
	//insert at start,end and dispaly value.
	int id;
	float marks;
	stu *next = NULL;
};
	stu *first,*last;
void insert_end(){
	stu *curr;
	curr = new stu;
	cout<<"Enter student ID"<<endl;
	cin>>curr->id;
	if(first == NULL){
		first = last = curr;
		cout<<first<<endl;
	}
	else{
		last -> next = curr;
		cout<<last<<endl;
		last = curr;
		cout<<last<<endl;
	}
}
void insert_s(){
	stu *curr;
	curr = new stu;
	cout<<"Enter student ID at s"<<endl;
	cin>>curr->id;
	if(first == NULL){
		first = last = curr;
		cout<<first<<endl;
	}
	else{

    curr->next = first;
    first = curr;
	}
}
void display(){
	stu *p = first; 
	if(first == NULL){
		cout<<"No record to dispaly:"<<endl;
	}
	else
	{
		
		while(p->next != NULL){
			cout<<p->id<<endl;
			p = p ->next;
		}
		
	}
}
void search(){
	stu *p = first;
	while(p->id != 2 && p != NULL){
		p = p->next;
		if(p == NULL){
			cout<<"record not found "<<endl;
		}else if(p->id == 2){
			cout<<"record found"<<endl;
		}
	}
}
//reverse by recursion==last in first out.
void rec(stu *n){
	if(n != NULL){
		cout<<n->id<<endl;
		rec(n -> next);
		cout<<n->id<<endl;
}else{
	cout<<n<<endl;//it may be not written
}
	}
	//reverse by iteration
void iter(stu* n){
	stu *p = first;
	stu* k = last;
	stu* p2;
		stu* s = first;
	while(s != k){
	
	while(p != k){
		p2 = p;
		p = p->next;
	}
	cout<<p ->id<<endl;
	k = p2;
	p = s;
}//while(s != k);
}
void iterLastFirst(stu* n){
	stu *p = first;
	stu* k = last;
	stu* p2;
		stu* s = first;
	do{
	
	while(p != k){
		p2 = p;
		p = p->next;
	}
	cout<<p ->id<<s -> id<<endl;
	k = p2;
	p = s ->next;
	s = s ->next;
}while(s != k);
	}
	 bool checkPal(){
	stu *p = first;
	stu* k = last;
	stu* p2;
		stu* s = first;
	do{
	
	while(p != k){
		p2 = p;
		p = p->next;
	}
	if(first == NULL){
		return true;
	}
	else if(first ->next ==  NULL){
		return true;
	}
	else if(p ->id != s -> id)
	return false;
	//cout<<p ->id<<s -> id<<endl;
	k = p2;
	p = s ->next;
	s = s ->next;
}while(s != k);
return true;
	}
int main() {
		int x;
do{
	cout<<"Enter 1 for insert at end, and 2 to dispaly list, 3 for insert at start: "<<endl;
	cout<<"Enter 4 for search and 5 for recursion reverse: "<<endl;
    cout<<"Enter 6 for itteration reverse, Enter 7 for print last and first then second last and second:"<<endl;
    cout<<"Enter 8 to check linked list is palindrome:"<<endl;
	cin>>x;
	if(x == 1){
		insert_end();
	}
	else if(x == 2){
		display();
	}
		else if(x == 3){
		insert_s();
	}
		else if(x == 4){
		search();
	}else if(x == 5){
			stu *p = first; 
		rec(p);
	}
	else if(x == 6){
			stu *q = first; 
		iter(q);
	}
	else if(x == 7){
		stu *w = first; 
		iterLastFirst(w);
	}
	else if(x == 8){
		cout<<"Check for palindrome:  "<<checkPal()<<endl;
	}
	
}while(x != 0);
	return 0;
}

