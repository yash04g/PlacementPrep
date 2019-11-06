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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        map<char,int> a1;
        map<char,int> a2;
        fo(i,n){
            a1[s[i]]++;
            a2[t[i]]++;
        }
        bool flag = false;
        // fo(i,n){
        //     if(a1[s[i]]!=a2[s[i]]){
        //         flag = true;
        //     }
        // }
        if(a1!=a2){
            cout<<"NO"<<endl;
            continue;
        }
        for(auto x:a1){
            if(x.second>1){
                flag = true;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            continue;
        }
        int inv1 = 0,inv2 = 0;
        fo(i,n){
            for(int j=i+1;j<n;++j){
                if(s[i]>s[j]){
                    inv1++;
                }
                if(t[i]>t[j]){
                    inv2++;
                }
            }
        }
        if(inv1%2 == inv2%2){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}