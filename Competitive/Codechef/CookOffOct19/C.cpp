#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	ll l,r;
    	cin>>l>>r;
    	ll i=0;
    	for(;i<65;i++){
    		if((1ll << i)<=r){
    			continue;
    		}else{
    			break;
    		}
    	}
    	i -= 1;
    	// cout<<i<<endl;
    	ll ans = 0;
    	if(((1ll << i))>l){
			// ans = ((1<<i)|((1<<i)-1));	
			ans = (1ll << (i+1))-1ll;
    	}
    	else if((1ll << i)==l){
    		ans = (1ll << i)|r;
    	}
    	else{
    		ans = (r|l);
    	}
    	// (1<<i)>l
    	// else{
    	// 	ans = -1;
    	// }
    	if(l==r){
    		ans = r;
    	}
    	cout<<ans<<endl;
    }
}