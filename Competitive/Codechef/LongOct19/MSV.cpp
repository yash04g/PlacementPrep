#include<bits/stdc++.h>
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
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double>

ll starVal(vi &a,int n){
	vi sieve(n,1);
	int cnt = 0;
	int maxCnt = 0;
	for(int i=n-1;i>=0;i--){
		cnt = 0;
		if(sieve[i]==1){
			fo(j,i){
				if(a[j]%a[i]==0){
					sieve[j] = 0;
					cnt++;
				}
			}
		}
		maxCnt = max(maxCnt,cnt);
	}
	return maxCnt;

}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	vi a(n);
    	fo(i,n) cin>>a[i];
    	cout<<starVal(a,n)<<endl;
    }
}