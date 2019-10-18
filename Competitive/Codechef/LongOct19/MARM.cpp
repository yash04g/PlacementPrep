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
    int t;
    cin >> t;
    while (t--){
    	ll n,k;
    	cin>>n>>k;
    	vll a(n);
    	vll b(n);
    	fo(i,n) cin>>a[i];
    	fo(i,n) b[i] = a[i];
    	if(n<k){
    		fo(i,n){
    		    if((k/n)%3==2){
    		    	a[i] = a[i]^a[n-1-i];
    		    }else if((k/n)%3==1){
    		    	a[i] = a[i]^a[n-1-i];
    		    }else{
    		    	a[i] = a[i];
    		    }
    		}
    		fo(i,n){
    			if((k/n)%3==2){
    				a[i] = a[i]^a[n-1-i];
    			}
    		}
    		fo(i,(k%n)){
    			a[i] = a[i]^a[n-i-1];
    		}
    		if(n%2!=0){
    			a[n/2] = 0;
    		}
    	}else{
    		fo(i,k){
    			a[i] = a[i]^a[n-i-1];
    		}
    	}
    	fo(i,n){
    		cout<<a[i]<<" ";
    	}
    	cout<<endl;
    }
}