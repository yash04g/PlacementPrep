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

bool isGood(ll n){
	while(n>1){
		if(n&1){
			return false;
		}
		n=n/2;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    ll n,p;
    cin>>n>>p;

    for(int i=0;i<=1e7;i++){ 
    	ll x = n-i*p;
    	ll temp = __builtin_popcount(x);
    	if(x<0)
       		break;
     
    	if(i>=temp && i<=x){
        	cout<<i;
        	exit(0);
    	}
 	}
  	cout<<-1;
}