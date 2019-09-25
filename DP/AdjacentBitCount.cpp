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
int dp[105][105][2];

int adjBC(int n,int k,int first){
	if(n==0){
		return 0;
	}
	if(n==1){
		if(k==0)
			return 1;
		else
			return 0;
	}
	if(dp[n][k][first]>-1){
		return dp[n][k][first];
	}
	int retval = -1;
	if(first==1){
		retval = adjBC(n-1,k-1,1)+adjBC(n-1,k,0);
	}else{
		retval = adjBC(n-1,k,1)+adjBC(n-1,k,0);
	}
	return dp[n][k][first] = retval;

}
int main(){
    int t;
    cin >> t;
    while (t--){
    	memset(dp,-1,sizeof(dp));
    	int num,n,k;
    	cin>>num>>n>>k;
    	int x = 0;
    	x += adjBC(n,k,0);
    	x += adjBC(n,k,1);
    	cout<<num<<" "<<x<<endl;
    }
}