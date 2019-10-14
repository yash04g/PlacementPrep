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
#define pdd pair<double,double
#define endl "\n"

bool possible(vvi &edges,int n,int sv,int ev,vector<bool> &visited){
	if(sv==ev){
		return true;
	}
	visited[sv] = true;
	// for(int i=1;i<n;i++){
	// 	if(edges[sv][i]){
	// 		bool ans = possible(edges,n,i,ev);
	// 		if(ans){
	// 			return true;
	// 		}
	// 	}
	// }
	vector<int> :: iterator it;
	for(it=edges[sv].begin();it!=edges[sv].end();it++){
		if(!visited[*it]){
			bool ans = possible(edges,n,*it,ev,visited);
			if(ans){
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int n,t;
    cin>>n>>t;
    vi a(n);
    Fo(i,1,n) cin>>a[i];
    // int **edges = new int*[n];
	// for(int i=1;i<n;i++){
	// 	edges[i] = new int[n];
	// 	for(int j=1;j<n;j++){
	// 		edges[i][j] = 0;
	// 	}
	// }
	vvi edges(n+1);
	vector<bool> visited(n,0);
	for(int i=1;i<n;i++){
		edges[i].pb(i+a[i]);
	}
	// exit(0);
	if(possible(edges,n,1,t,visited)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
}