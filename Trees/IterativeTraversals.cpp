#include<bits/stdc++.h>
#include<unordered_map>
#include"BinaryTreeNode.h"
using namespace std;
#define mp make_pair
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
void printTreeBFS(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* front = pendingNodes.front();
		cout<<front->data<<":";
		pendingNodes.pop();
		if(front->left!=NULL){
			pendingNodes.push(front->left);
			cout<<"L"<<front->left->data<<",";
		}
		else{
			cout<<"L -1,";
		}

		if(front->right!=NULL){
			pendingNodes.push(front->right);
			cout<<"R"<<front->right->data<<" ";
		}
		else{
			cout<<"R -1";
		}
		cout<<endl;
	}
}
void traversal_trick(BinaryTreeNode<int>* root){
	if(root==NULL)
		return;
	unordered_map<BinaryTreeNode<int>*,int> cnt;
	stack<BinaryTreeNode<int>*> s;
	s.push(root);
	while(!s.empty()){
		BinaryTreeNode<int>* currentNode = s.top();
		if(currentNode==NULL){
			s.pop();
			continue;
		}
		if(cnt[currentNode]==0){
			s.push(currentNode->left);
		}
		else if(cnt[currentNode]==2){
			s.push(currentNode->right);
		}
		else if(cnt[currentNode]==1){
			cout<<currentNode->data<<" ";
		}
		else{
			s.pop();
		}
		cnt[currentNode]++;
	}
}
int main(){
	BinaryTreeNode<int>* root = takeInputBFS();
	printTreeBFS(root);
	traversal_trick(root);
}