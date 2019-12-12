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
int R=0,L=0,U=0,D=0;
string s;
int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
		cin>>s;
		int len = s.length();
		int R=0,L=0,U=0,D=0;
		for(int j=0;j<len;j++){
			if(s[j]=='U'){
				U++;
			}
			else if(s[j]=='D'){
				D++;
			}
			else if(s[j]=='R'){
				R++;
			}
			else if(s[j]=='L'){
				L++;
			}
		}
		if(R<L){
			L=R;
		}
		else{
			R=L;
		}
		if(U<D){
			D=U;
		}
		else{
			U=D;
		}
		if(L==0 && U!=0){
			U=1;
			D=1;
		}
		if(U==0 && L!=0){
			R=1;
			L=1;
		}
		string ans="";
		int cnt = R+L+U+D;
		fo(i,R){
			ans += "R";
		}
		fo(i,U){
			ans += "U";
		}
		fo(i,L){
			ans += "L";
		}
		fo(i,D){
			ans += "D";
		}
		cout<<cnt<<endl<<ans<<endl;

    }
}
