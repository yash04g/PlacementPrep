#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mset(a,i) memset(a,i,sizeof(a))
#define mii map<int,int>  
#define pii pair<int,int>
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { if(0) return; cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){   
    if(0) return; 
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
void get_it_done(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int gcd(int a,int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}
const int N = 3e5+5;

void solve(){
    int n;
    cin>>n;
    vi a(n+1);
    loop(i,1,n+1) cin>>a[i];
    vpii pref1(n+1,mp(0,0));
    vpii pref2(n+1,mp(0,0));
    int maxi = 0;
    int sum = 0;
    loop(i,1,n+1){
        if(sum<=0){
            sum = a[i];
            maxi = a[i];
            pref1[i].ff = sum;
            pref1[i].ss = maxi;
            continue;
        }
        sum+=a[i];
        maxi = max(maxi,a[i]);
        pref1[i].ff = sum;
        pref1[i].ss = maxi;
    }
    sum = 0;
    maxi = 0;
    rloop(i,n,1){
        if(sum<=0){
            sum = a[i];
            maxi = a[i];
            pref2[i].ff = sum;
            pref2[i].ss = maxi;
            continue;
        }
        sum+=a[i];
        maxi = max(maxi,a[i]);
        pref2[i].ff = sum;
        pref2[i].ss = maxi;
    }
    maxi = 0;
    loop(i,1,n+1){
        int val = pref1[i].ff + pref2[i].ff - a[i] - max(pref1[i].ss,pref2[i].ss);
        maxi = max(maxi,val);
        maxi = max(pref1[i].ff-pref1[i].ss,maxi);
        maxi = max(pref2[i].ff-pref2[i].ss,maxi);
    }
    cout<<maxi<<endl;
    

}

int32_t main(){
    get_it_done();
    int tc=1;
    // cin >> tc;
    while (tc--){
        solve();        
    }
}
