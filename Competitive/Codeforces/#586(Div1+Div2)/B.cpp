#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define vvll vector<vector<ll> >
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

int main(){
	// ios::sync_with_stdio(false);
 //  	cin.tie(0);
 //  	cout.tie(0);
	ll n;
	cin>>n;
	vvll a(n,vll(n));
	fo(i,n){
		fo(j,n){
			cin>>a[i][j];
		}
	}
	vi ans(n);
	ll b2 = (ll)((a[0][1]*a[1][2])/a[0][2]);
	ll b = (ll)pow(b2,0.5);
	ans[1] = b;
	// exit(0);
	ans[0] = (ll)(a[0][1]/b);
	
	Fo(i,2,n){
		ans[i] = a[0][i]/ans[0];
	}
	fo(i,n){
		cout<<ans[i]<<" ";
	}
}