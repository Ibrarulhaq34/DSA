#include<iostream>
using namespace std;
struct stu{
	//insert at start,end and dispaly value.
	int id;
	float marks;
	stu *next = NULL;
	stu *per = NULL;
};
	stu *first = NULL;
	stu *last = NULL;
	void insert_end(){
		stu* curr = new stu;
		cout<<"Enter student ID"<<endl;
     	cin>>curr->id;
		if(first == NULL){
			first = last = curr;
		}
		else{
			last -> next = curr;
			curr -> per = last;
			last = curr;
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
	void insert_s(){
			stu* curr = new stu;
	    	cout<<"Enter student ID at s"<<endl;
	        cin>>curr->id;
		if(first == NULL){
			first = last = curr;
		}
		else{
			curr -> next = first;
			first -> per = curr;
			first = curr;
		}
	}
	void reverse(){
		stu* k = last;
		while(k ->per != NULL){
			k = k ->per;	
		cout<<k ->id<<endl;
		}
	}
	void search(){
	stu *p = first;
	stu* curr = new stu();
	cout<<"Enter key you want to search"<<endl;
	cin>>curr -> id;
	while(p->id != curr->id && p != NULL){//campare pointer with pointer
		p = p->next;
		if(p == NULL){
			cout<<"record not found "<<endl;
		}else if(p -> id == curr -> id){
			cout<<"found"<<endl;
		}
	}
}
void insert_after(){
	//curr is for after which value is inserted, curr1 is value which is inserted
	stu *p = first;
	stu* curr = new stu();
	cout<<"Enter key after you want to insert:"<<endl;
	cin>>curr -> id;
	//key to insert
	stu* curr1 = new stu();
	cout<<"Enter key you want to insert:"<<endl;
	cin>>curr1 -> id;
	while(p->id != curr->id && p != NULL){
		p = p->next;
		if(p == NULL){
			cout<<"record not found "<<endl;
		}else if(p -> id == curr -> id){
			curr1 ->next = p ->next;
			curr1->per = p;
			p -> next = curr1;
			curr1->next->per=curr1;
		//	cout<<"found"<<endl;
		}
	}
}
void delete_first(){
	stu*p = first;
	first = first -> next;
	first->per = NULL;
	delete p;
}
void delete_last(){
	stu*p =last;
	last = last ->per;
	last->next = NULL;
	delete p;
}
void delete_any(){
	stu*p = first;
	stu* curr = new stu();
	stu*p1;
	cout<<"Enter after which you want to delete:"<<endl;
	cin>>curr->id;
	while(p->id != curr->id && p != NULL){
		p1 = p;
		p = p ->next;
		if(p == NULL){
			cout<<"Record not found"<<endl;
		}else if(curr -> id == p-> id){
			p1 -> next = p->next;
			p->next -> per = p1;
		}
	}
}
int main() {
		int x;
do{
	cout<<"Enter 1 for insert at end, and 2 to dispaly list, 3 for insert at start: "<<endl;
	cout<<"Enter 4 for reverse and 5 for search: "<<endl;
    cout<<"Enter 6 for insert after, Enter 7 for delete first::"<<endl;
    cout<<"Enter 8 for delete at any value:"<<endl;
    cout<<"Enter 0 for exit:"<<endl;
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
		reverse();
	}
		else if(x == 5){
		search();
	}
	else if(x == 6){
		insert_after();
	}
	else if(x == 7){
		delete_first();
	}
	else if(x == 8){
		delete_last();
	}
	else if(x == 9){
		delete_any();
	}

	
}while(x != 0);
cout<<"Exit";
	return 0;
}
