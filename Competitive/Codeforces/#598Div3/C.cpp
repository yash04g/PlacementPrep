#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define vvll vector<vector<ll> >
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define fo(i,n) for(ll i=0;i<n;++i)
#define Fo(i,k,n) for(ll i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1000000007 
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"
#define inf 1000000005
int main(){
    ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        int n,m,d;
        cin>>n>>m>>d;
        vi c(m);
        int x = 0;
        fo(i,m) cin>>c[i];
        fo(i,m) x += c[i];
        vi ans(n);
        sort(c.begin(),c.end());
        
        
        

    }
}