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
#define mod 1e9+7 
#define endl "\n"
#define inf 1e18
void get_it_done(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}


int main(){
	get_it_done();
    int n;
    cin>>n;
    vvll p(n+1);
    vll ans(n+1,0);
    bool visited[200005];
    memset(visited,0,sizeof(visited));
    fo(i,n-2){
    	ll a,b,c;
    	cin>>a>>b>>c;
    	p[a].pb(b);
    	p[a].pb(c);
    	p[b].pb(a);
    	p[b].pb(c);
    	p[c].pb(a);
    	p[c].pb(b);
    }
    ll parity = 0;
    Fo(i,1,n+1){
    	if(p[i].size()==2){
    		if(parity==0){
    			ans[1] = i;
    			visited[i] = 1;
    			for(auto j:p[i]){
    				if(p[j].size()==4){
    					ans[2] = j;
    					visited[j] = 1;
    					break;
    				}
    			}
    			parity = 1;
    		}else{
    			ans[n] = i;
    			visited[i] = 1;
    			for(auto j:p[i]){
    				if(p[j].size()==4){
    					ans[n-1] = j;
    					visited[j] = 1;
    					break;
    				}
    			}
    		}
    	}
    }
    fo(i,n+1){
    	sort(all(p[i]));
    }
    Fo(i,3,n-1){
    	ll curr = ans[i-1];
    	ll x = p[curr].size();
    	Fo(j,1,x){
    		if(p[curr][j]==p[curr][j-1] && !visited[p[curr][j]]){
    			ans[i] = p[curr][j];
    			visited[p[curr][j]] = 1;
    			break;
    		}
    	}
    }
    Fo(i,1,n+1){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
}
