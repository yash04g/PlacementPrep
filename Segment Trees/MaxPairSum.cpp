#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int maxima;
	int smaxima;
};

void buildTree(int *arr,node *tree,int start,int end,int treeIndex){
	if(start==end){
		tree[treeIndex].maxima = arr[start];
		tree[treeIndex].smaxima = INT_MIN;
		return;
	}

	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeIndex);
	buildTree(arr,tree,mid+1,end,2*treeIndex+1);
	node left = tree[2*treeIndex];
	node right = tree[2*treeIndex+1];
	tree[treeIndex].maxima = max(left.maxima,right.maxima);
	tree[treeIndex].smaxima = min(max(left.maxima,right.smaxima),max(right.maxima,left.smaxima));
	return;
}
void updateTree(int *arr,node *tree,int start,int end,int treeIndex,int idx,int val){
	if(start==end){
		arr[idx] = val;
		tree[treeIndex].maxima = val;
		tree[treeIndex].smaxima = INT_MIN;
		return;
	}
	int mid = (start+end)/2;
	if(idx>mid){
		updateTree(arr,tree,mid+1,end,2*treeIndex+1,idx,val);
	}else{
		updateTree(arr,tree,start,mid,2*treeIndex,idx,val);
	}
	node left = tree[2*treeIndex];
	node right = tree[2*treeIndex+1];
	tree[treeIndex].maxima = max(left.maxima,right.maxima);
	tree[treeIndex].smaxima = min(max(left.maxima,right.smaxima),max(right.maxima,left.smaxima)); 
}
 node queryTree(node *tree,int start,int end,int treeIndex,int left,int right){
	if(start>right || end<left){
		node ans={INT_MIN,INT_MIN};
		return ans;
	}
	if(start>=left && end<=right){
		return tree[treeIndex];
	}
	int mid = (start+end)/2;
	node leftNode = queryTree(tree,start,mid,2*treeIndex,left,right);
	node rightNode = queryTree(tree,mid+1,end,2*treeIndex+1,left,right);
	node ans;
	ans.maxima = max(leftNode.maxima,rightNode.maxima);
	ans.smaxima = min(max(leftNode.maxima,rightNode.smaxima),max(rightNode.maxima,leftNode.smaxima));
	return ans;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	node *tree = new node[4*n];
	buildTree(arr,tree,0,n-1,1);
	int q;
	cin>>q;
	while(q--){
		char query;
		cin>>query;
		int x,y;
		cin>>x>>y;
		if(query=='U'){
			x--;
			updateTree(arr,tree,0,n-1,1,x,y);
		}
		if(query=='Q'){
			x--;
			y--;
			node ans = queryTree(tree,0,n-1,1,x,y);
			cout<<ans.maxima+ans.smaxima<<endl;
		}
	}
}