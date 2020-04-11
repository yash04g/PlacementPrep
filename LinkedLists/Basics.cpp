#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
    Node(int data){
    	this-> data=data;
    	next=NULL;
    }
};
int main(){
	Node n1(1),n2(2);
	Node *head=&n1;
	n2.next=&n2;
	cout<<head<<n2.next;

	}