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
#define MAX 500001

vector<int> primes;

void sieve(){
    bool isPrime[MAX];

	for(int i=2;i<=MAX;i++){
		isPrime[i] = true;
	}
	for(int i=2;i*i<=MAX;i++){

		if(isPrime[i]){
			for(int j=i*i;j<=MAX;j+=i){
				isPrime[j] = false;
			}
		}
	}
	primes.push_back(2);
	for(int i=3;i<=MAX;i+=2){
		if(isPrime[i]){
			primes.push_back(i);
		}
	}
	return;
}

ll solve(ll n){
    
    ll ans = 1;
    
    for (int i=0; primes[i]<=n; i++) {
        int k = primes[i];
        ll count = 0;
        while (n/k!=0) {
            count = (count+n/k)%mod;
            k = k*primes[i];
        }
        
        ans = (ans * (count+1)%mod)%mod;
    }
    
    return ans;
}


int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	ll n;
        cin>>n;
        ll ans = solve(n);
        cout<<ans<<endl;
    }
}