#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int*tree,int start,int end,int treeIdx){
	if(start == end){
		tree[treeIdx] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeIdx);
	buildTree(arr,tree,mid+1,end,2*treeIdx+1);
	tree[treeIdx] = min(tree[2*treeIdx],tree[2*treeIdx+1]);
}

void updateTree(int *tree,int *lazy,int start,int end,int treeIdx,int left,int right,int inc){
	if(start>end) return;
	if(lazy[treeIdx]!=0){
		tree[treeIdx] += lazy[treeIdx];
		if(start!=end){
			lazy[2*treeIdx] += lazy[treeIdx];
			lazy[2*treeIdx+1] += lazy[treeIdx];
		}
		lazy[treeIdx] = 0;
	}
	// No overlap
	if(right<start || left>end){
		return;
	}
	// Complete Overlap
	if(left<=start && right>=end){
		tree[treeIdx] += inc;
		if(start!=end){
			lazy[2*treeIdx] += inc;
			lazy[2*treeIdx+1] += inc;
		}
		return;
	}
	// Partial Overlap
	int mid = (start+end)/2;
	updateTree(tree,lazy,start,mid,2*treeIdx,left,right,inc);
	updateTree(tree,lazy,mid+1,end,2*treeIdx+1,left,right,inc);
	tree[treeIdx] = min(tree[2*treeIdx],tree[2*treeIdx+1]);
	return;
}

int query(int *tree,int *lazy,int start,int end,int treeIdx,int left,int right){
	if(start>end) return INT_MAX;
	if(lazy[treeIdx]!=0){
		tree[treeIdx] += lazy[treeIdx];
		if(start!=end){
			lazy[2*treeIdx] += lazy[treeIdx];
			lazy[2*treeIdx+1] += lazy[treeIdx];
		}
		lazy[treeIdx] = 0;
	}

	if(start>right || end<left){
		return INT_MAX;
	}

	if(start>=left && end<=right){
		return tree[treeIdx];
	}
	int mid = (start+end)/2;
	int leftAns = query(tree,lazy,start,mid,2*treeIdx,left,right);
	int rightAns = query(tree,lazy,mid+1,end,2*treeIdx+1,left,right);
	return min(leftAns,rightAns);
}

int main(){
	int n;
	cin>>n;
	int *arr = new int[n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	int *tree = new int[4*n];
	int *lazy = new int[4*n]();
	buildTree(arr,tree,1,n,1);
	int left,right,inc;
	cin>>left>>right>>inc;
	updateTree(tree,lazy,1,n,1,left,right,inc);
	updateTree(tree,lazy,1,n,1,left,right-2,inc-1);
	cout<<"Segment Tree"<<endl;
	for(int i=1;i<=4*n;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl<<"Lazy Tree"<<endl;
	for(int i=1;i<=4*n;i++){
		cout<<lazy[i]<<" ";
	}
	cin>>left>>right;
	cout<<query(tree,lazy,1,n,1,left,right)<<endl;
}