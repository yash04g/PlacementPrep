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
    	vll pin(n);
        fo(i,n){
            cin>>pin[i];
        }
    	map<ll,ll> m;
        fo(i,n){
            m[pin[i]]++;
        }
    	ll moves = 0;
    	vll ans;
    	exit(0);
    	fo(i,n){
    		if(m[pin[i]]==1){
    			ans.pb(pin[i]);
    			m[pin[i]]--;
    		}else{
    			fo(i,9){
    				ll num = i+1;
    				bool flag = false;
    				while(num<10000){
    					if(m[pin[i]+num]==0){
    						ans.pb(pin[i]+num);
    						m[pin[i]+num]++;
    						flag = true;
    						break;
    					}else if(m[pin[i]-num]==0){
    						ans.pb(pin[i]-num);
    						m[pin[i]-num]++;
    						flag = true;
    						break;
    					}else{
    						num *=10;
    					}
    				}
    				++num;
    				if(flag){
                        moves+=1;
    					break;
    				}
    			}
    		}
    	}
    	cout<<moves<<endl;
    	fo(i,n){
    		cout<<ans[i]<<endl;
    	}
    }
}
