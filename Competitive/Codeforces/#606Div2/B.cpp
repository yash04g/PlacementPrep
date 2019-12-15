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
const int N = 1e5+5;
int dp[N];


int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	vi a(n);
    	fo(i,n) cin>>a[i];
    	set<int,greater<int> > s;
    	map<int,bool> m;
    	int maxima = 0;
    	fo(i,n){
    		if(!(a[i]&1)){
    			s.insert(a[i]);
    			m[a[i]] = true;
    		}
    	}
    	int moves = 0;
    	if(s.size()==0){
    		cout<<0<<endl;
    		continue;
    	}
    	for(auto x:s){
    		// cout<<x<<endl;
    		if(m[x]){
    			// cout<<1<<endl;
    			while(!(x&1)){
    				moves++;
    				x /= 2;
    				if(m[x]){
    					m[x] = false;
    				}
    				// cout<<x<<endl;
    			}
    		}
    	}
    	cout<<moves<<endl;
    	// exit(0);



    }
}
