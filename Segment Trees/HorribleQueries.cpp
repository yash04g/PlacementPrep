#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void buildTree(ll *arr,ll *tree,ll start,ll end,ll idx){
	if(start>end){
		return;
	}
	if(start==end){
		tree[idx] = arr[start];
		return;
	}
	ll mid = (start+end)/2;
	buildTree(arr,tree,start,mid,2*idx);
	buildTree(arr,tree,mid+1,end,2*idx+1);
	tree[idx] = tree[2*idx]+tree[2*idx+1];
}

void updateTree(ll *tree,ll *lazy,ll start,ll end,ll idx,ll left,ll right,ll inc){
	if(start>end)
		return;
	if(lazy[idx]!=0){
		tree[idx] += lazy[idx]*(end-start+1);
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
		tree[idx] += (end-start+1)*inc;
		if(start!=end){
			lazy[2*idx] += inc;
			lazy[2*idx+1] += inc;
		}
		return;
	}
	ll mid = (start+end)/2;
	updateTree(tree,lazy,start,mid,2*idx,left,right,inc);
	updateTree(tree,lazy,mid+1,end,2*idx+1,left,right,inc);
	tree[idx] = tree[2*idx]+tree[2*idx+1];
}
ll query(ll *tree,ll *lazy,ll start,ll end,ll idx,ll left,ll right){
	if(start>end)
		return 0;
	if(lazy[idx]!=0){
		tree[idx] += lazy[idx]*(end-start+1);
		if(start!=end){
			lazy[2*idx] += lazy[idx];
			lazy[2*idx+1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if(start>right || end<left){
		return 0;
	}
	if(start>=left && end<=right){
		return tree[idx];
	}
	ll mid = (start+end)/2;
	ll leftAns = query(tree,lazy,start,mid,2*idx,left,right);
	ll rightAns = query(tree,lazy,mid+1,end,2*idx+1,left,right);
	return leftAns+rightAns;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,c;
		cin>>n>>c;
		ll *arr = new ll[n+1]();
		ll *lazy = new ll[4*n]();
		ll *tree = new ll[4*n]();
		buildTree(arr,tree,1,n,1);
		while(c--){
			ll qtype;
			cin>>qtype;
			if(qtype==0){
				ll p,q,v;
				cin>>p>>q>>v;
				updateTree(tree,lazy,1,n,1,p,q,v);
			}else{
				ll p,q;
				cin>>p>>q;
				cout<<query(tree,lazy,1,n,1,p,q);
			}
		}
	}

}