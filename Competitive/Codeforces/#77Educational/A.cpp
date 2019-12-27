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
int dp[N];


int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
    	int c,sum;
    	cin>>c>>sum;
    	int ans = 0;
    	if(c==1){
    		ans = sum*sum;
    		cout<<ans<<endl;
    		continue;
    	}
    	if(c>sum){
    		cout<<sum<<endl;	
    		continue;
    	}
    	int x = sum%c;
    	int y = sum/c;
    	fo(i,c){
    		if(x>0){
    			ans += ((y+1)*(y+1));
    			x--;
    		}else{
    			ans += y*y;
    		}
    	}
    	cout<<ans<<endl;
    }
}
