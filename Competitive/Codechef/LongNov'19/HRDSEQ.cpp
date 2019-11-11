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

vi seq(129);
void initialize(){
    seq[1] = 0;
    seq[2] = 0;
    Fo(i,3,129){
        if(seq[i-1]==0){
            int x = -1;
            for(int j=i-2;j>=1;j--){
                if(seq[j]==0){
                    x = j;
                    break;
                }
            }
            int num = (i-1)-x;
            seq[i] = num;
        }else{
            int x = -1;
            int last = seq[i-1];
            for(int j=i-2;j>=1;j--){
                if(seq[j]==last){
                    x = j;
                    break;
                }
            }
            if(x==-1){
                seq[i] = 0;
                
            }else{
                int num = (i-1)-x;
                seq[i] = num;
            }
        }
    }
}
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    ll t;
    cin >> t;
    initialize();
    while (t--){
        int n;
        cin>>n;
        int x = seq[n];
        int cnt = 0;
        Fo(i,1,n+1){
            if(seq[i]==x){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}