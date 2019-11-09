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
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    string s;
    cin>>s;
    int currLen = 1;
    int maxLen = 1;
    int n = s.size();
    // Map to maintain the last occurence of a character of string
    int visited[256];
    memset(visited,-1,sizeof(visited));
    visited[s[0]] = 0;
    for(int i=1;i<n;i++){
    	int last_occ = visited[s[i]];
    	// Expansion only
    	if(last_occ==-1 || i-currLen>last_occ){
    		currLen += 1;
    		maxLen = max(maxLen,currLen);
    	}
    	// Expansion+Contraction
    	else{
    		maxLen = max(maxLen,currLen);
    		currLen = i-last_occ;
    	}
    	visited[s[i]] = i;
    }
    maxLen = max(maxLen,currLen);
    cout<<maxLen<<endl;
}