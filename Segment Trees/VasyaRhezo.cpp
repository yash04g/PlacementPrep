#include<bits/stdc++.h>
using namespace std;
class node{
public:
	int maxa;
	int minb;
	int warrior;
};
void buildTree(int *a,int *b,node *tree,int start,int end,int treeIdx){
	if(start>end)
		return;
	if(start==end){
		tree[treeIdx].maxa = a[start];
		tree[treeIdx].minb = b[start];
		tree[treeIdx].warrior = start;
		return;
	}
	int mid = (start+end)/2;
	buildTree(a,b,tree,start,mid,2*treeIdx);
	buildTree(a,b,tree,mid+1,end,2*treeIdx+1);
	if(tree[2*treeIdx].maxa>tree[2*treeIdx+1].maxa){
		tree[treeIdx].maxa = tree[2*treeIdx].maxa;
		tree[treeIdx].minb = tree[2*treeIdx].minb;
		tree[treeIdx].warrior = tree[2*treeIdx].warrior;
	}
	else if(tree[2*treeIdx].maxa<tree[2*treeIdx+1].maxa){
		tree[treeIdx].maxa = tree[2*treeIdx+1].maxa;
		tree[treeIdx].minb = tree[2*treeIdx+1].minb;
		tree[treeIdx].warrior = tree[2*treeIdx+1].warrior;
	}else{
		if(tree[2*treeIdx].minb<tree[2*treeIdx+1].minb){
			tree[treeIdx].maxa = tree[2*treeIdx].maxa;
			tree[treeIdx].minb = tree[2*treeIdx].minb;
			tree[treeIdx].warrior = tree[2*treeIdx].warrior;
		}else if(tree[2*treeIdx].minb>tree[2*treeIdx+1].minb){
			tree[treeIdx].maxa = tree[2*treeIdx+1].maxa;
			tree[treeIdx].minb = tree[2*treeIdx+1].minb;
			tree[treeIdx].warrior = tree[2*treeIdx+1].warrior;
		}else{
			if(tree[2*treeIdx].warrior<tree[2*treeIdx+1].warrior){
				tree[treeIdx].maxa = tree[2*treeIdx].maxa;
				tree[treeIdx].minb = tree[2*treeIdx].minb;
				tree[treeIdx].warrior = tree[2*treeIdx].warrior;
			}else{
				tree[treeIdx].maxa = tree[2*treeIdx+1].maxa;
				tree[treeIdx].minb = tree[2*treeIdx+1].minb;
				tree[treeIdx].warrior = tree[2*treeIdx+1].warrior;
			}
		}
	}
	return;
}

node query(node *tree,int start,int end,int treeIdx,int left,int right){
	if(start>right || end<left){
		node ans = {INT_MIN,INT_MAX,INT_MAX};
		return ans;
	}
	if(start>=left && end<=right){
		return tree[treeIdx];
	}
	int mid = (start+end)/2;
	node leftAns = query(tree,start,mid,2*treeIdx,left,right);
	node rightAns = query(tree,mid+1,end,2*treeIdx+1,left,right);
	node ans;
	if(leftAns.maxa>rightAns.maxa){
		ans.maxa = leftAns.maxa;
		ans.minb = leftAns.minb;
		ans.warrior = leftAns.warrior;
	}
	else if(leftAns.maxa<rightAns.maxa){
		ans.maxa = rightAns.maxa;
		ans.minb = rightAns.minb;
		ans.warrior = rightAns.warrior;
	}else{
		if(leftAns.minb<rightAns.minb){
			ans.maxa = leftAns.maxa;
			ans.minb = leftAns.minb;
			ans.warrior = leftAns.warrior;
		}else if(leftAns.minb>rightAns.minb){
			ans.maxa = rightAns.maxa;
			ans.minb = rightAns.minb;
			ans.warrior = rightAns.warrior;
		}else{
			if(leftAns.warrior<rightAns.warrior){
				ans.maxa = leftAns.maxa;
				ans.minb = leftAns.minb;
				ans.warrior = leftAns.warrior;
			}else{
				ans.maxa = rightAns.maxa;
				ans.minb = rightAns.minb;
				ans.warrior = rightAns.warrior;
			}
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	int *a = new int[n+1];
	int *b = new int[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	node *tree = new node[4*n];
	buildTree(a,b,tree,1,n,1);
	int q;
	cin>>q;
	while(q--){
		int left,right;
		cin>>left>>right;
		node ans = query(tree,1,n,1,left,right);
		cout<<ans.warrior<<endl;
	}
}