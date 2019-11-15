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
int dp1[10005];
int dp2[10005];
int longestBitonicSubarray(int *input, int n) {
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    dp1[0] = 1;
    dp2[n-1] = 1;
    if(input[1]>input[0]){
    	dp1[1] = 2;
    }else{
    	dp1[1] = 1;
    }
    if(input[n-2]>input[n-1]){
    	dp2[1] = 2;
    }else{
    	dp2[1] = 1;
    }
    Fo(i,2,n){
    	dp1[i] = 1;
    	int maxima = 0;
    	for(int j=0;j<i;j++){
    		if(input[i]>input[j] && dp1[i]<dp1[j]+1)
    			maxima = max(maxima,dp1[j]);
    	}
    	dp1[i] += maxima;
    }
    for(int i=n-3;i>=0;i--){
    	dp2[i] = 1;
    	int maxima = 0;
    	for(int j=n-1;j>i;j--){
    		if(input[i]>input[j] && dp2[i]<dp2[j]+1)
    			maxima = max(maxima,dp2[j]);
    	}
    	dp2[i] += maxima;
    }
    int ans1 = dp1[0]+dp2[0]-1;
    fo(i,n){
    	ans1 = max(dp1[i]+dp2[i]-1,ans1);
    }
    return ans1;
}
int main(){
    int t;
    cin >> t;
    while (t--){

    }
}