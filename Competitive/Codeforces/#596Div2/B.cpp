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
    	int n,k,d;
    	cin>>n>>k>>d;
    	vi a(n);
    	fo(i,n) cin>>a[i];
    	int ans = INT_MAX;
    	map<int,int> m;
    	fo(i,d){
    		m[a[i]]++;
    	}
    	ans = m.size();
    	Fo(i,d,n){
    		m[a[i-d]]--;
    		if(m[a[i-d]]==0){
    			m.erase(a[i-d]);
    		}
    		m[a[i]]++;
    		ans = min(ans,(int)m.size());
    	}
    	cout<<ans<<endl;
    }	
}