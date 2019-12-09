#include<bits/stdc++.h>
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
		if(leftChildData!=-1){
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
void calculateMinMax(BinaryTreeNode<int>* root,int &min,int &max,int horizontalDistance){
	if(root==NULL)
		return;
	if(horizontalDistance<min)
		min = horizontalDistance;
	if(horizontalDistance>max)
		max = horizontalDistance;
	calculateMinMax(root->left,min,max,horizontalDistance-1);
	calculateMinMax(root->right,min,max,horizontalDistance+1);
}
void verticalHelper(BinaryTreeNode<int>* root,int verticalLine,int horizontalDistance){
	if(root==NULL)
		return;
	if(horizontalDistance == verticalLine)
		cout<<root->data<<" ";
	verticalHelper(root->left,verticalLine,horizontalDistance-1);
	verticalHelper(root->right,verticalLine,horizontalDistance+1);
}
void verticalTraversal(BinaryTreeNode<int>* root){
	int min = INT_MAX;
	int max = INT_MIN;
	int horizontalDistance = 0;
	calculateMinMax(root,min,max,horizontalDistance);
	for(int i=min;i<=max;i++){
		verticalHelper(root,i,horizontalDistance);
		cout<<endl;
	}
}
// Uses preorder approach O(nlogn)
void getVerticalOrder(BinaryTreeNode<int>* root,int hd,map<int,vector<int> > &m){
	if(root==NULL)
		return;
	m[hd].push_back(root->data);
	getVerticalOrder(root->left,hd-1,m);
	getVerticalOrder(root->right,hd+1,m);
}
void verticalTraversalBetter(BinaryTreeNode<int>* root){
	map<int,vector<int> > m;
	int hd = 0;
	getVerticalOrder(root,hd,m);
	map<int,vector<int> > :: iterator it;
	for(it = m.begin();it!=m.end();it++){
		for(int i=0;i<it->second.size();i++){
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
}
// Uses BFS which uses a queue having a pair<root,int> int has the distance in it while node represents the tree node
vector<vector<int> > verticalTraversalBFS(BinaryTreeNode<int>* root){
	if(root==NULL){
        vector<vector<int> > ans;
        return ans;
    }
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
	vector<vector<int> > ans;
    map<int,vector<int> > :: iterator it;
    for(it = m.begin();it!=m.end();it++){
        ans.push_back(it->second);
    } 
    return ans;
}

void verticalTraversalBFS1(BinaryTreeNode<int>* root){
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
	map<int,vector<int> > :: iterator it;
	for(it = m.begin();it!=m.end();it++){
		for(int i=0;i<it->second.size();i++){
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	BinaryTreeNode<int>* root = takeInputBFS();
	printTreeBFS(root);
	verticalTraversalBetter(root);
	verticalTraversalBFS1(root);
}