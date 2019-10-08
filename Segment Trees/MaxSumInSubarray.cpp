#include<bits/stdc++.h>
using namespace std;
#define MIN -15008
class node{
public:
	int maxSum;
	int sum;
	int bpsum; // Best Prefix Sum
	int bssum; // Best Suffix Sum
};

void buildTree(int *arr,node *tree,int start,int end,int treeIndex){
	if(start == end){
		tree[treeIndex].maxSum = arr[start];
		tree[treeIndex].sum = arr[start];
		tree[treeIndex].bssum = arr[start];
		tree[treeIndex].bpsum = arr[start];
        return;
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeIndex);
	buildTree(arr,tree,mid+1,end,2*treeIndex+1);
	node left = tree[2*treeIndex];
	node right = tree[2*treeIndex+1];
	tree[treeIndex].sum = left.sum+right.sum;
	tree[treeIndex].bpsum = max(left.bpsum,left.sum+right.bpsum);
	tree[treeIndex].bssum = max(right.bssum,right.sum+left.bssum);
	tree[treeIndex].maxSum = max(left.maxSum,max(right.maxSum,max(tree[treeIndex].bpsum,max(tree[treeIndex].bssum,left.bssum+right.bpsum))));
	return;
}

node query(node *tree,int start,int end,int treeIndex,int left,int right){
	if(start>right || end<left){
		node ans = {MIN,MIN,MIN,MIN};
		return ans;
	}
	if(start>=left && end<=right){
		return tree[treeIndex];
	}
	int mid = (start+end)/2;
	// Adding -ve number to INT_MIN makes it positive
	// if(left>mid){
	// 	return query(tree,mid+1,end,2*treeIndex+1,left,right);
	// }
	// if(right<=mid){
	// 	return query(tree,start,mid,2*treeIndex,left,right);
	// }

	node leftAns = query(tree,start,mid,2*treeIndex,left,right);
	node rightAns = query(tree,mid+1,end,2*treeIndex+1,left,right);
    
	node ans;
	ans.sum = leftAns.sum+rightAns.sum;
	ans.bpsum = max(leftAns.bpsum,leftAns.sum+rightAns.bpsum);
	ans.bssum = max(rightAns.bssum,rightAns.sum+leftAns.bssum);
	ans.maxSum = max(leftAns.maxSum,max(rightAns.maxSum,max(ans.bpsum,max(ans.bssum,leftAns.bssum+rightAns.bpsum))));
	return ans;
}

int main(){
	int n;
	cin>>n;
	int *a = new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	node *tree = new node[4*n];
	buildTree(a,tree,0,n-1,1);
	int q;
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
        x--,y--;
		node ans = query(tree,0,n-1,1,x,y);
		cout<<ans.maxSum<<endl;
	}
}