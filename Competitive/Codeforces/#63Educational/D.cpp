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
    ll n,x;
    cin>>n>>x;
    vll a(n);
    fo(i,n) cin>>a[i];
    bool flag = true;
    ll sum1 = 0;
    fo(i,n){
        if(a[i]<0){
            flag = false;
        }
        sum1 += a[i];
    }
    if(flag){
        if(x>0){
            sum1 *= x;
        }
        cout<<sum1<<endl;
        exit(0);
    }
    bool flag1 = true;
    fo(i,n){
        if(a[i]>0){
            flag1 = false;
        }
    }
    if(flag1){
        if(x<0){
            sum1 *= x;
        }else{
            sum1 = 0;
        }
        cout<<sum1<<endl;
        exit(0);
    }
    if(x<0){
        vll b(n,0);
        fo(i,n){
            b[i] -= a[i]; 
        }
        ll l=0,r=0;
        ll s = 0;
        ll sum = 0;
        ll maxSum = -1e18;
        fo(i,n){
            sum += b[i];
            if(maxSum<sum){
                maxSum = sum;
                l = s;
                r = i;
            }
            if(sum<0){
                sum = 0;
                s = i+1;
            }
        }
        Fo(j,l,r+1){
            a[j] *= x;
        }
        maxSum = -1e18;
        sum = 0;
        fo(i,n){
            sum += a[i];
            if(maxSum<sum){
                maxSum = sum;
            }
            if(sum<0){
                sum = 0;
            }
        }
        cout<<maxSum<<endl;

    }else{
        // cout<<1<<endl;
        ll maxSum = -1e18;
        ll sum = 0;
        fo(i,n){
            sum += a[i];
            if(maxSum<sum){
                maxSum = sum;
            }
            if(sum<0){
                sum = 0;
            }
        }
        ll ans = x*maxSum;
        cout<<ans<<endl;
    }
}