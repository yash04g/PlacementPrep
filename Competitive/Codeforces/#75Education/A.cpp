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
#define fo(i,n) for(ll i=0;i<n;++i)
#define Fo(i,k,n) for(ll i=k;i<n;++i)
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
    int t;
    cin >> t;
    while (t--){
    	string s;
    	cin>>s;
    	string ans = "";
    	int i = 0;
    	while(i<s.size()){
    		if(s[i]==s[i+1] && (i!=s.size()-1)){
    			i += 2;
    		}else{
    			ans += s[i];
    			i += 1;
    		}
    	}
    	if(s.size()==1){
    		ans = s[0];
    	}
    	sort(ans.begin(),ans.end());
    	set<char> res;
    	set<char> :: iterator it;
    	for(int i=0;i<ans.size();i++){
    		res.insert(ans[i]);
    	}
    	for(it = res.begin();it!=res.end();it++){
    		cout<<*it;
    	}
    	cout<<endl;
    	// cout<<ans<<endl;
    }
}