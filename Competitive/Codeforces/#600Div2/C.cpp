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
    ll n,m;
    cin>>n>>m;
    vll a(n);
    fo(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    ll sum = 0;
    vll ans(n,0);
 	fo(i,n){
 		sum += a[i];
 		ans[i] = sum;
 		if(i-m >= 0){
 			ans[i] += ans[i-m];
 		}
 	}
 	
  	fo(i,n){
  		cout << ans[i] << " ";
  	}
}