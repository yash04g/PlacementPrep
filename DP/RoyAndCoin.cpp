#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double>
int main(){

    int n,m,x=0;
    cin>>n>>m;
    vector<int> input(n+1,0);
    vector<int> start(n+1,0);
    vector<int> end(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        start[x]++;
        end[y]++;
    }
    input[1] = start[1];
    for(int i=2;i<=n;i++){
        input[i] = start[i]-end[i-1]+input[i-1];
    }
    vector<int> coins(n+1,0);
    for(int i=1;i<=n;i++){
        coins[input[i]]++;
    }
    vector<int> atleast(n+1,0);
    atleast[n] = coins[n];
    for(int i=n-1;i>=1;i--){
        atleast[i] = coins[i]+atleast[i+1];
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int cnt;
        cin>>cnt;
        cout<<atleast[cnt]<<endl;
    }
}