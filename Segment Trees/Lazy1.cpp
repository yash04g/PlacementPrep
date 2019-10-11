#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int idx){
	if(start>end)
		return;
	if(start==end){
		tree[idx] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*idx);
	buildTree(arr,tree,mid+1,end,2*idx+1);
	tree[idx] = min(tree[2*idx],tree[2*idx+1]);
}

void updateTree(int *tree,int *lazy,int start,int end,int idx,int left,int right,int inc){
	if(start>end)
		return;
	if(lazy[idx]!=0){
		tree[idx] += lazy[idx];
		if(start!=end){
			lazy[2*idx] += lazy[idx];
			lazy[2*idx+1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(start>right || end<left){
		return;
	}
	if(start>=left && end<=right){	
		tree[idx] += inc;
		if(start!=end){
			lazy[2*idx] += inc;
			lazy[2*idx+1] += inc;
		}
		return;
	}
	int mid = (start+end)/2;
	updateTree(tree,lazy,start,mid,2*idx,left,right,inc);
	updateTree(tree,lazy,mid+1,end,2*idx+1,left,right,inc);
	tree[idx] = min(tree[2*idx],tree[2*idx+1]);
}

int query(int *tree,int *lazy,int start,int end,int idx,int left,int right){
	if(start>end)
		return INT_MAX;
	if(lazy[idx]!=0){
		tree[idx] += lazy[idx];
		if(start!=end){
			lazy[2*idx] += lazy[idx];
			lazy[2*idx+1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(start>right || end<left){
		return INT_MAX;
	}
	if(start>=left && end<=right){
		return tree[idx];
	}
	int mid = (start+end)/2;
	int leftAns = query(tree,lazy,start,mid,2*idx,left,right);
	int rightAns = query(tree,lazy,mid+1,end,2*idx+1,left,right);
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