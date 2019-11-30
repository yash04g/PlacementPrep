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
    	ll i, j, k, n, m, ans = 0, cnt = 0;
		cin >> n;
		string s[n];
		map<string, ll> mp;
		for (i = 0; i < n; i++) {
			cin >> s[i];
			mp[s[i]] ++;
		}
		for (i = 0; i < n; i++) {
			if (mp[s[i]] >= 2) {
				bool bl = false;
				for (k = 0; k < 4; k++) {
					for (j = 0; j <= 9; j++) {
						if (s[i][k] - '0' == j) continue;
						string t = s[i];
						t[k] = ('0' + j);
						if (mp[t]) continue;
						cnt++;
						mp[t]++;
						mp[s[i]]--;
						if (mp[s[i]] == 0) mp.erase(s[i]);
						s[i] = t;
						bl = true;
						break;
					}
					if (bl) break;
				}
			}
		}
		cout << cnt << endl;
		for (i = 0; i < n; i++) {
			cout << s[i] << endl;
		}
    }
}
