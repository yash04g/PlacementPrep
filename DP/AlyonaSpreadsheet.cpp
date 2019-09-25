#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
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
vector<int> go(vvi &inp,vvi &dp,int r,int c){
	Fo(i,1,r){
		fo(j,c){
			if(inp[i][j]>=inp[i-1][j]){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = i;
			}
		}
	}
	vi ans(r,INT_MAX);
	ans[0] = 0;
	Fo(i,1,r){
		int minima = INT_MAX;
		fo(j,c){
			minima = min(dp[i][j],minima);
		}
		ans[i] = minima;
	}
	return ans;
}
int main(){
	int r,c;
    cin>>r>>c;
    vvi inp(r,vi(c));
    vvi dp(r,vi(c,0));
   	fo(i,r){
   		fo(j,c){
   			cin>>inp[i][j];
   		}
   	}
    vi ans = go(inp,dp,r,c);
    int q;
    cin>>q; 
    while(q--){
    	int x,y;
    	cin>>x>>y;
    	y--;x--;
    	if(ans[y]<=x){
    		cout<<"Yes"<<endl;
    	}else{
    		cout<<"No"<<endl;
    	}
    }
}