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
const int N = 2e5+5;
int dp[N];


int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	vi left(n);
    	vi right(n);
    	map<int,int> l;
    	map<int,int> r;
    	fo(i,n) cin>>left[i],l[left[i]]++;;
    	fo(i,n) cin>>right[i],r[right[i]]++;
    	reverse(all(left));
    	if((l[1]==0&&r[1]==0)||(l[2]==0 && r[2]==0)){
    		cout<<2*n<<endl;
    		continue;
    	}
    	int cnt = 0;
    	
    	cout<<cnt<<endl;

    }
}
