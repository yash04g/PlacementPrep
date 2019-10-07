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
	tree[TreeNode] = min(tree[2*TreeNode],tree[2*TreeNode+1]);
}
void update(int *arr,int *tree,int start,int end,int TreeNode,int idx,int val){
	if(start==end){
		arr[idx] = val;
		tree[TreeNode] = val;
		return;
	}
	int mid = (start+end)/2;
	if(idx>mid){
		update(arr,tree,mid+1,end,2*TreeNode+1,idx,val);
	}else{
		update(arr,tree,start,mid,2*TreeNode,idx,val);
	}
	tree[TreeNode] = min(tree[2*TreeNode],tree[2*TreeNode+1]);
}
int queryTree(int *tree,int start,int end,int TreeNode,int left,int right){
    if(start>right || end<left){
		return INT_MAX;
	}
    if(start>=left && end<=right){
		return tree[TreeNode];
	}
    int mid = (start+end)/2;
	int leftAns = queryTree(tree,start,mid,2*TreeNode,left,right);
	int rightAns = queryTree(tree,mid+1,end,2*TreeNode+1,left,right);
	return min(leftAns,rightAns);
}
int main(){
    int n,q;
    cin>>n>>q;
    int *arr = new int[n+1];
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
    int *tree = new int[4*n];
    buildTree(arr,tree,1,n,1);
    while(q--){
        char query;
        cin>>query;
        int idx,val;
        cin>>idx>>val;
        if(query=='u'){
            update(arr,tree,1,n,1,idx,val);
        }
        if(query=='q'){
            int ans = queryTree(tree,1,n,1,idx,val);
            cout<<ans<<endl;
        }
    }
}