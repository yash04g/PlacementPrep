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
        string s,t;
        cin>>s>>t;
        char c1;
        char c2;
        vector<char> s1;
        vector<char> s2;
        int cnt = 0;
        fo(i,n){
            if(s[i]!=t[i]){
                cnt++;
                if(cnt==1){
                    s1.pb(s[i]);
                    s1.pb(t[i]);
                }
                if(cnt==2){
                    s2.pb(s[i]);
                    s2.pb(t[i]);
                }
            }
            if(cnt>2)
                break;            
        }
        if(cnt==2){
            if((s1[0]==s2[0])&&(s1[1]==s2[1])){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<"NO"<<endl;
        }

    }
}