#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mi map<int,int>
#define mc map<char,int>  
#define pll pair<int,int>
#define pdd pair<double,double>
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

void get_it_done(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
const int N = 2e5+5;
int dp1[N];
int dp2[N];


int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	vi a(n+1);
    	Fo(i,1,n+1) cin>>a[i];
    	memset(dp1,0,sizeof(dp1));
    	memset(dp2,0,sizeof(dp2));
    	dp1[1] = dp2[n] = 1;
    	Fo(i,2,n+1){
    		if (a[i] > a[i - 1]) 
    			dp1[i] = dp1[i - 1] + 1;
			else
				dp1[i] = 1;
    	}
    	for(int i=n-1;i>=0;i--){
    		if (a[i] < a[i + 1]) 
    			dp2[i] = dp2[i + 1] + 1;
			else 
				dp2[i] = 1;
    	}
    	int ans = 0;
    	Fo(i,2,n){
    		if (a[i+1]>a[i-1]){
				ans = max(ans, dp1[i-1] + dp2[i+1]);
			}
    	}
    	Fo(i,1,n+1){
    		ans = max(dp1[i], max(ans, dp2[i]));
    	}
    	cout<<ans<<endl;
    }
}
