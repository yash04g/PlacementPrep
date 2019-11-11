#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define vvll vector<vector<ll> >
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define fo(i,n) for(ll i=0;i<n;++i)
#define Fo(i,k,n) for(ll i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1000000007 
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"
#define inf 1000000005

int main(){
    ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll m,n;
        cin>>n>>m;
        ll x = -1;
        ll ans = inf;
        bool flag = false;
        if(n%m==0){
            vvll a(m,vll(n/m));
        fo(i,n/m){
            fo(j,m){
                cin>>a[j][i];
            }
        }
        fo(i,m){
            sort(a[i].begin(),a[i].end());
        }        
        vll p(m);
        fo(i,m){
            p[i] = a[i].size()-1;
        }
        
        // ll ans = inf;
        while(1){
            ll maxima = -inf;
            ll minima = inf;
            ll x = -1;
            fo(i,m){
                if(maxima<a[i][p[i]]){
                    maxima = max(maxima,a[i][p[i]]);  
                    x = i;
                } 
                minima = min(minima,a[i][p[i]]); 
            }
            ans = min(ans,maxima-minima);
            p[x]--;
            if(p[x]<0){
                break;
            }
            // fo(i,m){
            //     if(a[i][p[i]]==maxima){
            //         p[i]--;
            //         if(p[i]<0){
            //             flag = true;
            //         }
            //     }
            // }
            // if(flag){
            //     break;
            // }   
        }
        }else{
            vvll a(m,vll((n-1)/m));
            fo(i,(n-1)/m){
                fo(j,m){
                    cin>>a[j][i];
                }
            }
            fo(i,n%m){
                ll temp;
                cin>>temp;
                a[i].pb(temp);
            }
            fo(i,m){
                sort(a[i].begin(),a[i].end());
            }
            vll p(m);
            fo(i,m){
                p[i] = a[i].size()-1;
            }
            while(1){
                
                ll maxima = -inf;
                ll minima = inf;
                ll x = -1;
                fo(i,m){
                    if(maxima<a[i][p[i]]){
                        maxima = max(maxima,a[i][p[i]]);
                        x = i;
                    }   
                    minima = min(minima,a[i][p[i]]); 
                }
                ans = min(ans,maxima-minima);
                p[x]--;
                if(p[x]<0){
                    break;
                }
                // fo(i,m){
                //     if(a[i][p[i]]==maxima){
                //         p[i]--;
                //     }
                //     if(p[i]<0){
                //         flag = true;
                //     }
                // }
                // if(flag){
                //     break;
                // }
            }
        }
        cout<<ans<<endl;
        
    }
}