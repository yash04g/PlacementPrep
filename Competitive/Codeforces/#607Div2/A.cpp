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
    	string s;
    	cin>>s;
    	int n = s.size();
    	fo(i,s.size()){
    		if(i<(n-1) && s[i]=='p' && s[i+1]=='o' && ((i+2)==n)){
    			cout<<"FILIPINO"<<endl;
    		}
    		if(i<n-3 && s[i]=='d' && s[i+1]=='e' && s[i+2]=='s' && s[i+3]=='u'&& ( (i+4)==n)){
    			cout<<"JAPANESE"<<endl;
    		}
    		if(i<n-3 && s[i]=='m' && s[i+1]=='a' && s[i+2]=='s' && s[i+3]=='u' && ((i+4)==n)){
    			cout<<"JAPANESE"<<endl;	
    		}
    		if(i<n-4 && s[i]=='m' && s[i+1]=='n' && s[i+2]=='i' && s[i+3]=='d' && s[i+4]=='a' && ((i+5)==n)){
    			cout<<"KOREAN"<<endl;
    		}
    	}
    }
}
