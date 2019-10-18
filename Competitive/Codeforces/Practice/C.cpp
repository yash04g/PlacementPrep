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
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
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
    int n;
    cin>>n;
    vi a(n+1);
    ll sum = 0;
    Fo(i,1,n+1){
        cin>>a[i];
        sum += a[i];
    }
    // if(n<=2){
    //     cout<<0<<endl;
    //     exit(0);
    // }
    // if(n==3 && (a[1]==a[2] && a[3]==a[2])){
    //     cout<<1<<endl;
    //     exit(0);
    // }
    if(sum%3!=0){
        cout<<0<<endl;
    }else{
        ll presum = 0;
        ll ways = 0;
        ll cnt = 0;
        Fo(i,1,n){
            presum += a[i];
            if(presum == (2*sum/3)){
                ways += cnt;
            }
            if(presum == (sum/3)){
                cnt++;
            }
        }
        cout<<ways<<endl;
    }
}