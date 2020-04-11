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
Node *takeinput(){
	int data;
	cin>>data;
	Node *head=NULL;
	while(data!= -1){
		Node *newNode = new Node(data);
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
void print(Node *head){
	Node* temp = head;
	while(temp->next!=NULL){
		cout<<temp->data;
		temp=temp->next;
	}

}
Node *insertNode(Node* head, int i, int data){
	Node* temp=head;
	int count=0;
	Node* newNode = new Node(data);
	if(i==0){
		newNode->next=temp;
		temp=newNode;
		return temp;
	}
	while(temp!=NULL && count<i-1){
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
Node *deleteNode(Node* head, int i){
	
}
int main(){

}