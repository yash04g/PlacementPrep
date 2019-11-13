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
#define mod 1e9+7 
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"
#define inf 1e9+5

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n,x,a,b;
        cin>>n>>x>>a>>b;
        if(abs(a-b)==(n-1)){
            cout<<n-1<<endl;
            continue;
        }
        if(x==0){
            cout<<abs(a-b)<<endl;
            continue;
        }
        if(a>b){
            // cout<<a<<" "<<b<<endl;
            swap(a,b);
            // cout<<a<<" "<<b<<endl;
        }
        if(x>=(n-b)){
            x -= (n-b);
            b = n;
            if(x>=(a-1)){
                x -= (a-1);
                a = 1;
            }else{
                // x = 0;
                a -= x;
                x = 0;
            }

        }else{            
            b += x;
            x = 0;
            // cout<<b<<endl;
        }
        cout<<abs(a-b)<<endl;

    }
}