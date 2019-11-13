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
#define fo(i,n) for(ll i=0;i<n;++i)
#define Fo(i,k,n) for(ll i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1e9+7 
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"
#define inf 1e9+5

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin>>n;
        vll a(n);
        fo(i,n) cin>>a[i];
        if(n<2){
            cout<<-1<<endl;
            continue;        
        }
        ll cnt = inf;
        map<ll,int> m;
        fo(i,n){
            if(m.find(a[i])!=m.end()){
                cnt = min(cnt,i-m[a[i]]+1);
            }
            m[a[i]] = i;
        }
        if(cnt == inf){
            cout<<-1<<endl;
        }else{
            cout<<cnt<<endl;
        }
    }
}