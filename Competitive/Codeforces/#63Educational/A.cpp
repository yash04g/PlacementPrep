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
    int l = -1;
    int r = -1;
    int minima = s[0];
    l = 1;
    for(int i=1;i<n;i++){
        if(s[i]<minima){
            r = i+1;
            break;
        }else{
            minima = s[i];
            l = i+1;
        }
    }
    if(r!=-1){
        cout<<"YES"<<endl<<l<<" "<<r<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}