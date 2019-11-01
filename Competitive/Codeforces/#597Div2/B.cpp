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
    	ll n;
        cin>>n;
        ll a,b,c;
        cin>>a>>b>>c;
        string seq;
        cin>>seq;
        ll numWins = n/2;
        if(n&1){
            numWins += 1;
        }
        string req = "";
        ll cnt = 0;
        fo(i,n){
            if(seq[i]=='P'){
                if(c>0){
                    c--;
                    req += 'S';
                    cnt++;
                }else{
                    req += 'a';
                }   
            }
            if(seq[i]=='S'){
                if(a>0){
                    a--;
                    req += 'R';
                    cnt++;
                }else{
                    req += 'a';
                }
                
            }
            if(seq[i]=='R'){
                if(b>0){
                    b--;
                    req += 'P';
                    cnt++;
                }else{
                    req += 'a';
                }
                
            }
        }
        fo(i,n){
            if(req[i]=='a'){
                if(a>0){
                    req[i] = 'R';
                    a--;
                    
                }else if(b>0){
                    req[i] = 'P';
                    b--;
                }else{
                    req[i] = 'S';
                    c--;
                }
            }
        }
        
        if(cnt>=numWins){
            cout<<"YES"<<endl<<req<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}