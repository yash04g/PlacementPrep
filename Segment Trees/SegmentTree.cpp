#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int TreeNode){
	if(start==end){
		tree[TreeNode] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*TreeNode);
	buildTree(arr,tree,mid+1,end,2*TreeNode+1);
	tree[TreeNode] = tree[2*TreeNode] + tree[2*TreeNode+1];
}
void updateTree(int *arr,int *tree,int start,int end,int TreeNode,int idx,int val){
	if(start==end){
		arr[idx] = val;
		tree[TreeNode] = val;
		return;
	}
	int mid = (start+end)/2;
	if(idx>mid){
		updateTree(arr,tree,mid+1,end,2*TreeNode+1,idx,val);
	}else{
		updateTree(arr,tree,start,mid,2*TreeNode,idx,val);
	}
	tree[TreeNode] = tree[2*TreeNode]+tree[2*TreeNode+1];
}
int query(int *tree,int start,int end,int TreeNode,int left,int right){
	// Completely outside
	if(start>right || end<left){
		return 0;
	}
	//Completely Inside
	if(start>=left && end<=right){
		return tree[TreeNode];
	}
	// Partially
	int mid = (start+end)/2;
	int leftAns = query(tree,start,mid,2*TreeNode,left,right);
	int rightAns = query(tree,mid+1,end,2*TreeNode+1,left,right);
	return leftAns+rightAns;
}

int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	// Always make Segment tree of size 4*n
	int *tree = new int[4*n];
	buildTree(arr,tree,0,n-1,1);
	for(int i=1;i<=4*n;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
	int idx,val;
	cin>>idx>>val;
	updateTree(arr,tree,0,n-1,1,idx,val);
	for(int i=1;i<=4*n;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
	int left,right;
	cin>>left>>right;
	int ans = query(tree,0,n-1,1,left,right);
	cout<<ans<<endl;
}
