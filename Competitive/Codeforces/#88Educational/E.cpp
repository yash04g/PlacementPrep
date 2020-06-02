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

        vector<int> v(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
        }

        int curr_sum = 0;
        vector<int> leftsum(n+1,0);
        vector<int> leftmax(n+1,0);
        int curr_max = v[1];
        for(int i=1;i<=n;i++)
        {
            if(curr_sum<=0)
            {
                leftsum[i] = v[i];
                leftmax[i] = v[i];
                curr_sum = v[i];
                curr_max = v[i];
                continue;
            }

            curr_sum+=v[i];
            leftmax[i] = max(v[i],curr_max);
            leftsum[i] = curr_sum;
            curr_max = max(curr_max,v[i]);
        }

        curr_max=v[n];
        curr_sum=0;

        vector<int> rightsum(n+1,0);
        vector<int> rightmax(n+1,0);
        for(int i=n;i>=1;i--)
        {
            if(curr_sum<=0)
            {
                rightsum[i] = v[i];
                rightmax[i] = v[i];
                curr_sum = v[i];
                curr_max = v[i];
                continue;
            }

            curr_sum+=v[i];
            rightmax[i] = max(v[i],curr_max);
            rightsum[i] = curr_sum;
            curr_max = max(curr_max,v[i]);
        }

        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            int k = leftsum[i] + rightsum[i] - v[i] - max(leftmax[i],rightmax[i]);
            ans = max(ans,k);
            ans = max(leftsum[i]-leftmax[i],ans);
            ans = max(rightsum[i]-rightmax[i],ans);
        }

        cout<<ans<<endl;
}

int32_t main(){
    get_it_done();
    int tc=1;
    cin >> tc;
    while (tc--){
        solve();        
    }
}
