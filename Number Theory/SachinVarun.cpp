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
class triplet{
public:
	ll x;
	ll y;
	ll gcd;
};

triplet extendedGCD(ll a,ll b){
	if(b==0){
		triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}
	triplet smallAns = extendedGCD(b,a%b);
	triplet ans;
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.y;
	ans.y = smallAns.x-(a/b)*smallAns.y;
	return ans;
}

ll multiplicativeModuloInverse(ll a,ll m){
	triplet ans = extendedGCD(a,m);
	return (ans.x%m+m)%m;
}


int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	ll a,b,d;
        cin>>a>>b>>d;
        ll g = __gcd(a,b);
        if(d%g){
			cout<<0<<endl;
			continue;
		}
		if(d==0){
			cout<<1<<endl;
			continue;
		}
        a /= g;
        b /= g;
        d /= g;
        ll ans = 0;
        ll y1 = ((d%a)*multiplicativeModuloInverse(b,a))%a;
        if(y1>(d/b)){
            cout<<0<<endl;
            continue;
        }
        ans = ((d/b)-y1)/a;
        ans++;
        cout<<ans<<endl;
    }
}