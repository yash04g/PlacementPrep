#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double>

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    fo(i,n){
    	cin>>a[i];
    }
    ll neg = 0;
    ll cnt1 = 0;
    ll cnt2 = 0;
    ll ans_p = 0;
    fo(i,n){
    	if(neg%2==0){
    		cnt1++;
    	}else{
    		cnt2++;
    	}
    	if(a[i]<0){
    		neg++;
    	}
    	if(neg%2==0){
    		ans_p += cnt1;
    	}else{
    		ans_p += cnt2;
    	}
    }
    ll ans_n = (n*(n+1))/2 - ans_p;
    cout<<ans_n<<" "<<ans_p<<endl;

}
