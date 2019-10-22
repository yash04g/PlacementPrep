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
    int n,c;
    cin>>n>>c;
    vi a(n);
    vi b(n);
    fo(i,n-1) {cin>>a[i];}
    fo(i,n-1){
    	cin>>b[i]; 
    }
   	ll dp[n][2];
   	dp[0][0] = a[0];
   	dp[0][1] = b[0]+c;
   	Fo(i,1,n-1){
   		dp[i][0] = a[i] + min(dp[i-1][0],dp[i-1][1]);
   		dp[i][1] = b[i] + min(dp[i-1][0]+c,dp[i-1][1]);
   	}
   	cout<<0<<" ";
   	fo(i,n-1){
   		cout<<min(dp[i][0],dp[i][1])<<" ";
   	}
}