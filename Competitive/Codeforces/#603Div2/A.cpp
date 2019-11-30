#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define ll long long
#define fo(i,n) for(ll i=0;i<n;++i)
#define Fo(i,k,n) for(ll i=k;i<n;++i)
#define vll vector<ll>
#define vvll vector<vector<ll> >
#define vpll vector<pair<ll,ll> >
#define all(v) v.begin(),v.end()
#define mll map<ll,ll>
#define mc map<char,ll>  
#define pll pair<ll,ll>
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


int main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
		vll candy(3);
		ll ans=0;
		fo(i,3){
			cin>>candy[i];
		}
		sort(candy.begin(),candy.end());
		if(candy[0]==candy[1] && candy[1]==candy[2]){
			ans += (candy[0]+candy[1]+candy[2])/2;
		}
		else if(candy[1]==candy[2]){
			ll temp = candy[0]/2;
			ans += 2*temp + candy[1]-temp;
		}
		else{
			if(candy[0]+candy[1]<=candy[2]){
				ans += candy[0]+candy[1];
			}
			else{
				ans += (candy[0]+candy[1]+candy[2])/2;
			}
		}
		cout<<ans<<endl;

    }
}
