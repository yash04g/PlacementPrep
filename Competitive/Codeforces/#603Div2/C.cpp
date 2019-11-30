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
    	ll a;
        cin >> a;
        set<ll> ans;
        ans.insert(0);
        for (ll i = 1; i <= sqrt(a); i++)
        {
            ans.insert(i);
            ans.insert(a / i);
        }
        cout << ans.size() << endl;
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
