#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long
#define fo(i,n) for(ll i=0;i<n;++i)
#define Fo(i,k,n) for(ll i=k;i<n;++i)
#define vll vector<ll>
#define vvll vector<vector<ll> >
#define vpll vector<pair<ll,ll> >
#define all(v) v.begin(),v.end()
#define mll map<ll,ll>
#define mc map<char,ll>  
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define endl "\n"
#define inf 1e18
void get_it_done(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

bool cmp(pll a,pll b){
	return a.first<b.first;
}

int main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
    	ll n;
    	cin>>n;
    	vpll a(n);
    	fo(i,n){
    		ll x,y;
    		cin>>x>>y;
    		a[i] = mp(x,y);
    	}
    	ll l=1e9+5,r=0;
    	bool flag = true;
    	fo(i,n){
    		if(a[i].first>r){
    			r = a[i].first;
    		}
    		if(a[i].second<l){
    			l = a[i].second;
    		}
    	}
    	if(r-l<=0){
    		cout<<0<<endl;
    		continue;
    	}
    	cout<<r-l<<endl;
    }
}
