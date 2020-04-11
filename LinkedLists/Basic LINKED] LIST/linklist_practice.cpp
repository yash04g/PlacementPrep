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
void addAtFront(node*&head,int d){
if(head==NULL){
	head=new node(d);
	return;
}
node* n=new node(d);
n->next=head;
head=n;
return ;

}
void takeInput(node* &head){
	int d;
	cin>>d;
	while(d!=-1){
		addAtFront(head,d);
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
int length(node*head){
	int cnt=0;
     while(head!=NULL){
     	cnt++;
     	head=head->next;
     }
     return cnt;
}
int mid(node*head){
	node*slow=head;
	node*fast=head;
	while(slow!=NULL&&fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow->data;
}
void reverse(node*&head){
	node* c=head;
	node* p=NULL;
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
	node* rest=reverseREC(head->next);
	head->next->next=head;
	head->next=NULL;
	return rest;
}
void deleteAtFront(node*head){
	node* temp=head;
	head=head->next;
	delete temp;
}
void insertAtPosition(node*head,int p,int d){
	if(p==0){
		addAtFront(head,d);
	}
	node*temp=head;
	int cnt=1;
	while(cnt<=p-1){
       cnt++;
       temp=temp->next;
	}
	node* n=new node(d);
	n->next=temp->next;
	temp->next=n;
	return;
}
node* reverseK(node*head,int k){
	node *c=head;
	node* n=NULL;
	node* p=NULL;
	int cnt=0;
	while(c!=NULL&&cnt<k){
		n=c->next;
		c->next=p;
		p=c;
		c=n;
		cnt++;

	}
	if(n!=NULL){
		head->next=reverseK(n,k);
	}
	return p;
}
void FromEnd(node* head,int n){
	node*fast=NULL;
	node*slow=NULL;
	int cnt=0;
	if(head!=NULL){
		while(cnt<n){
			if(fast==NULL){ 
				cout<<"not"<<endl;
			return;
		}
			fast=fast->next;
			cnt++;
		}
		while(fast!=NULL){
      fast=fast->next;
      slow=slow->next;
		}

	}
	cout<<slow->data<<endl;
	return;
}
bool compareList(node* list1,node* list2){
	node* temp1=list1;
	node* temp2=list2;
	while(temp1&&temp2){
		if(temp1->data==temp2->data){
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else{
			return 0;
		}
	}
	if(temp1==NULL&&temp2==NULL){
		return 1;
	}
	return 0;
}
int main(){
node* root;
root=NULL;
takeInput(root);
print(root);
print(root);

//cout<<mid(root)<<endl;
// reverse(root);
// print(root);
// node*newNode=reverseK(root,3);
// print(newNode);
// int k;
// cin>>k;
// cout<<FromEnd(root,k);
node* reverse1=reverseREC(root);
print(reverse1);
print(root);
if(compareList(root,reverse1)==true){
	cout<<" isPalindrome"<<endl;
}
else{
	cout<<"nopalindrome"<<endl;
}
}