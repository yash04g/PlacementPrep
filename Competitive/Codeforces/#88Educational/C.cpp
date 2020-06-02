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
     double h,c,t;
    cin>>h>>c>>t;
        if(h==t)
        {
            cout<<1<<endl;
            return;
        }
        double sum = h+c;
        double mid = sum/2;
        if(mid==t)
        {
            cout<<2<<endl;
            return;
        }

        if(t<mid)
        {
            cout<<2<<endl;
            return;
        }

        int high = (h-t);
        int low = (2*t-h-c);
        double x,y;
        if(high%low==0)
        {
            x = (high/low);
            cout<<2*x+1<<endl;
            return;
        }
        else
        {
            x = (high/low)+1;
            y = x-1;

            double val1 = (((x*sum)+h)/((2*x)+1));
            double val2 = (((y*sum)+h)/((2*y)+1));
            if(abs(t-val1)<abs(t-val2))
            {
                cout<<2*x+1<<endl;
            }
            else
            {
                cout<<2*y+1<<endl;
            }
        }

}

int32_t main(){
    get_it_done();
    int tc=1;
    cin >> tc;
    while (tc--){
        solve();        
    }
}
