#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int oddCnt;
	int evenCnt;
};
void buildTree(int *arr,node *tree,int start,int end,int treeIdx){
	if(start>end){
		return;
	}
	if(start==end){
		if(arr[start]&1)
			tree[treeIdx].oddCnt=1;
		else
			tree[treeIdx].evenCnt=1;
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeIdx);
	buildTree(arr,tree,mid+1,end,2*treeIdx+1);
	tree[treeIdx].evenCnt = tree[2*treeIdx].evenCnt+tree[2*treeIdx+1].evenCnt;
	tree[treeIdx].oddCnt = tree[2*treeIdx].oddCnt+tree[2*treeIdx+1].oddCnt;
	return;
}
void updateTree(int *arr,node *tree,int start,int end,int treeIdx,int idx,int val){
	if(start>end){
		return;
	}
	if(start==end){
		arr[start] = val;
		if(val&1){
			tree[treeIdx].oddCnt=1;
			tree[treeIdx].evenCnt=0;
		}else{
			tree[treeIdx].oddCnt=0;
			tree[treeIdx].evenCnt=1;
		}
        return;
	}
	int mid = (start+end)/2;
	if(idx>mid){
		updateTree(arr,tree,mid+1,end,2*treeIdx+1,idx,val);
	}else{
		updateTree(arr,tree,start,mid,2*treeIdx,idx,val);
	}
	tree[treeIdx].evenCnt = tree[2*treeIdx].evenCnt+tree[2*treeIdx+1].evenCnt;
	tree[treeIdx].oddCnt = tree[2*treeIdx].oddCnt+tree[2*treeIdx+1].oddCnt;
	return;
}

node query(int *arr,node *tree,int start,int end,int treeIdx,int left,int right){
	if(start>right || end<left){
		node ans = {0,0};
		return ans;
	}
	if(start>=left && end<=right){
		return tree[treeIdx];
	}
	int mid = (start+end)/2;
	node leftAns = query(arr,tree,start,mid,2*treeIdx,left,right);
	node rightAns = query(arr,tree,mid+1,end,2*treeIdx+1,left,right);
	node ans;
	ans.oddCnt = leftAns.oddCnt+rightAns.oddCnt;
	ans.evenCnt = leftAns.evenCnt+rightAns.evenCnt;
	return ans;
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	node *tree = new node[4*n];
	for(int i=0;i<4*n;i++){
		tree[i].oddCnt = 0;
		tree[i].evenCnt = 0;
	}
	buildTree(arr,tree,0,n-1,1);
	int q;
	cin>>q;
	while(q--){
		int qtype,idx,val;
		cin>>qtype>>idx>>val;
		if(qtype==0){
            idx--;
			updateTree(arr,tree,0,n-1,1,idx,val);
		}
		if(qtype==1){
            idx--,val--;
			node ans = query(arr,tree,0,n-1,1,idx,val);
			cout<<ans.evenCnt<<endl;
		}
		if(qtype==2){
            idx--,val--;
			node ans = query(arr,tree,0,n-1,1,idx,val);
			cout<<ans.oddCnt<<endl;
		}
	}
}