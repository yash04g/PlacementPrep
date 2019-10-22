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
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	vi p(n+1);
    	Fo(i,1,n+1) cin>>p[i];
    	vi ans(n+1,1);
    	map<int,int> m;
    	Fo(i,1,n+1){
    		m[i] = p[i];
    	}
    	while(!m.empty()){
    		int i = (*m.begin()).first;
    		int start = i;
    		int end = m[i];
    		vi a;
    		a.pb(i);
    		while(i!=end){
    			a.pb(end);
    			start = end;
    			end = m[start];
    		}
    		for(int j : a){
    			ans[j] = a.size();
    			m.erase(j);
    		}
    	}
    	Fo(i,1,n+1){
    		cout<<ans[i]<<" ";
    	}
    	cout<<endl;
    }
}