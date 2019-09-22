#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define pb push_back
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

ll gcd(ll a,ll b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int n;
    cin>>n;
    vll a(n);
    fo(i,n){
    	cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll x = a[n-1];
    ll y = 0;
   	ll z = a[n-1]+1;
    vll b;
    fo(i,n){
    	if(x-a[i]==0){
    		continue;
    	}
    	b.pb(x-a[i]);
    }
    sort(b.begin(),b.end());
    fo(i,b.size()-1){
    	ll g = gcd(b[i],b[i+1]);
    	z = min(z,g);
    }
    fo(i,b.size()){
    	y += b[i]/z;
    }
    if(b.size()==1){
    	y = 1;
    	z = b[0];
    }
    cout<<y<<" "<<z<<endl;
}