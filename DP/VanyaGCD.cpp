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
#define pii pair<int,int>
#define pdd pair<double,double>
int dp[501][101];
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}
int count(vi &input,int n){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		dp[i][0] = 0;
	}
	dp[0][input[0]] = 1;
	for(int i=0;i<n;i++){
		for(int k=0;k<i;k++){
			if(input[k]<input[i]){
				for(int g=1;g<101;g++){
					int ng = gcd(input[i],g);
					dp[i][ng] = (dp[i][ng] + dp[i][g])%mod;
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans = (ans + dp[i][1])%mod;
	}
	return ans;
}
int main(){
    int n;
    cin>>n;
    vi input(n);
    fo(i,n)
    	cin>>input[i];
    cout<<count(input,n)<<endl;
}