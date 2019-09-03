#include <bits/stdc++.h>
using namespace std;
int dp[31][10][2];
int maxProfit(vector<int>& stocks,int n,int k,int i,int isongoing){
    if(i==n){
        return 0;
    }
    if(dp[i][k][isongoing] > -1){
        return dp[i][k][isongoing];
    }
    int ans = maxProfit(stocks,n,k,i+1,isongoing);
    if(isongoing){
        int option1 = maxProfit(stocks,n,k-1,i+1,0)+stocks[i];
        ans = max(ans,option1);
    }else{
        if(k==0){
            ans = 0;
        }else{
            int option2 = maxProfit(stocks,n,k,i+1,1)-stocks[i];
            ans = max(ans,option2);
        }
    }
    dp[i][k][isongoing] = ans;
    return ans;   
}

int main(){
    int q;
    cin>>q;
    while(q--){
        int n,k;
        cin>>k>>n;
        vector<int> stocks(n);
        for(int i=0;i<n;i++){
            cin>>stocks[i];
        }
        memset(dp,-1,sizeof(dp));
        cout<<maxProfit(stocks,n,k,0,0)<<endl;
    }
}
