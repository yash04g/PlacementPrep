#include<bits/stdc++.h>
#include<unordered_map>
#include"BinaryTreeNode.h"
using namespace std;
BinaryTreeNode<int>* takeInputBFS(){
	cout<<"Enter root data "<<endl;
	int rootData;
	cin>>rootData;
	if(rootData == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter left child of "<<front->data<<endl;
		int leftChildData;
		cin>>leftChildData;
		if(leftChildData!=-1){
			BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
			front->left = leftChild;
			pendingNodes.push(leftChild);
		}
		cout<<"Enter right child of "<<front->data<<endl;
		int rightChildData;
		cin>>rightChildData;
		if(rightChildData!=-1){
			BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
			front->right = rightChild;
			pendingNodes.push(rightChild);
		}
	}
	return root;
}
void reverseLevelOrder(BinaryTreeNode<int>* root){
	if(root==NULL)
		return;
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	stack<BinaryTreeNode<int>*> s;
	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* front = pendingNodes.front();
		s.push(pendingNodes.front());
		pendingNodes.pop();
		if(front->left!=NULL){
			pendingNodes.push(front->left);
		}
		if(front->right!=NULL){
			pendingNodes.push(front->right);
		}
	}
	while(!s.empty()){
		cout<<s.top()->data<<" ";
		s.pop();
	}
}
int main(){
	BinaryTreeNode<int>* root = takeInputBFS();
	reverseLevelOrder(root);
}