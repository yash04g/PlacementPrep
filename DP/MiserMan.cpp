#include <bits/stdc++.h>
using namespace std;
int dp[105][105];
int minCost(vector<vector<int> > fare,int n,int m){
    for(int i=0;i<m;i++){
        dp[0][i] = fare[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(j!=0 && j!=m-1){
                dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i-1][j+1]))+fare[i][j];
            }
            if(j==0){
                dp[i][j] = min(dp[i-1][j],dp[i-1][j+1])+fare[i][j];
            }
            if(j==m-1){
                dp[i][j] = min(dp[i-1][j],dp[i-1][j-1])+fare[i][j];
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<m;i++){
        ans = min(ans,dp[n-1][i]);
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > fare(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>fare[i][j];
        }
    }
    cout<<minCost(fare,n,m);
}
