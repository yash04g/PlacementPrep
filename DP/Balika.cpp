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
int dp[105][105][105];
// int helper(string s1,string s2,int k,int i,int j,int m,int n){
// 	if(k==0){
// 		return 0;
// 	}
// 	if(i==m || j==n){
// 		if(k>0){
// 			return INT_MIN;
// 		}else{
// 			return 0;
// 		}
// 	}
// 	if(dp[i][j][k]>-1){
// 		return dp[i][j][k];
// 	}
// 	if(s1[i]==s2[j]){
// 		if(k>0){
// 			return dp[i][j][k] = max(s1[i]+helper(s1,s2,k,i+1,j+1,m,n),max(helper(s1,s2,k,i+1,j,m,n),helper(s1,s2,k,i,j+1,m,n)));
// 		}else{
// 			return 0;
// 		}
// 	}
// 	return dp[i][j][k] = max(helper(s1,s2,k,i+1,j,m,n),helper(s1,s2,k,i,j+1,m,n));
// }
int helper(string s1,string s2,int k){
	int m = s1.length();
	int n = s2.length();
	if(k<=0){
		return 0;
	}
	if(m==0 || n==0){
		return INT_MIN;
	}
	if(dp[m][n][k]>-1){
		return dp[m][n][k];
	}
	if(s1[0]==s2[0]){
		return dp[m][n][k] = max(s1[0]+helper(s1.substr(1),s2.substr(1),k-1),max(helper(s1,s2.substr(1),k),helper(s1.substr(1),s2,k)));
	}else{
		return dp[m][n][k] = max(helper(s1.substr(1),s2,k),helper(s1,s2.substr(1),k));
	}
}
int solve(string s1,string s2,int k){
	int m = s1.length();
	int n = s2.length();
	memset(dp,0,sizeof(dp));
	return helper(s1,s2,k);
}
int main(){
    int t;
    cin >> t;
    while (t--){
    	string s1,s2;
    	cin>>s1>>s2;
    	int k;cin>>k;
    	int ans = solve(s1,s2,k);
    	if(ans<0){
    		ans = 0;
    	}
    	cout<<ans<<endl;
    }
}