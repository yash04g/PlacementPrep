#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double>
int N = 100005+5;
vvi tree(4*N,vi(26,0));

void buildTree(vi &arr,int start,int end,int treeIdx){
	if(start>end){
		return;
	}
	if(start==end){
		int x = arr[start];
		tree[treeIdx][x] = 1;
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr,start,mid,2*treeIdx);
	buildTree(arr,mid+1,end,2*treeIdx+1);
	for(int j=0;j<26;j++){	
        if(tree[2*treeIdx][j] > 0 || tree[2*treeIdx+1][j]>0 ){
            tree[treeIdx][j] = 1;
        }
        else tree[treeIdx][j] =0;
    }
}

void updateTree(vi &arr,int start,int end,int treeIdx,int pos,int val){
	if(start>pos || end<pos){
		return;
	}
	if(start==end && start==pos){
		int k = arr[pos];
		tree[treeIdx][k]--;
		if(tree[treeIdx][k]<0){
			tree[treeIdx][k] = 0;
		}
		tree[treeIdx][val]++;
		arr[pos] = val;
		return;
	}
	int mid = (start+end)/2;
	updateTree(arr,start,mid,2*treeIdx,pos,val);
	updateTree(arr,mid+1,end,2*treeIdx+1,pos,val);
	for(int j=0;j<26;j++){
        if(tree[2*treeIdx][j] > 0 || tree[2*treeIdx+1][j]>0 ){
            tree[treeIdx][j] = 1;
        }
        else tree[treeIdx][j] =0;
    }
}

vi query(vi &arr,int start,int end,int treeIdx,int left,int right){
	vi ans(26,0);
	if(start>end){
		return ans;
	}
	if(start>right || end<left){
		return ans;
	}
	if(start>=left && end<=right){
		return tree[treeIdx];
	}
	int mid = (start+end)/2;
	vi leftAns = query(arr,start,mid,2*treeIdx,left,right);
	vi rightAns = query(arr,mid+1,end,2*treeIdx+1,left,right);
	fo(j,26){
		if(leftAns[j]>0 || rightAns[j]>0){
			ans[j] = 1;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    string s;
    cin>>s;
    int n = s.size();
    vi arr(n+1);
    fo(i,s.size()){
    	int x = s[i]-'a';
    	arr[i] = x;
    }
    int q;
    cin>>q;
    buildTree(arr,0,n-1,1);
    while(q--){
    	int qtype;
    	cin>>qtype;
    	if(qtype==1){
    		int pos;
    		cin>>pos;
    		char c;
    		cin>>c;
    		int val = c-'a';
    		pos--;
    		updateTree(arr,0,n-1,1,pos,val);
    	}else{
    		int left,right;
    		cin>>left>>right;
    		left--,right--;
    		vi ans = query(arr,0,n-1,1,left,right);
    		int cnt = 0;
    		fo(i,26){
    			if(ans[i]>0){
    				cnt++;
    			}
    		}
    		cout<<cnt<<endl;
    	}
    }
}