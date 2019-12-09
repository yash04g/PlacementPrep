#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include"BinaryTreeNode.h"
using namespace std;
void printTree(BinaryTreeNode<int>* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<":";
	if(root->left!=NULL){
		cout<<"L:"<<root->left->data<<" ";
	}
	if(root->right!=NULL){
		cout<<"R:"<<root->right->data<<" ";
	}
	cout<<endl;
	printTree(root->left);
	printTree(root->right);
}
BinaryTreeNode<int>* takeInput(){
	int rootData;
	cin>>rootData;
	if(rootData == -1){
		return NULL;
	}
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}
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
int numNodes(BinaryTreeNode<int>* root){
	if(root==NULL){
		return 0;
	}
	return 1 + numNodes(root->right) + numNodes(root->left);
}
bool isNodePresent(BinaryTreeNode<int>* root,int x){
	if(root==NULL){
		return false;
	}
	if(root->data == x){
		return true;
	}
	bool leftAns = isNodePresent(root->left,x);
	bool rightAns = isNodePresent(root->right,x);
	bool ans = leftAns || rightAns;
	return ans;
}
int height(BinaryTreeNode<int>* root){
	if(root==NULL)
		return 0;
	return 1 + max(height(root->left),height(root->right));
}
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
	if(root==NULL)
		return;
	mirrorBinaryTree(root->left);
	mirrorBinaryTree(root->right);
	BinaryTreeNode<int>* temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
}
void inOrder(BinaryTreeNode<int> *root){
	if(root==NULL){
    return;
  	}
  	inOrder(root->left);
  	cout<<root->data<<" ";
	inOrder(root->right);
}
void preOrder(BinaryTreeNode<int> *root){
  if(root==NULL){
    return;
  }
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}
void postOrder(BinaryTreeNode<int> *root){
  if(root==NULL){
    return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
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
	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1,max(option3,option2));
}
pair<int,int> diameterBetterHelper(BinaryTreeNode<int>* root){
	if(root==NULL){
		pair<int,int> result;
		result.first = 0;
		result.second = 0;
		return result;
	}
	pair<int,int> leftAns = diameterBetterHelper(root->left);
	pair<int,int> rightAns = diameterBetterHelper(root->right);
	int lh = leftAns.first;
	int rh = rightAns.first;
	int ld = leftAns.second;
	int rd = rightAns.second;
	int height = 1 + max(lh,rh);
	int diameter = max(lh+rh,max(ld,rd));
	pair<int,int> ans;
	ans.first = height;
	ans.second = diameter;
	return ans;
}
int diameterBetter(BinaryTreeNode<int>* root){
	pair<int,int> ans = diameterBetterHelper(root);
	return ans.second;
}
class PairAns{
public:
	int min;
	int max;
};
PairAns minMax(BinaryTreeNode<int> *root) {
	if(root==NULL){
		PairAns ans;
		ans.min = INT_MAX;
		ans.max = INT_MIN;
		return ans;
	}
	PairAns leftAns = minMax(root->left);
	PairAns rightAns = minMax(root->right);
	int minima = min(root->data,min(leftAns.min,rightAns.min));
	int maxima = max(root->data,max(leftAns.max,rightAns.max));
	PairAns finalAns;
	finalAns.min = minima;
	finalAns.max = maxima;
	return finalAns;
}
int sumOfAllNodes(BinaryTreeNode<int>* root) {
	if(root==NULL)
		return 0;
	int sum = root->data;
	int leftSum = sumOfAllNodes(root->left);
	int rightSum = sumOfAllNodes(root->right);
	return sum+rightSum+leftSum;
}
bool isBalanced(BinaryTreeNode<int> *root){
	if(root==NULL)
		return true;
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	if(abs(leftHeight-rightHeight)<=1)
		return true;
	else
		return false;

	bool leftAns = isBalanced(root->left);
	bool rightAns = isBalanced(root->right);
	return leftAns && rightAns;
}
pair<int,bool>* isBalancedPairHelper(BinaryTreeNode<int>* root){
	if(root==NULL){
		pair<int,bool>* pair1 = new pair<int,bool>(0,true);
		pair1->first = 0;
		pair1->second = true;
		return pair1;
	}
	pair<int,bool>* leftAns = isBalancedPairHelper(root->left);
	pair<int,bool>* rightAns = isBalancedPairHelper(root->right);
	pair<int,bool>* finalAns = new pair<int,bool>();
	int leftHeight = leftAns->first;
	int rightHeight = rightAns->first;
	if(abs(leftHeight-rightHeight)>1 || !(leftAns->second) || !(rightAns->second)){
		finalAns->second = false;
	}
	else{
		finalAns->second = true;
	}
	finalAns->first = 1 + max(leftHeight,rightHeight);
	return finalAns;
}
bool isBalancedPair(BinaryTreeNode<int>* root){
	pair<int,bool>* ans = isBalancedPairHelper(root);
	return ans->second;
}
void printLevelATNewLine(BinaryTreeNode<int> *root){
	if(root==NULL)
		return;
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		int size = pendingNodes.size();
		while(size>0){
		BinaryTreeNode<int>* front = pendingNodes.front();
		cout<<front->data<<" ";
		pendingNodes.pop();
		if(front->left!=NULL){
			pendingNodes.push(front->left);
		}
		if(front->right!=NULL){
			pendingNodes.push(front->right);
		}
		size--;
		}
		cout<<endl;
	}
}
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
	if(root==NULL || (root->left==NULL && root->right == NULL)){
		return NULL;
	}
	BinaryTreeNode<int>* leftAns = removeLeafNodes(root->left);
	BinaryTreeNode<int>* rightAns = removeLeafNodes(root->right);
	root->left = leftAns;
	root->right = rightAns;
	return root;
}
void nodesWithoutSibling(BinaryTreeNode<int> *root) {
	if(root==NULL)
		return;
	if(root->left == NULL && root->right!=NULL){
		cout<<root->right->data<<endl;
	}
	if(root->left != NULL && root->right==NULL){
		cout<<root->left->data<<endl;
	}
	nodesWithoutSibling(root->left);
	nodesWithoutSibling(root->right);
}
template<typename T>
class node{
public:
	T data;
	node* next;

	node(T data){
		this->data = data;
		next = NULL;
	}
};
vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
	if(root==NULL){
		vector<node<int>*> ans;
		node<int>* temp = new node<int>(-1);
		ans.push_back(temp);
		return ans;
	}
	vector<node<int>*> ans;
	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(!pendingNodes.empty()){
		int size = pendingNodes.size();
		node<int>* head = new node<int>(pendingNodes.front()->data);
		ans.push_back(head);
        node<int>* temp = NULL;
		while(size>0){
			BinaryTreeNode<int>* front = pendingNodes.front();
			pendingNodes.pop();
			if(front->left!=NULL){
                node<int>* leftNode = new node<int>(front->left->data);
				if(temp==NULL){
					temp = leftNode;
				}
				else{
				temp->next = leftNode;
				temp = temp->next;
				}
				pendingNodes.push(front->left);
			}
			if(front->right!=NULL){
                node<int>* rightNode = new node<int>(front->right->data);
				if(temp==NULL){
					temp = rightNode;
				}
				else{
				temp->next = rightNode;
				temp = temp->next;
				}
				pendingNodes.push(front->right);
			}
			size--;
		}
	}
	return ans;
}
void zigZagOrder(BinaryTreeNode<int> *root){
	if(root==NULL)
		return;
	stack<BinaryTreeNode<int>*> s1;
	stack<BinaryTreeNode<int>*> s2;
	s1.push(root);
	while(!s1.empty()){
		BinaryTreeNode<int>* top1 = s1.top();
		cout<<top1->data<<" ";
		s1.pop();
		if(top1->left!=NULL){
			s2.push(top1->left);
		}
		if(top1->right!=NULL){
			s2.push(top1->right);
		}
		while(!s2.empty()){
			BinaryTreeNode<int>* top2 = s2.top();
			cout<<top2->data<<" ";
			s2.pop();
			if(top2->right!=NULL){
				s1.push(top2->right);
			}
            if(top2->left!=NULL){
				s1.push(top2->left);
			}
		}
	}
}

int main(){
	// BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
	// BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
	// BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
	// root->left = node1;
	// root->right = node2;
	// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
	BinaryTreeNode<int>* root = takeInputBFS();
	printTreeBFS(root);
	// cout<<numNodes(root)<<endl;
	// cout<<diameter(root)<<endl;
	// cout<<diameterBetter(root)<<endl;
	//5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
	zigZagOrder(root);
}