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
#define fo(i,n) for(ll i=0;i<n;++i)
#define Fo(i,k,n) for(ll i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1000000007 
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"

bool cmp(pair<int,ll> a,pair<int,ll> b){
    return a.second>b.second;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    ll t;
    cin >> t;
    while (t--){
    	ll n;
        cin>>n;
        vvll a(n);
        map<int,ll> first1;
        map<int,ll> last;
        fo(i,n){
            ll c;
            cin>>c;
            while(c--){
                ll temp;
                cin>>temp;
                a[i].pb(temp);
            }
            first1[a[i][0]] = i;
            last[a[i][c-1]] = i;
        }
        bool flag = true; // Chef
        ll chef = 0;
        ll ramsay = 0;
        while(a.size()>0){
            if(flag){
                ll idx = (*first1.rbegin()).second;
                if(a[idx].size()&1){
                    fo(i,a[idx].size()/2+1){
                        chef += a[idx][i];
                    }
                    Fo(i,a[idx].size()/2+1,a[idx].size()){
                        ramsay += a[idx][i];
                    }
                    flag = false;
                }else{
                    fo(i,a[idx].size()/2){
                        chef += a[idx][i];
                    }
                    Fo(i,a[idx].size()/2,a[idx].size()){
                        ramsay += a[idx][i];
                    }
                }
                ll t = *(a[idx].rbegin()); 
                last.erase(last[t]);
                a.erase(a.begin()+idx);
                first1.erase(prev(first1.end()));
                
            }else{
                ll idx = (*last.rbegin()).second;
                if(a[idx].size()&1){
                    fo(i,a[idx].size()/2){
                        chef += a[idx][i];
                    }
                    Fo(i,a[idx].size()/2,a[idx].size()){
                        ramsay += a[idx][i];
                    }
                    flag = true;
                }else{
                    fo(i,a[idx].size()/2){
                        chef += a[idx][i];
                    }
                    Fo(i,a[idx].size()/2,a[idx].size()){
                        ramsay += a[idx][i];
                    }
                }
                ll t = *(a[idx].begin());
                first1.erase(first1[t]);
                a.erase(a.begin()+idx);
                last.erase(prev(last.end()));
            }
        }
        cout<<chef<<endl;       
    }
}