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
vi allprimes;
vi notprime;
bool prime[10005];
void sieve(){
	fo(i,10005) prime[i] = 1;
	prime[0] = 0;
	prime[1] = 0;
	for(int i=2;i*i<=10005;i++){
		if(prime[i]){
			for(int j=i*i;j<10005;j += i){
				prime[j] = false;
			}
		}
	}
}
int numPrimes(int n){
	int ans = 0;
	Fo(i,2,n+1){
		if(prime[i]){ ans++; allprimes.pb(i);}
		else notprime.pb(i);
	}
	return ans;
}
 
int32_t main(){
	get_it_done();
    int t=1;
    // cin >> t;
    sieve();
    while (t--){
    	int r,c;
    	cin>>r>>c;
    	if(r==1 && c==1){
    		cout<<0<<endl;
    		continue;
    	}
    	vvi ans(r,vi(c,1));
    	int p = numPrimes(r+c);
    	// if(p>=max(r,c)){
    	// 	if(r>c){
 
    	// 		// fo(i,r) fo(j,c) ans[i][j] = allprimes[j];
    	// 		// Fo(i,1,r) fo(j,c) (ans[i][j] *= notprime[i-1]);
    	// 		// vvi trans(r,vi(c,1));
    	// 		// fo(i,r){
    	// 		// 	fo(j,c){
    	// 		// 		trans[j][i] = ans[i][j];
    	// 		// 	}
    	// 		// }
 
    	// 	}else{
    	// 		fo(i,r) fo(j,c) ans[i][j] = allprimes[j];
    	// 		Fo(i,1,r) fo(j,c) (ans[i][j] *= notprime[i-1]);
    	// 		fo(i,r){
    	// 			fo(j,c){
	    // 				cout<<ans[i][j]<<" ";
    	// 			}
    	// 			cout<<endl;
    	// 		}
    	// 	}
 			if(c==1){
 				fo(i,r){
 					cout<<i+2<<endl;
 				}
 				continue;
 			}
 
    		fo(i,r){
    			fo(j,c){
    				ans[i][j] = (j+2);
    			}
    		}
    		Fo(i,1,r){
    			fo(j,c){
    				ans[i][j] *= (c+1+i);
    			}
    		}
    		fo(i,r){
    				fo(j,c){
	    				cout<<ans[i][j]<<" ";
    				}
    				cout<<endl;
    		}
 
    	// }
 
    }
}