#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class node{
public:
	ll squareSum;
	ll sum;
};
class lnode{
public:
	ll set;
	ll update;
};

void buildTree(ll *arr,node* tree,ll start,ll end,ll treeIdx){
	if(start==end){
		tree[treeIdx].squareSum = arr[start]*arr[start];
		tree[treeIdx].sum = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*treeIdx);
	buildTree(arr,tree,mid+1,end,2*treeIdx+1);
	tree[treeIdx].squareSum = tree[2*treeIdx].squareSum + tree[2*treeIdx+1].squareSum;
	tree[treeIdx].sum = tree[2*treeIdx].sum+tree[2*treeIdx+1].sum;
}

void updateTree(node* tree, lnode* lazy,ll start,ll end,ll treeIdx,int qtype,ll left,ll right,ll val){
	if(start>end)
		return;
	if(lazy[treeIdx].set!=0){
		ll x = lazy[treeIdx].set;
		tree[treeIdx].sum = (end-start+1)*x;
		tree[treeIdx].squareSum = (end-start+1)*x*x;
		if(start!=end){
			lazy[2*treeIdx].update = 0;
			lazy[2*treeIdx+1].update = 0;
			lazy[2*treeIdx].set = x;
			lazy[2*treeIdx+1].set = x;
		}
		lazy[treeIdx].set = 0;
	}
	if(lazy[treeIdx].update!=0){
		ll x = lazy[treeIdx].update;
		tree[treeIdx].squareSum += (end-start+1)*x*x + 2*x*(tree[treeIdx].sum);
		tree[treeIdx].sum += (end-start+1)*x;
		if(start!=end){
			lazy[2*treeIdx].update += x;
			lazy[2*treeIdx+1].update += x;
		}
		lazy[treeIdx].update = 0;
	}
	if(end<left || start>right){
		return;
	}
	if(start>=left && end<=right){
		if(qtype==0){
			// Set
			tree[treeIdx].squareSum = val*val*(end-start+1);
			tree[treeIdx].sum = val*(end-start+1);
			if(start!=end){
				lazy[2*treeIdx].update = 0;
				lazy[2*treeIdx+1].update = 0;
				lazy[2*treeIdx].set = val;
				lazy[2*treeIdx+1].set = val;
			}
		}else{
			tree[treeIdx].squareSum += val*val*(end-start+1)+2*val*(tree[treeIdx].sum);
			tree[treeIdx].sum += val*(end-start+1);
			if(start!=end){
				lazy[2*treeIdx].update += val;
				lazy[2*treeIdx+1].update += val;
			}
		}
		return;
	}
	ll mid = (start+end)/2;
	updateTree(tree,lazy,start,mid,2*treeIdx,qtype,left,right,val);
	updateTree(tree,lazy,mid+1,end,2*treeIdx+1,qtype,left,right,val);
	tree[treeIdx].squareSum = tree[2*treeIdx].squareSum + tree[2*treeIdx+1].squareSum;
	tree[treeIdx].sum = tree[2*treeIdx].sum+tree[2*treeIdx+1].sum;
}

node query(node* tree, lnode* lazy,ll start,ll end,ll treeIdx,ll left,ll right){
	if(start>end){
		node ans;
		ans.squareSum = 0;
		ans.sum = 0;
		return ans;
	}
	if(lazy[treeIdx].set!=0){
		ll x = lazy[treeIdx].set;
		tree[treeIdx].sum = (end-start+1)*x;
		tree[treeIdx].squareSum = (end-start+1)*x*x;
		if(start!=end){
			lazy[2*treeIdx].update = 0;
			lazy[2*treeIdx+1].update = 0;
			lazy[2*treeIdx].set = x;
			lazy[2*treeIdx+1].set = x;
		}
		lazy[treeIdx].set = 0;
	}
	if(lazy[treeIdx].update!=0){
		ll x = lazy[treeIdx].update;
		tree[treeIdx].squareSum += (end-start+1)*x*x + 2*x*tree[treeIdx].sum;
		tree[treeIdx].sum += (end-start+1)*x;
		if(start!=end){
			// lazy[2*treeIdx].set = 0;
			// lazy[2*treeIdx+1].set = 0;
			lazy[2*treeIdx].update += x;
			lazy[2*treeIdx+1].update += x;
		}
		lazy[treeIdx].update = 0;
	}
	if(start>right || end<left){
		node ans;
		ans.squareSum = 0;
		ans.sum = 0;
		return ans;
	}

	if(start>=left && end<=right){
		return tree[treeIdx];
	}
	int mid = (start+end)/2;
	node leftAns = query(tree,lazy,start,mid,2*treeIdx,left,right);
	node rightAns = query(tree,lazy,mid+1,end,2*treeIdx+1,left,right);
	node ans;
	ans.squareSum = leftAns.squareSum+rightAns.squareSum;
	ans.sum = leftAns.sum+rightAns.sum;
	return ans;
}

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		cout<<"Case "<<i<<":"<<endl;
		ll n,q;
		cin>>n>>q;
		ll *arr = new ll[n];
		for(ll j=0;j<n;j++) 
			cin>>arr[j];
		node *tree = new node[4*n];
		lnode *lazy = new lnode[4*n];
		for(ll j=0;j<4*n;j++){
			lazy[j].set = 0;
			lazy[j].update = 0;
		}
		buildTree(arr,tree,0,n-1,1);
		while(q--){
			int qtype;
			cin>>qtype;
			if(qtype==2){
				ll left,right;
				cin>>left>>right;
                left--,right--;
				node ans = query(tree,lazy,0,n-1,1,left,right);
				cout<<ans.squareSum<<endl;
			}
			else{
				ll left,right,val;
				cin>>left>>right>>val;
                left--,right--;
				updateTree(tree,lazy,0,n-1,1,qtype,left,right,val);
			}
		}
	}
}