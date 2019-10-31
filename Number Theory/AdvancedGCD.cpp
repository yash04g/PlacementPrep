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

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    if(b>a){
        return gcd(b,a);
    }
    return gcd(b,a%b);
}

ll advancedGCD(ll a,string b){
    ll x = 0;
    fo(i,b.size()){
        x = (x*10+(b[i]-'0'))%a;
    }
    return gcd(a,x);
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a;
        string b;
        cin>>a>>b;
        if(a==0){
            cout<<b<<endl;
            continue;
        }
        ll ans = advancedGCD(a,b);
        cout<<ans<<endl;
    }
}