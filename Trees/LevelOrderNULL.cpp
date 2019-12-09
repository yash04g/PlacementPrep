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
vector<vector<BinaryTreeNode<int>*> > LevelOrderTraversal(BinaryTreeNode<int>* root){
	if(root==NULL){
		vector<vector<BinaryTreeNode<int>*> > ans;
		return ans;
	}
	vector<vector<BinaryTreeNode<int>*> > ans;
	vector<BinaryTreeNode<int>*> x;
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);
	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		if(front!=NULL){
			x.push_back(front);
		}
		if(front==NULL && pendingNodes.front()==NULL){
			while(!x.empty()){
				ans.push_back(x);
			}
			break;
		}
		if(front==NULL){
			ans.push_back(x);
			pendingNodes.push(NULL);
			x.clear();
			continue;
		}
		if(front->left!=NULL)
			pendingNodes.push(front->left);
		if(front->right!=NULL)
			pendingNodes.push(front->right);
	}
	return ans;
}
int main(){
	BinaryTreeNode<int>* root = takeInputBFS();
	vector<vector<BinaryTreeNode<int>*> > ans = LevelOrderTraversal(root);
	vector<vector<BinaryTreeNode<int>*> > :: iterator it;
	for(auto i:ans){
		for(int j=0;j<i.size();j++){
			cout<<i[j]->data<<" ";
		}
		cout<<endl;
	}
}