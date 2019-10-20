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
bool isPowerOfTwo (ll x){  
    return (!(x&(x-1ll)));  
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
    	bool flag = false;
    	int cnt = 0;
    	for(int i=0;i<18;i++){
    		if(n%10ll==0ll){
    			n = n/10ll;
    			cnt++;
    		}
    	}
    	if(n==1){
    		flag = true;
    	}
    	else if(isPowerOfTwo(n) && n!=0){
    		int cnt1 = 0;
    		ll temp = n;
    		while((temp&1ll) == 0ll){
    			temp = temp>>1ll;
    			cnt1++;
    		}
    		if(cnt1<=cnt){
    			flag = true;
    		}else{
    			flag = false;
    		}
    	}
    	else{
    		flag = false;
    	}
    	if(flag){
    		cout<<"Yes"<<endl;
    	}else{
    		cout<<"No"<<endl;
    	}
    }
}