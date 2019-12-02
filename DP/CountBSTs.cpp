#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long 
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

int countBST(int n){
    if(n<=1){
        return 1;
    }
    vi dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3;i<=n;i++){
        int ans = 0;
        for(int j=1;j<=i;j++){
            // int temp = (int)(dp[j-1]*dp[i-j])%mod;
            ans = (ans+(int)(dp[j-1]*dp[i-j])%mod)%mod;
        }
        dp[i] += ans%mod;
    }
    return dp[n];
}
int main(){
    
}