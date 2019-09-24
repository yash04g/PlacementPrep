#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
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
int dp[10005][10005];
int minCostPath(int **input,int m,int n){
	memset(dp,0,sizeof(dp));
	dp[n-1][n-1] = input[n-1][n-1];
	for(int i=m-2;i>=0;i--){
		dp[i][n-1] = input[i][n-1] + dp[i+1][n-1];
	}
	for(int j=n-2;j>=0;j--){
		dp[m-1][j] = input[m-1][j] + dp[m-1][j+1];
	}
	for(int i=m-2;i>=0;i--){
		for(int j=n-2;j>=0;j--){
			dp[i][j] = input[i][j] + min(dp[i+1][j],min(dp[i+1][j+1],dp[i][j+1]));
		}
	}
	return dp[0][0];
}
int main(){
    int t;
    cin >> t;
    while (t--){

    }
}