#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long int

int minCount(int n){
	if(n<=3){
		return n;
	}
	int ans = INT_MAX;
	for(int i=1;i<=(int)sqrt(n);i++){
		ans = min(ans,1+minCount(n-i*i));
	}
	return ans;
}
int minCountHelper(int n,vector<int> &dp){
	if(n<=3){
		return n;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	int ans = INT_MAX;
	for(int i=1;i<=(int)sqrt(n);i++){
		ans = min(ans,1+minCountHelper(n-i*i,dp));
	}
	dp[n] = ans;
	return dp[n];
}
int minCountMemoization(int n){
	vector<int> dp(n+1,-1);
	return minCountHelper(n,dp);
}
int minCountDP(int n){
	vector<int> dp(n+1,-1);
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for(int i=4;i<=n;i++){
		int ans = i;
		for(int j=1;j<=(int)sqrt(n);j++){
			ans = min(ans,1+dp[i-j*j]);
		}
		dp[i] = ans;
	}
	return dp[n];
}
int main(){

}