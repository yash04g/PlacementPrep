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
int indexOfNIter(Node *head, int n) {
    if(head == NULL){
        return -1;
    }
	if(head->data == n){
		return 0;
	}   
	Node* temp = head;
	int count = 0;
	while(temp!=NULL){
		if(temp->data==n){
			return count;
		}
		temp = temp->next;
		count++;
	}
    return -1;
}
int lengthLL(Node *head){
	if(head == NULL) return 0;
	return 1+lengthLL(head->next);
}
Node* append_LinkedList(Node* head,int n){
	if(head == NULL){
		return NULL;
	}
	int LastIndex = lengthLL(head)-1;
	Node* temp = head;
	int count = 0;
	while(count < LastIndex-n){
		temp = temp->next;
		count++;
	}
	Node *newNode = temp->next;
	temp->next = NULL;
    Node* temp1 = newNode;
	while(temp1->next!=NULL){
		temp1 = temp1->next;
	}
	temp1->next = head;
	head = newNode;
	return head;
}
Node* eliminate_duplicate(Node* head){
	if(head == NULL || head->next==NULL){
		return head;
	}
	Node* temp1 = head;
	Node* temp2 = head->next;
	while(temp2!=NULL){
		if(temp1->data == temp2->data){
			temp2 = temp2->next;
		}
		else{
			temp1->next = temp2;
            temp1 = temp2;
			temp2 = temp2->next;
		}
	}
	temp1->next = temp2;
	return head;
}
void printReverseLL(Node* head){
	if(head==NULL) return;
	printReverseLL(head->next);
	cout<<head->data<<" ";
}
Node* printReverseLL1(Node* head){
	if(head == NULL || head->next==NULL) return head;
	Node* newHead = printReverseLL1(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}
Node* midLL(Node* head){
	if(head == NULL){
		return NULL;
	}
	Node* slow = head;
	Node* fast = head->next;
	while(fast->next!=NULL && fast!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}
// bool check_palindrome(Node* head){
// 	if(head == NULL) return true;
// 	Node* midPoint = midLL(head); 
// 	Node* newHead = printReverseLL1(midPoint);
// 	while(head!=NULL){
// 		cout<<head->data<<" ";
// 		head=head->next;
// 	}
// 	cout<<endl;
// 	while(newHead!=NULL){
// 		cout<<newHead->data<<" ";
// 		newHead = newHead->next;
// 	}
// 	cout<<endl;
// 	// while(newHead->next!=NULL){
// 	// 	if(head->data == newHead->data){
// 	// 		head = head->next;
// 	// 		newHead = newHead->next;
// 	// 	}
// 	// 	else if(head->data != newHead->data){
// 	// 		return false;
// 	// 	}
// 	// 	else if(head->next)
// 	// }
// 	return true;
// }


int main(){
	Node *head = takeInput();
	printReverseLL(head);
	cout<<endl<<lengthLL(head)<<endl;
	Node* newNode = printReverseLL1(head);
	cout<<endl;
	print(newNode);
	// cout<<check_palindrome(head);

}