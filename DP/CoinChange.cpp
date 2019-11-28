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
int helper(int n,int *d,int numD,vvi &dp){
	if(n<0 || numD==0){
		return 0;
	}
	if(n==0){
		return 1;
	}
	if(dp[n][numD]>-1){
		return dp[n][numD];
	}
	int firstWay = helper(n-d[0],d,numD,dp);
	int secondWay = helper(n,d+1,numD-1,dp);
	return dp[n][numD] = firstWay+secondWay;
}
int coin_change(int n,int* d,int numD){
	vvi dp(n+1,vi(numD+1,-1));
	return helper(n,d,numD,dp);
}
int coin_changeDP(int n,int *d,int numD){
	vvi dp(n+1,vi(numD+1,-1));
}
int main(){
    int t;
    cin >> t;
    while (t--){

    }
}