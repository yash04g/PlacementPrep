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
        ll x,y;
        cin>>x>>y;
        // if((x-y)==1 || x==y){
        //     cout<<"YES"<<endl;
        //     continue;
        // }
        // else if(x>y){
        //     cout<<"YES"<<endl;
        //     continue;
        // }
        // else if(!(x&1)){
        //     bool flag = false;
        //     while(!flag){
        //         if(!(x&1)){
        //             x /= 2;
        //             x *= 3;
        //             if((x-1)==y || (x==y)){
        //                 flag = true;
        //             }
        //         }else{
        //             break;
        //         }
        //     }
        //     if(flag){
        //         cout<<"YES"<<endl;
        //     }else{
        //         cout<<"NO"<<endl;
        //     }
        // }
        // else{
        //     x -= 1;
        //     if(x==0){
        //         cout<<"NO"<<endl;
        //         continue;
        //     }
        //     bool flag = false;
        //     while(!flag){
        //         if(!(x&1)){
        //             x /= 2;
        //             x *= 3;
        //             if(x>=y){
        //                 flag = true;
        //             }
        //         }else{
        //             break;
        //         }
        //     }
        //     if(flag){
        //         cout<<"YES"<<endl;
        //     }else{
        //         cout<<"NO"<<endl;
        //     }
        //     // cout<<"NO"<<endl;
        // }
        if(x>=y){
            cout<<"YES"<<endl;
        }
        else if(!(x&1)){
            if(x==2 && y>=4){
                cout<<"NO"<<endl;
                continue;
            }
            ll z = (x*3)/2;
            if(z>x){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
        else{
            ll z = ((x-1)/2)*3;
            if(z>x){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }
}