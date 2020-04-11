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
void AddatFront(Node *&head, int data){
if(head==NULL){
	head= new Node(data);
    return;
}
Node *n=new Node(data);
n->next=head;
head=n;
return;
}
void takeinput(Node *&head){
	int data;
	cin>>data;
	while(data!=-1){
		AddatFront(head,data);
		cin>>data;
	}
}
void print(Node *head) {
	while(head!=NULL){
		cout << head -> data << " " ;
		head = head -> next ;
	}
}
int length(Node* head){
	int count =0;
	while(head!=NULL){
		count++;
		head=head->next;
	}
	return count;
}
void printIthNode(Node *head, int i){
	int count=0;
  while(head!=NULL){    
   while(count<i){
     head=head->next;
     count++;
     }
     cout<<head->data;
     return;
     }
     return;
  }
   Node * insertNode(Node* head, int i, int data){

	Node *newNode = new Node(data);

	int count=0;
	Node *temp=head;
	if(i==0){
		newNode->next=head;
		head=newNode;
		return head;
	}
	while(temp!=NULL && count <i-1){
		temp=temp->next;
		count++;
	}
	if(temp!=NULL){
	newNode->next=temp->next;
	temp->next=newNode;
}
    return head;
}
Node* insertNodeRec(Node *head, int i, int data) {
 if(head==NULL){
 	return head;
 }
 Node *newNode = new Node(data);
 if (i==0)
 {
 	newNode->next=head;
		head=newNode;
		return head;
 	
 }        
 return insertNodeRec(head->next,i->i-1,data);
}
Node* deleteNode(Node *head, int i) {
  int count=0;
  if (i>length(head)){
  	return head;
  }
  if (i==0) {
  Node * temp1 = head;
  Node * c = temp1->next;
  head = c;
  delete temp1;
  return head;
  }
  Node * temp = head;
  while(count<i-1){
    temp = temp -> next;
  	count++;
  }
  Node * a = temp->next;
  Node * b = a->next;
  delete a;
  temp->next=b;
  return head;
}

int main(){
	Node *head=NULL;
	takeinput(head);
	print(head);
	cout<<deleteNode(head);
}