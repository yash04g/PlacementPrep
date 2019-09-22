#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int>&arr,int n,int sum){
    bool** dp = new bool*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new bool[sum+1];
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(j-arr[i-1]>=0){
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    bool ans =  dp[n][sum];
    // Delete array
    for(int i=0;i<=n;i++){
        delete []dp[i];
    }
    delete [] dp;
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    if(possible(arr,n,sum)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
