#include<iostream>
using namespace std;
class Node{
public:
	int data ;
	Node *next;
		
	Node(int data){
		this ->data = data;
		next=NULL;
	}
};
// Take input using Adda at front function
void Addatfront(Node * &head, int data){
if(head==NULL){
	head = new Node(data);
	return;
}
Node *n= new Node(data);
n->next=head;
head=n;
return;
}
void takeinput(Node *&head){
	int data;
	cin>>data;
	while(data!=-1){
		Addatfront(head,data);
		cin>>data;
	} }
//Take Input without add at front
Node* takeInput(){
	int data;
	cin>>data;
	Node* head = NULL;
	while(data!=-1){
		Node* newNode = new Node(data);
		if(head==NULL){
			head=newNode;
		}
		else{
			Node *temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newNode;
		}
		cin>>data;
	}
	return head;
}

void print(Node *head) {
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
int length(Node *head){
int count=0;
  while(head!=NULL){
  	count++;
    head=head->next;
  }
  return count;
}
int lengthRecursive(Node*head){
	if (head==NULL){
		return 0;
	}
	return 1+lengthRecursive(head->next);
}
void printIthNode(Node *head, int i){
	Node* temp=head;
	if(i>length(head)){
    return;
  }
  int a=0;
  while(a<=i){
  	temp=temp->next;
  	a++;
  }
  cout<<temp->data;
}
Node * insertNode(Node* head, int i, int data){
	Node* temp=head;
	int count=0;
	Node* newNode= new Node(data);
	if(i==0){
		newNode->next=head;
		head=newNode;
		return head;
	}
	while(temp!=NULL && count<i-1){ //temp!=NULL handles the case when i>lenth of Linked List
		temp=temp->next;
		++count;
	}
	if(temp!=NULL){
		Node* a=temp->next;
		temp->next=newNode;
		newNode->next=a;
	}
	return head;
}
Node* deleteNode(Node *head, int i) {
  Node* temp=head;
  if(i==0){
    Node *a=temp;
    Node *b=a->next;
    head=b;
    delete a;
    return head;
  }
  int count=0;
  while(temp!=NULL && count<i-1 && temp->next!=NULL){
    temp=temp->next;
    ++count;
  }
  if(temp!=NULL && temp->next!=NULL){
    Node* c=temp->next;
    Node *d=c->next;
    temp->next=d;
    delete c;
  }
  return head;
}
int indexOfNIter(Node *head, int n) {
	int i=0;
	Node *temp=head;
	if(head==NULL){
		return -1;
	}
	while(i<length(head) && temp->data!=n){
		temp=temp->next;
		++i;
	}
	if(temp->data==n){
		return i;
	}
	else{
		return -1;
	}

}
Node* midpoint_linkedlist(Node *head)
{
   Node *slow=head;
   Node *fast=head;
  while(slow!=NULL && fast->next!=NULL &&fast->next->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow;
}
Node *reverse_linked_list_rec(Node *head)
{
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node *smallAns=reverse_linked_list_rec(head->next);
  Node *temp=smallAns;
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=head;
  head->next=NULL;
  return smallAns;
}



int main(){
	Node *head=NULL;
	Node * n=takeInput();
	print(head);
	int i,data;
	cin>>i>>data;
	head = insertNode(head,i,data);
	print(head);

}
