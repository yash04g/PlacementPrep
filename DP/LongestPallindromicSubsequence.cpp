#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define vvll vector<vector<ll> >
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1e9+7 
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"
#define inf 1e9+5

int dp[1005][1005];

int helper(string s,int i,int j){
    if(i>j){
        return 0;
    }
    if(i==j){
      return 1;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    if(s[i]==s[j]){
        return dp[i][j] = helper(s,i+1,j-1)+2;
    }else{
        return dp[i][j] = max(helper(s,i+1,j),helper(s,i,j-1));
    }
}

int lps(string s){
    int n = s.size();
    memset(dp,0,sizeof(dp));
    return helper(s,0,n-1);
}

int lpsDP(string s){
    memset(dp,0,sizeof(dp));
    int n = s.size();
    for(int i=0;i<n;++i){
        dp[i][i] = 1;
    }
    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j = i+len-1;
            if(s[i]==s[j]){
                dp[i][j] = dp[i+1][j-1]+2;
            }else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int ans = lps(s);
    cout<<ans;
}