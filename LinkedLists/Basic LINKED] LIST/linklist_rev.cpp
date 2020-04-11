#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* next;
	node(int d){
		data=d;
		next=NULL;

	}
};

void addatfront(node*&head,int d){
	if(head==NULL){
	head=new node(d);
	return;
	}
	node *n=new node(d);
	n->next=head;
	head=n;
	return;
}
void takeinput(node*&head){
	int d;
	cin>>d;
	while(d!=-1){
		addatfront(head,d);
		cin>>d;
	}
}
void print(node*head){
	while(head!=NULL){
		cout<<head->data<<"=>";
		head=head->next;
	}
	cout<<endl;
}
ostream& operator<<(ostream &os,node*head){
    print(head);
    return os;
}
istream& operator>>(istream &is,node*&head){
    takeinput(head);
    return is;
}
int length(node*head){
	int l=0;
	while(head!=NULL){
		l++;
		head=head->next;
	}
	return l;
}
void insertAtPosition(node*&head,int data,int p){
	if(p==0){
		addatfront(head,data);
		return;
	}
	else{
		node*temp=head;
		int cnt=1;
		while(cnt<=p-1){
			cnt++;
			temp=temp->next;
		}
		node*n =new node(data);
		n->next=temp->next;
		temp->next=n;
		return;
	}
}
void insertAttail(node*&head,int d){
	return insertAtPosition(head,d,length(head));
}
void deleteatfront(node*&head){
	node *temp=head;
	head=head->next;
	delete temp;
}
bool searchRecursive(node* head,int key){
	if(head==NULL){
		return false;
	}
	if(head->data==key){
		return true;
	}
	return searchRecursive(head->next,key);
}
bool searchIterative(node*head,int key){
	while(head!=NULL){
		if(head->data==key){
			return true;
		}
		head=head->next;
	}
	return false;
}
node* mid(node*head){
	node*slow=head;
	node*fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
node*merge(node*a,node*b){
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return NULL;
	}
	node* c;
	if(a->data<b->data){
		c=a;
		c->next=merge(a->next,b);

	}
	else{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}
node* mergeSort(node*head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	node* m=mid(head);
	node*a=head;
	node*b=m->next;
	m->next=NULL;
	a=mergeSort(a);
	b=mergeSort(b);
	return merge(a,b);
	
}
void reverseit(node*&head){
	node*c=head;
	node*p=NULL;
	node* n;
	while(c!=NULL){
		n=c->next;
		c->next=p;
		p=c;
		c=n;
	}
	head=p;
}
node* reverseREC(node*head){
	if(head==NULL||head->next==NULL){
		return head;
	}
	node* chotaHead=reverseREC(head->next);
	head->next->next=head;
	head->next=NULL;
	return chotaHead;

}

int main(){
	node*head;
	head=NULL;
// 	takeinput(head);
// 	print(head);
// 
	// node*head2;
	// head2=NULL;
	cin>>head;
	cout<<head;
	//cin>>head2;
	// cout<<head2;
	// int lengt=length(head);
	// cout<<lengt<<endl;
	// int d,p;
	// cin>>d>>p;
	// insertAtPosition(head,d,p);
	// cout<<head;
	// int data;
	// cin>>data;
	// insertAttail(head,data);
	// cout<<head;
// deleteatfront(head);
// cout<<head;
	// int k;
	// cin>>k;
	// if(searchIterative(head,k)){
	// 	cout<<"true";
	// }
	// else{
	// 	cout<<"false";
	// }
	// node* c=merge(head,head2);
	// cout<<c;
	// node*temp=mergeSort(head);
	// cout<<temp;
	// reverseit(head);
	// cout<<head;
head=reverseREC(head);
cout<<head;
}