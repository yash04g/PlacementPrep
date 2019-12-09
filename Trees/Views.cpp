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
void LeftView(BinaryTreeNode<int>* root){
	if(root==NULL)
		return;
	queue<BinaryTreeNode<int>* > pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);
	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* front = pendingNodes.front();
		if(front!=NULL){
			cout<<front->data<<" ";
			while(front!=NULL){
				if(front->left!=NULL){
					pendingNodes.push(front->left);
				}
				if(front->right!=NULL){
					pendingNodes.push(front->right);
				}
				pendingNodes.pop(); // Front is popped
				front = pendingNodes.front();
			}
			pendingNodes.push(NULL);
		}
		// cout<<endl;
		pendingNodes.pop();
	}
}
vector<vector<int> > LevelOrderTraversal(BinaryTreeNode<int>* root){
	if(root==NULL){
		vector<vector<int> > ans;
		return ans;
	}
	vector<vector<int> > ans;
	queue<BinaryTreeNode<int>* > pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL);
	vector<int> x;
	while(!pendingNodes.empty()){
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		if(front!=NULL){
			x.push_back(front->data);
		}
		if(front==NULL && pendingNodes.front()==NULL){
			if(!x.empty()){
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
void LeftView2(BinaryTreeNode<int>* root){
	if(root==NULL)
		return;
	vector<vector<int> > ans = LevelOrderTraversal(root);
	for(vector<int> i:ans){
		if(i.size()>0){
			cout<<i[0]<<" ";
		}
	}
	return;
}
void RightView(BinaryTreeNode<int>* root){
	if(root==NULL)
		return;
	vector<vector<int> > ans = LevelOrderTraversal(root);
	for(vector<int> i:ans){
		if(i.size()>0){
			cout<<i[i.size()-1]<<" ";
		}
	}
	return;
}
// Top View
void TopView(BinaryTreeNode<int>* root){
	queue<pair<BinaryTreeNode<int>*,int> > pendingNodes;
	map<int,vector<int> > m;
	int hd = 0;
	pendingNodes.push(make_pair(root,hd));
	while(!pendingNodes.empty()){
		pair<BinaryTreeNode<int>*,int> front = pendingNodes.front();
		pendingNodes.pop();
		hd = front.second;
		BinaryTreeNode<int>* node = front.first;
		m[hd].push_back(node->data);
		if(node->left!=NULL){
			pendingNodes.push(make_pair(node->left,hd-1));
		}
		if(node->right!=NULL){
			pendingNodes.push(make_pair(node->right,hd+1));
		}
	}
	map<int,vector<int> > :: iterator it = m.begin();
	for(it = m.begin();it!=m.end();it++){
		cout<<it->second[0]<<" ";
	}
}
void Bottomview(BinaryTreeNode<int>* root){
	queue<pair<BinaryTreeNode<int>*,int> > pendingNodes;
	map<int,vector<int> > m;
	int hd = 0;
	pendingNodes.push(make_pair(root,hd));
	while(!pendingNodes.empty()){
		pair<BinaryTreeNode<int>*,int> front = pendingNodes.front();
		pendingNodes.pop();
		hd = front.second;
		BinaryTreeNode<int>* node = front.first;
		m[hd].push_back(node->data);
		if(node->left!=NULL){
			pendingNodes.push(make_pair(node->left,hd-1));
		}
		if(node->right!=NULL){
			pendingNodes.push(make_pair(node->right,hd+1));
		}
	}
	map<int,vector<int> > :: iterator it = m.begin();
	for(it = m.begin();it!=m.end();it++){
		cout<<it->second[it->second.size()-1]<<" ";
	}
}
int main(){
	BinaryTreeNode<int>* root = takeInputBFS();
	// 1 2 3 -1 4 5 -1 -1 -1 -1 6 7 8 -1 -1 -1 -1
	LeftView(root);
	cout<<endl;
	LeftView2(root);
	cout<<endl;
	RightView(root);
	// RightView(root);
	cout<<endl;
	TopView(root);
	cout<<endl;
	Bottomview(root);
}