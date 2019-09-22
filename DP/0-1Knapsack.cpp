#include<bits/stdc++.h>
using namespace std;
int knapsackHelper(int* weights,int* values,int n,int maxWeight,int startIndex = 0){
	if(startIndex==n || maxWeight==0){
		return 0;
	}
	int val1 = knapsackHelper(weights,values,n,maxWeight,startIndex+1);
	int val2 = 0;
	if(maxWeight-weights[startIndex]<0){
		val2 = 0;
	}
	else
		val2 = values[startIndex] + knapsackHelper(weights,values,n,maxWeight-weights[startIndex],startIndex+1);
	int val = max(val1,val2);
	return val;
}
int knapsack(int* weights, int* values, int n, int maxWeight){
	return knapsackHelper(weights,values,n,maxWeight);		
}
int knapsackMemoizationHelper(int* weights, int* values, int n, int maxWeight,vector<vector<int> >&dp){
	if(n==0 || maxWeight==0){
		return 0;
	}
	if(dp[n][maxWeight]!=-1){
		return dp[n][maxWeight];
	}
	int val1 = knapsackMemoizationHelper(weights+1,values+1,n-1,maxWeight,dp);
	int val2 = 0;
	if(maxWeight-weights[0]<0){
		val2 = 0;
	}
	else
		val2 = values[0] + knapsackMemoizationHelper(weights+1,values+1,n-1,maxWeight-weights[0],dp);
	dp[n][maxWeight] = max(val1,val2);
	return dp[n][maxWeight];
}
int knapsackMemoization(int* weights, int* values, int n, int maxWeight){
	vector<vector<int> >dp(n+1,vector<int>(maxWeight+1,-1));
	return knapsackMemoizationHelper(weights,values,n,maxWeight,dp);
}
int knapsackDP(int* weights, int* values, int n, int maxWeight){
	vector<vector<int> >dp(n+1,vector<int>(maxWeight+1,-1));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=maxWeight;j++){
			if(i==0 || j==0){
				dp[i][j] = 0;
			}
			else if(j-weights[i-1]>=0){
				dp[i][j] = max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][maxWeight];
}

int main(){

}