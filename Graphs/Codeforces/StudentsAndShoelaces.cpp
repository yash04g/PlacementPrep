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
int solve(vvi &edges,int n,int sv){
	int cnt = 0;
	while(true){
		bool flag = true;
		vi indices;
		for(int i=1;i<=n;i++){
			if(edges[i].size()==1){
				indices.pb(i);
			}
		}
		if(indices.size()==0){
			break;
		}else{
			cnt++;		
		}
		fo(i,indices.size()){
			Fo(j,1,n){
				vector<int> :: iterator it;
				it = find(edges[j].begin(),edges[j].end(),indices[i]);
				if(it!=edges[j].end()){
					edges[j].erase(it);
				}
			}
		}
		fo(i,indices.size()){
			edges[indices[i]].clear();
		}

	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int n,m;
    cin>>n>>m;
	vvi edges(n+1);
	fo(i,m){
		int a,b;
		cin>>a>>b;
		edges[a].pb(b);
		edges[b].pb(a);
	}
	cout<<solve(edges,n,1)<<endl;

}