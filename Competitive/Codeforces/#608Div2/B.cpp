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
    // cin >> t;
    while (t--){
    	int n;
		cin>>n;
		string s;
		cin>>s;
		int cntW=0,cntB=0;
		vi ans;
		for(int i=0;i<n;i++){
			if(s[i]=='W') cntW++;
			else cntB++;
		}
		if((cntB&1) && (cntW&1)){
			cout<<-1<<endl;
			continue;
		}
		else if(cntB == 0 || cntW == 0){
			cout<<0<<endl;
			continue;
		}
		else if((cntB & 1) && cntW % 2 == 0){
			int idx = 0;
			while(idx<n-1){
				if(s[idx]=='W'){
					if(s[idx+1]=='B'){
						s[idx] = 'B';
						s[idx+1] = 'W';
						ans.push_back(idx+1);
					}
					else{
						s[idx] = 'B';
						s[idx+1] = 'B';
						ans.push_back(idx+1);
					}
				}
				idx++;
			}
		}
		else if(cntB % 2 == 0 && cntW % 2 == 1){
			int idx = 0;
			while(idx<n-1){
				if(s[idx]=='B'){
					if(s[idx+1]=='W'){
						s[idx] = 'W';
						s[idx+1] = 'B';
						ans.push_back(idx+1);
					}
					else{
						s[idx] = 'W';
						s[idx+1] = 'W';
						ans.push_back(idx+1);
					}
				}
				idx++;
			}
		}
		else if(cntB % 2 == 0 && cntW % 2 == 0){
			int idx = 0;
			if(cntW>cntB){
				while(idx<n-1){
					if(s[idx]=='W'){
						if(s[idx+1]=='B'){
							s[idx] = 'B';
							s[idx+1] = 'W';
							ans.push_back(idx+1);
						}
						else{
							s[idx] = 'B';
							s[idx+1] = 'B';
							ans.push_back(idx+1);
						}
					}
					idx++;
				}
		}
		else{
			while(idx<n-1){
				if(s[idx]=='B'){
					if(s[idx+1]=='W'){
						s[idx] = 'W';
						s[idx+1] = 'B';
						ans.push_back(idx+1);
					}
					else{
						s[idx] = 'W';
						s[idx+1] = 'W';
						ans.push_back(idx+1);
					}
				}
				idx++;
			}
		}
	}
	int len = ans.size();
	cout<<len<<endl;
	for(int i=0;i<len;i++){
		cout<<ans[i]<<" ";
	}


    }
}
