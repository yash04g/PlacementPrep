#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void buildTree(int *a,ll *tree,int *arr,int start,int end,int treeIdx){
	if(start>end)
		return;
	if(start==end){
		tree[treeIdx] = a[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(a,tree,arr,start,mid,2*treeIdx);
	buildTree(a,tree,arr,mid+1,end,2*treeIdx+1);
	tree[treeIdx] = ((tree[2*treeIdx+1]%3)+((tree[2*treeIdx]*arr[end-mid])%3))%3;
}

void updateTree(int *a,ll *tree,int *arr,int start,int end,int treeIdx,int flipIdx){
    // exit(0);
	if(start>end)
		return;
	if(start==end){
		tree[treeIdx] = 1;
		a[flipIdx] = 1;
		return;
	}
	int mid = (start+end)/2;
	if(flipIdx>mid){
		updateTree(a,tree,arr,mid+1,end,2*treeIdx+1,flipIdx);
	}else{
		updateTree(a,tree,arr,start,mid,2*treeIdx,flipIdx);
	}
	tree[treeIdx] = ((tree[2*treeIdx+1]%3)+((tree[2*treeIdx]*arr[end-mid])%3))%3;	
}
int query(int *a,ll* tree,int *arr,int start,int end,int treeIdx,int left,int right){
	if(start>right||end<left){
    	return 0;
  	}
  	if(start>=left && end<=right){
    	return (tree[treeIdx]*arr[right-end])%3;
	}
	int mid = (start+end)/2;
	int leftAns = query(a,tree,arr,start,mid,2*treeIdx,left,right);
	int rightAns = query(a,tree,arr,mid+1,end,2*treeIdx+1,left,right);
	return (leftAns+rightAns)%3;
}
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
    int *a = new int[n];
    for(int i=0;i<n;i++){
        a[i] = s[i]-'0';
    }
	int q;
	cin>>q;
	ll *tree = new ll[4*n];
	int *arr = new int[n+1];
	for(int i=0;i<=n;i++){
		if((i&1)==0){
			arr[i] = 1;
		}else{
			arr[i] = 2;
		}
	}
	buildTree(a,tree,arr,0,n-1,1);
	while(q--){
		int qtype;
		cin>>qtype;
		if(qtype==1){
			int flipIdx;
            cin>>flipIdx;
            if(s[flipIdx]=='0'){
			    updateTree(a,tree,arr,0,n-1,1,flipIdx);
            }
		}else{
			int left,right;
            cin>>left>>right;
			cout<<query(a,tree,arr,0,n-1,1,left,right)<<endl;
		}
	}
}
