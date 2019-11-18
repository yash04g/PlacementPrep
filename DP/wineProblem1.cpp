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
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1000000007 
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"

int dp[105][105];

int solve(int arr[],int be,int end,int year){
	if(dp[be][end]!=0) return dp[be][end];
	if(be>end){
		return 0;
	}
	int q1 = arr[be]*year + solve(arr,be+1,end,year+1);
	int q2 = arr[end]*year + solve(arr,be,end-1,year+1);
	return dp[be][end] = max(q1,q2);
}
int bottomUp(int arr[],int n){
	int year = n;
	for(int i=0;i<n;i++){
		dp[i][i] = year*arr[i];
	}
	year--;
	for(int len=2;len<=n;++len){
		int start = 0;
		int end = n-len;
		while(start<=end){
			int endWindow = start+len-1;
			dp[start][endWindow] = max(arr[start]*year + dp[start+1][endWindow],arr[endWindow]*year +dp[start][endWindow-1]);
			++start;
		}
		--year;
	}
	return dp[0][n-1];
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t=1;
    while (t--){
    	int arr[100];
    	int n;
    	cin>>n;
    	fo(i,n) cin>>arr[i];
    	memset(dp,0,sizeof(dp));
    	int ans = solve(arr,0,n-1,1);
    	cout<<ans<<endl;
    	memset(dp,0,sizeof(dp));
    	ans = bottomUp(arr,n);
    	cout<<ans<<endl;
    }
}