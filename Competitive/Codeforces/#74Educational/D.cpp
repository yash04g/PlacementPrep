#include <bits/stdc++.h>
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

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int countA=0,countB=0;
    ll ans = ((ll)n*(n+1))/2;
    vi counts;
    for(int i=0;i<n;i++){
    	if(s[i]=='A'){
    		countA++;
    		if(countB>0){
    			counts.pb(countB);
    		}
    		countB=0;
    	}else{
    		countB++;
    		if(countA>0){
    			counts.pb(countA);
    		}
    		countA=0;
    	}
    }
    if(countA){
    	counts.pb(countA);
    }
    if(countB){
    	counts.pb(countB);
    }
    for(int i=0;i<counts.size()-1;i++){
    	int a = counts[i];
    	int b = counts[i+1];
    	ans -= (a+b-1);
    }
    ans -= n;
    cout<<ans<<endl;
}