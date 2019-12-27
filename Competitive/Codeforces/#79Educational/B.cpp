#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mi map<int,int>
#define mc map<char,int>  
#define pii pair<int,int>
#define pdd pair<double,double>
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

void get_it_done(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
void swap(int &a,int &b){
	a^=b;b^=a;a^=b;
}
const int N = 2e5+5;
int dp[N][2];


int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
    	int n,s;
		cin>>n>>s;
		vi a(n);
		int sum = 0;
		int mini = inf;
		fo(i,n) cin>>a[i],sum += a[i],mini = min(mini,a[i]);
		if(sum<=s){
			cout<<0<<endl;
			continue;
		}
		if(sum-mini<=s){
			cout<<1<<endl;
			continue;
		}
		vpii arr(n);
		int maxi = a[0];
		int sum1 = a[0];
		arr[0] = mp(a[0],a[0]);
		Fo(i,1,n){
			maxi = max(maxi,a[i]);
			sum1 += a[i];
			arr[i] = mp(sum1,maxi);
		}
		int cnt = 0;
		int ans1 = -1;
		fo(i,n){
			if(arr[i].first-arr[i].second>s){
				break;
			}else{
				// cout<<1<<endl;
				ans1 = max(ans1,arr[i].second);
			}
		}
		// cout<<ans1<<endl;
		int idx = -1;
		fo(i,n){
			if(a[i]==ans1){
				idx = i;
				break;
			}
		}
		cout<<idx+1<<endl;

    }
}
