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

bool cmp(pair<ll,ll> a,pair<ll,ll> b){
    return a.first<b.first;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin>>n;
        vll monster(n);
        fo(i,n) cin>>monster[i];
        ll m;
        cin>>m;
        vpll heroes(m);
        fo(i,m){
            ll power,endurance;
            cin>>power>>endurance;
            heroes[i] = mp(power,endurance);
        }
        sort(monster.begin(),monster.end());
        sort(heroes.begin(),heroes.end(),cmp);
        ll cnt = 0;
        // ll monsterDefeat = 0;
        ll i = 0;
        ll j = 0;
        while(i<m && j<n){
         
        }
        if(cnt<n){
            cout<<-1<<endl;
        }else{
            cout<<n<<endl;
        }

    }
}