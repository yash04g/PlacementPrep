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
#define fo(i,n) for(ll i=0;i<n;++i)
#define Fo(i,k,n) for(ll i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1000000007 
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"
ll Divisors(ll n){  
    ll ans = n;
    
    for(ll i = 2;i<=sqrt(n);i++){
        if(n%i==0){
            ans = __gcd(ans,i);
            ans = __gcd(ans,n/i);
        }
    }
    return ans;
}
bool is_prime(ll n) {
    for(ll i =2;i<=((ll)sqrt(n));i++){
        if(n%i==0){
            return false;
        }
        // cout<<1<<endl;
    }
    return true;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    ll n;
    cin>>n;
    if(n==1){
        cout<<1<<endl;
        exit(0);
    }
    if(is_prime(n)){
        cout<<n<<endl;
    }else{
        ll ans = Divisors(n);
        cout<<ans<<endl;
    }
}