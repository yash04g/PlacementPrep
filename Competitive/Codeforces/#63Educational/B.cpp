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
#define vpll vector<pair<ll,ll> >
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int> m;
    fo(i,n){
        m[s[i]]++;
    }
    int req = ((n-11)+2)/2;
    if(m['8']<req){
        cout<<"NO"<<endl;
    }else{
        bool flag = true;
        int cnt = 0;
        fo(i,2*req-1){
            if(s[i]=='8'){
                cnt++;
            }
        }
        if(cnt>=req){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}