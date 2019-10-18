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

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	ll n,m,q;
    	cin>>n>>m>>q;
    	ll* row = new ll[n];
    	ll* col = new ll[m];
    	fo(i,n){
    		row[i] = 0;
    	}
    	fo(i,m){
    		col[i] = 0;
    	}
    	// vvi a(n+1,vi(m+1,0));
    	fo(i,q){
    		ll x,y;
    		cin>>x>>y;
    		x--;y--;
    		row[x] += 1;
    		col[y] += 1;
    	}
    	ll rowcnt = 0,colcnt = 0;
    	fo(i,n){
    		if((row[i]&1)==1)
    			rowcnt++;
    	}
    	fo(i,m){
    		if((col[i]&1)==1)
    			colcnt++;
    	}
    	ll ans = rowcnt*m+colcnt*n-2*rowcnt*colcnt;
    	cout<<ans<<endl;
    }
}