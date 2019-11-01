#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(ll i=0;i<n;++i)
#define Fo(i,k,n) for(ll i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1000000007 
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"
int dp[100005];
void initialize(){
    memset(dp,0,sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    Fo(i,4,100005){
        dp[i] = ((dp[i-2])%mod+(dp[i-1])%mod)%mod;
    }
}
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    initialize();
    string s;
    cin>>s;
    fo(i,s.size()){
        if(s[i]=='w' || s[i]=='m'){
            cout<<0<<endl;
            exit(0);
        }
    }
    ll ways = 1;
    int i = 0;
    while(i<s.size()){
        int n=0,u=0;
        if(s[i] == 'n'){
            while(i < s.length() && s[i] == 'n'){
                n++;
                i++;
            }
        }
 		else if(s[i] == 'u'){
            while(i < s.length() && s[i] == 'u'){
                u++;
                i++;
            }
        }
 		else{ 
            i++;
        }
 		if(n > 0)
            ways = ((ways%mod)*(dp[n]%mod)%mod);
 		if(u > 0)
            ways = ((ways%mod)*(dp[u]%mod)%mod);
        
    }
    ways %= mod;
    cout<<ways<<endl;

}