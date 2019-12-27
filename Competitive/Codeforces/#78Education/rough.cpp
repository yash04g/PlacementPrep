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
    	int a,b;
    	cin>>a>>b;
    	if(a==b){
    		cout<<0<<endl;
    		continue;
    	}
    	if(abs(a-b)==1){
    		cout<<1<<endl;
    		continue;
    	}
    	if(a>b){
    		a ^= b;
    		b ^= a;
    		a ^= b;
    	}
    	int i = 1;
    	int cnt = 0;
    	bool flag = true;
    	while(1){
    		while(a<b){
    			
    			a += i;
    			i++;
    			cnt++;
                // if(a+i>b){
                //     break;
                // }
    			// cout<<a<<endl;
    		}
    		if(a==b) 
    			break;
    		else{
    			b += i;
    			i++;
    			cnt++;
    			// deb(b);
    		}
    	}
    	cout<<cnt<<endl;
    }
}
