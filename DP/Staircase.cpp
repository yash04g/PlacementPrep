#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define ll long long int
long staircase(int n){
	if(n<=0)
		return 1;
	if(n==1 || n==2){
		return n;
	}
	return staircase(n-1)+staircase(n-2)+staircase(n-3);
}
long staircaseHelper(int n,vector<ll> &dp){
	if(n<=0)
		return 1;
	if(n==1 || n==2){
		return n;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	dp[n] = staircaseHelper(n-1,dp)+staircaseHelper(n-2,dp)+staircaseHelper(n-3,dp);
	return dp[n];
}
long staircaseMemoization(int n){
	if(n<=0){
		return 1;
	}
	vector<ll> dp(n+1,-1);
	return staircaseHelper(n,dp);
}
long staircaseDP(int n){
	vector<ll> dp(n+1,-1);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for(int i=3;i<=n;i++){
		dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
	}
	return dp[n];
}
int main(){

}