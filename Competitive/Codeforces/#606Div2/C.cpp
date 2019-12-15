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
    	string s;
    	cin>>s;
    	int n = s.size();
    	vi ans;
    	// fo(i,n){
    	// 	if(i<n-2 && s[i]=='o'){
    	// 		if(s[i+1]=='n' && s[i+2]=='e'){
    	// 			if(i>1 && s[i-1]=='o'){
    	// 				ans.pb(i+1+1);
    	// 			}
    	// 			else if(i>1 && s[i-1]!='w'){
    	// 				ans.pb(i+1);
    	// 			}else if(i>1 && s[i-2]=='t' && s[i-1]=='w'){
    	// 				continue;
    	// 			}
    	// 			else{
    	// 				ans.pb(i+1);
    	// 			}
    	// 		}
    	// 	}
    	// 	if(i<n-2 && s[i]=='t'){
    	// 		if(s[i+1]=='w' && s[i+2]=='o'){
    	// 			if(s[i+3]=='o' && i<n-3){
    	// 				ans.pb(i+1+1);
    	// 			}else{
    	// 				ans.pb(i+2+1);
    	// 			}
    	// 		}
    	// 	}
    	// }
    	fo(i,n){
    		if(i<n-2 && s[i]=='o'){
    			if(i>1 && s[i-1]=='w' && s[i-2]=='t'){
    				continue;
    			}
    			if(s[i+1]=='n' && s[i+2]=='e'){
    				if(i>0 && s[i-1]=='o'){
    					ans.pb(i+1+1);
    				}else if(i<n-3 && s[i+3]=='e'){
    					ans.pb(i+1+1);
    				}
    				else{
    					ans.pb(i+2+1);
    				}

    			}
    		}
    		if(i<n-2 && s[i]=='t'){
    			if(s[i+1]=='w' && s[i+2]=='o'){
    				if(i<n-3 && s[i+3]=='o'){
    					ans.pb(i+1+1);
    				}else{
    					ans.pb(i+2+1);
    				}
    			}
    		}
    	}

    	cout<<ans.size()<<endl;
    	fo(i,ans.size()){
    		cout<<ans[i]<<" ";
    	}
    	cout<<endl;
    }
}
