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
#define pll pair<int,int>
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
const int N = 1e5+5;
int dp[N];


int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
		int n;
		cin>>n;
		if(n<10){
			cout<<n<<endl;
			continue;
		}    	
		int numDigits = 0;
		int temp = n;
		while(temp>0){
			numDigits++;
			temp /= 10;
		}
		int ans = 9*(numDigits-1);
		int x = (n/((int)pow(10,(numDigits-1))));
		ans += (x-1);
		int temp1 = 0;
		fo(i,numDigits){
			temp1 += (x*((int)pow(10,i)));
		}
		if(n>=temp1){
			ans += 1;
		}

		cout<<ans<<endl;

    }
}
