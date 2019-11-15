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
#define vpll vector<pair<ll,ll> >
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
    ll n,m;
    cin>>n>>m;
    vll x(n);
    vll p(m);
    fo(i,n) cin>>x[i];
    fo(i,m) cin>>p[i];
    // bool flag = false;
    // fo(i,m){
    //     if(p[i]==1){
    //         flag = true;
    //     }
    // }
    // ll g = x[0];
    // Fo(i,1,n){
    //     g = __gcd(g,x[i]);
    // }
    // if(g==1){
    //     cout<<"NO"<<endl;
    // }else{
    //     cout<<"YES"<<endl<<x[0]<<" ";
    //     ll p1;
    //     fo(i,m){
    //         if(p[i]==g){
    //             p1 = i+1;
    //             break;
    //         }
    //     }
    //     cout<<p1<<endl;
    // }
    vll diff;
    fo(i,n-1){
        diff.pb(x[i+1]-x[i]);
    }
    ll g = diff[0];
    Fo(i,1,diff.size()){
        g = __gcd(g,diff[i]);
    }
    bool flag = false;
    ll idx = -1;
    fo(i,m){
        if(p[i]==1){
            flag = true;
            idx = i;
        }
    }
    if(g==1 && !flag){
        cout<<"NO"<<endl;
    }else if(g==1 && flag){
        cout<<"YES"<<endl<<x[0]<<" "<<idx+1<<endl;
    }else{
        
        ll p1 = -1;
        fo(i,m){
            if(g%p[i]==0 || g==p[i]){
                p1 = i+1;
                break;
            }
        }
        if(p1!=-1)
            cout<<"YES"<<endl<<x[0]<<" "<<p1<<endl;
        else
            cout<<"NO"<<endl;
    }

}