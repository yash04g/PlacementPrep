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
    	int sum = 0;
    	int numt = 0;
    	int numf = 0;
    	int numz = 0;
    	fo(i,n){
    		int x = s[i]-'0';
    		sum += x;
    		if(x==0) numz++;
    		if(x%2==0){
    			numt++;
    		}
    		if((x%4==0 || x%8==0) && x!=0){
    			numt += 2;
    		}
    		if(x%5==0){
    			numf++;
    		}
    	}
    	if(sum%3!=0){
    		cout<<"cyan"<<endl;
    	}else{
    		if(numt>1 && numf>0 && numz>0){
    			// cout<<numt<<endl;
    			cout<<"red"<<endl;
    		}else{
    			cout<<"cyan"<<endl;	
    		}
    	}

    }
}
