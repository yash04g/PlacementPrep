#include<iostream>
#include<vector>
#include<queue>
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
int minDepth(BinaryTreeNode<int>* root){
	if (root == NULL) 
        return 0;
    if (root->left == NULL && root->right == NULL) 
        return 1;
    if (!root->left) 
        return minDepth(root->right) + 1;
    if (!root->right) 
        return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
}
BinaryTreeNode<int>* buildTreeHelper(int *preorder,int *inorder,int inStart,int inEnd,int preStart,int preEnd){
	if(inStart>inEnd){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[preStart]);
	int rootIndexIn = -1;
	for(int i=inStart;i<=inEnd;i++){
		if(inorder[i]==preorder[preStart]){
			rootIndexIn = i;
			break;
		}
	}
	int lpreS = preStart+1;
	int linS = inStart;
	int linE = rootIndexIn-1;
	int lpreE = linE - linS + lpreS;
	int rpreE = preEnd;
	int rinS = rootIndexIn+1;
	int rinE = inEnd;
	int rpreS = lpreE+1;
	BinaryTreeNode<int>* leftChild= buildTreeHelper(preorder,inorder,linS,linE,lpreS,lpreE);
	BinaryTreeNode<int>* rightChild = buildTreeHelper(preorder,inorder,rinS,rinE,rpreS,rpreE);
	root->left = leftChild;
	root->right = rightChild;
	return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
	int inStart = 0;
	int inEnd = inLength-1;
	int preStart = 0;
	int preEnd = preLength-1;
	BinaryTreeNode<int>* root = buildTreeHelper(preorder,inorder,inStart,inEnd,preStart,preEnd);
	return root;
}
int diameter(BinaryTreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	int option1 = height
}
int main(){

}