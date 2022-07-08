#include<iostream>
using namespace std;
struct BST{
	int id;
	BST* right = NULL,*left = NULL;
};
BST* root = NULL;
void insert(int k){
	BST*curr = new BST;
	BST *p;
	BST *p2;
	curr->id = k;
	if(root == NULL){
		  root = curr;
	}
	else{
		p = root;
		while(p != NULL){
			p2 = p;
			if(k > p ->id){
				p = p->right;
			}else{
				p = p ->left;
			}
		
		}
			if(curr -> id> p2 ->id){
				p2->right = curr;
			}else{
				p2 ->left = curr;
			}
	}
}
void in_order(BST *p){
	if(p != NULL){
		in_order(p ->left);
		cout<<p->id<<endl;
		in_order(p->right);
	}
}
bool search(int key){
	BST* p = root;
	while((p->id != key ) && (p != NULL)){
		if(p -> id > key){
			p = p ->left;
		}

		else{
			p = p ->right;
		}
	}
	return p;	
}
//By recurcive
//void search(int key,BST *p){
//	if(p == NULL){
//		cout<<"Not found"<<endl;
//	}
//	else if(p ->id == key){
//		cout<<"Fount"<<endl;
//	}
//	else if(p ->id < key){
//		search(key,p->left);
//	}else{
//		search(key,p->right);
//	}
//}
void del(int key){
BST *p = root, *p1;
while(p != NULL && p->id != key){
	p1 = p;
	if(p->id < key){
		p = p->right;
	}
	else{
		p = p->left;
	}
}	
if( p == NULL){ 
cout<<"Key not found "<<endl;
}
else{
	if(p ->right == NULL && p->left == NULL){
		if( p = p1 ->left){
			p1 -> left = NULL;
			delete p;
		}
		else{
			p1 ->right = NULL;
			delete p;
		}
	}else if(p ->right == NULL || p->left== NULL){
		if(p1 -> left == p){
			if(p->right == NULL){
				p1->left = p ->left;
				delete p;
			}else{
				p1 ->left = p -> right;
				delete p;
			}
		}else if(p1 -> right == p){
			if(p->left == NULL){
				p1 -> right = p -> right;
				delete p;
			}else{
				p1 -> right = p->left;
				delete p;
			}
		}
	}
}
}
int main() {
		int x;
do{
	cout<<"Enter 1 for insert , and 2 to dispaly list, 3 for search, 4 for delete : "<<endl;
	cin>>x;
	if(x == 1){
		int y;
		cout<<"Enter num you want to insert"<<endl;
		cin>>y;
		insert(y);
	}	
	if(x == 2){
		in_order(root);
	}
	if(x == 3){
	int y;
	cout<<"Enter num you want to Search:"<<endl;
	cin>>y;
	//search(y,root);
		cout<<search(y)<<endl;
		}
	if(x == 4){
		int y;
		cout<<"Enter num you want to delete: "<<endl;
	cin>>y;
	del(y);
	}
}while(x != 0);
	return 0;
}

