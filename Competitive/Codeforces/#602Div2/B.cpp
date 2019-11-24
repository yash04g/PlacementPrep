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
    	ll n;
    	cin>>n;
    	vll a(n);
    	map<ll,ll> m1;
    	fo(i,n) cin>>a[i],m1[a[i]]++;
    	vll p(n);
    	p[0] = a[0];
    	bool flag = true;
    	if(a[0]>n){
    		flag = false;
    	}
    	Fo(i,1,n){
    		if(a[i]>n){
    			flag = false;
    			break;
    		}
    		if(a[i]==a[i-1]){
    			p[i] = -1;
    			if(a[i]-(i+1)<0){
    				flag = false;
    				break;
    			}
    		}
    		else{
    			p[i] = a[i];
    		}
    	}
    	if(!flag){
    		cout<<-1<<endl;
    		continue;
    	}
    	ll cnt = 1;
    	if(a[0]==cnt){
    		cnt += 1;
    	}
    	Fo(i,1,n){
    		if(p[i]==-1){
    			p[i] = cnt;
    			cnt += 1;
    		}
    		if(m1[cnt]>0){
    			cnt += 1;
    		}
    	}


    	fo(i,n){
    		cout<<p[i]<<" ";
    	}
    	cout<<endl;

    }
}
