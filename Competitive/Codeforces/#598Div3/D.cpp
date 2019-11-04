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
        ll n,k;
        string s;
        cin>>n>>k>>s;
        int idx=-1,oi=-1;
        if(s[0]=='0'){
            idx = 0;
        }else{
            oi = 0;
        }
        Fo(i,1,n){
            if(s[i]=='1' && s[i-1]=='0'){
                oi = i;
            }
            if(k>0){
                if(s[i]=='0' && s[i-1]!='0'){
                    int shift = i-oi;
                    if(shift>k){
                        s[i-k] = '0';
                        s[i] = '1';
                        k = 0;
                        break;
                    }else{
                        k -= shift;
                        s[oi] = '0';
                        s[i] = '1';
                        oi++;
                    }
                }
            }
        }
        cout<<s<<endl;
    }
}