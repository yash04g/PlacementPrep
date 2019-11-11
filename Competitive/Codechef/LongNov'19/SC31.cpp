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
#define mod 1000000007 
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	int n;
        cin>>n;
        vector<string> a(n);
        fo(i,n) cin>>a[i];
        ll cnt = 0;
        vector<int> ans(10);
        fo(i,n){
            fo(j,10){
                ans[j] += (a[i][j]-'0');
            }
        }
        fo(i,10){
            if(ans[i]&1){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}