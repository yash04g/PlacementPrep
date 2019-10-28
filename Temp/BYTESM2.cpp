#include<bits/stdc++.h>
#define FOR(i,a,b) for(auto i=(a);i<=(b);i++)
#define elif else if
#define FORA(x,arr) for(auto &x:arr)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define fio freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define ll long long
#define mod1 1000000007
using namespace std;
int main(){
	fastio
	fio
	int n;
	cin>>n;
	int arr[n];
	FORA(x,arr)	cin>>x;
	int dp[2][n];
	if(arr[n-1]==0)
		dp[n-1]=1;
	else
		dp[n-1]=0;
	for(int i=n-2;i>=0;i--){
		int mxs=0,mxc=0;
		for(int j=i+1;j<n;j++){
			if(arr[j]==)
		}
	}