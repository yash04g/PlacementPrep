#include<bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node *next;
	Node(int data){
		this->data = data;
		next=NULL;
	}
};
void print_LL(Node *head){
	Node *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl; 
}
Node *takeInput(){		//Complexity is O(n^2)
	int data;
	cin>>data;
	Node *head = NULL;
	while(data!=-1){
		Node* newNode = new Node(data);
		if(head==NULL){
			head = newNode;
		}
		else{
			Node* temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		cin>>data;
	}
	return head;
}
Node* takeInput2(){		//Complexity is O(n)
	int data;
	cin>>data;
	Node *head = NULL;
	Node *tail = NULL;
	while(data!=-1){
		Node* newNode = new Node(data);
		if(head==NULL){
			head = newNode;
			tail = newNode;
		}
		else{
			tail ->next = newNode;
			tail = newNode;
			//or 
			//tail = tail->next;
		}
		cin>>data;
	}
	return head;
}
int length_LL(Node *head) {
  if(head==NULL){
    return 0;
  }
  return 1 + length_LL(head->next);
}
void printIthNode(Node *head, int i) {
  if(i>length_LL(head)){
    return;
  }
  else{
  int count =0;
  Node* temp = head;
  while(count<i){
    ++count;
    temp = temp->next;
  }
  cout<<temp->data;
}
}
Node* insertNode(Node* head,int i,int data){
	// if(i>length_LL(head)){
 //    return;
 //    }	 As we have add condition for temp in while loop
	Node *newNode = new Node(data);
	Node *temp = head;
	int count = 0;

	if(i==0){
		newNode->next = head;
		head = newNode;
		return head;
	}

	while(count<i-1 && temp != NULL){
		temp = temp->next;
		++count;
	}	//As soon as we will exit this loop we will have the address of i-1 node
	if(temp!=NULL){
	Node *a = temp->next;	//Contains the address of the node at i
	temp->next = newNode;
	newNode->next = a;
	}
	//Without creating a
	// newNode->next = temp->next;
	// temp->next = newNode;
	return head;
}
Node* deleteNode(Node*head,int i){
	int count = 0;
	Node* temp = head;
	if(i==0){
		head = temp->next;
		delete temp;
	}
	while(temp!=NULL && count<i-1){
		temp = temp->next;
		++count;
	}
	if(temp!=NULL && temp->next!=NULL){
	Node *a = temp->next;
	Node *b = a->next;
	temp->next = b;
	delete a;
	}
	return head;
}
Node* insertNodeRec(Node *head, int i, int data){
	if(head==NULL){
		return head;
	}
	Node* newNode = new Node(data);
	if(i==0){
		newNode->next = head;
		head = newNode;
		return head;
	}
	head->next = insertNodeRec(head->next,i-1,data);
	return head;
}
Node* deleteNodeRec(Node*head,int i){
	if(head==NULL){
		return head;
	}
	if(i==0){
		Node *temp = head;
		head = temp->next;
		delete temp;
	}
	head->next = deleteNodeRec(head->next,i-1);
	return head;
}
void print_linkedlist_spl(Node *head){
  if(head==NULL){
    return;
  }
  print_linkedlist_spl(head->next);
  cout<<head->data<<" ";
    
}
int Node_Search(Node *head, int n) {
  if(head==NULL){
    return -1;
  }
  Node*temp = head;
  int i=0;
  while(temp!=NULL){
    if(temp->data == n){
      return i;	// Returns the index at which node is present
    }
    temp = temp->next;
    ++i;
  }
  return -1;
}
Node* append_LinkedList(Node* head,int n){
	int i=1;
	int len = length_LL(head);
	int count = len - n;
	Node *temp = head;
	Node *head2 = head;
	while(i<count || temp!=NULL){
		++i;
		temp = temp->next;
	}
	if(temp!=NULL){
		head2 = temp->next;
		temp->next = NULL;
		Node *temp2 = head2;
		while(temp2!=NULL){
			temp2 = temp2->next;
		}
		Node* tail = temp2;
		head = tail->next;
		return head2;
	}
	return head;
}
int main(){
	// Node n1(1),n2(2);
	// n1.next = &n2;
	// Node *n5 = new Node(10);
	// Node *n6 = new Node(20);
	// Node *head = n5;
	// n5->next = n6;
	// n6->next = NULL;
	Node *head = takeInput2();
	print_LL(head);
	// head = insertNode(head,0,99);
	// print_LL(head);
	// head = insertNode(head,2,100);
	// print_LL(head);
	// head = insertNode(head,9,200);
	// print_LL(head);
	// head = deleteNodeRec(head,2);
	// print_LL(head);
	// head = insertNodeRec(head,2,100);
	// print_LL(head);
	head = append_LinkedList(head,3);
	print_LL(head);
}