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

void swap1(int &a,int &b){
    a = a^b;
    b = b^a;
    a = a^b;
}

int main(){
    ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n);
        fo(i,n) cin>>a[i];
        if(n==1){
            cout<<a[0]<<endl;
            continue;
        }
        else if(n==2){
            if(a[0]>a[1]){
                swap1(a[0],a[1]);
            }
            cout<<a[0]<<" "<<a[1]<<endl;
            continue;
        }
        else{
            bool swaps[n];
            fo(i,n){
                swaps[i] = true;
            }
            int s = n-1;
            int x = 100;
            while(x){
                for(int i=n-1;i>0;i--){
                    if(s==0){
                        break;
                    }else{
                        if(a[i]<a[i-1]){
                            if(swaps[i-1]){
                                swap1(a[i],a[i-1]);
                                swaps[i-1] = false;
                                s--;
                            }
                        }
                    }
                }
                x--; 
            }
            fo(i,n){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
}