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
    int t;
    cin >> t;
    while (t--){
    	string s;
    	cin>>s;
    	int n = s.size();
    	vi a(n);
    	fo(i,n){
    		a[i] = s[i]-'0';
    	}
    	vi odd;
    	vi even;
    	fo(i,n){
    		if(a[i]&1){
    			odd.pb(a[i]);
    		}else{
    			even.pb(a[i]);
    		}
    	}
    	vi ans;
    	int i = 0;
    	int j = 0;
    	while(i<odd.size() && j<even.size()){
    		if(odd[i]<even[j]){
    			ans.pb(odd[i]);
    			i++;
    		}else{
    			ans.pb(even[j]);
    			j++;
    		}
    	}
    	while(i<odd.size()){
    		ans.pb(odd[i]);
    		i++;
    	}
    	while(j<even.size()){
    		ans.pb(even[j]);
    		j++;
    	}
    	fo(i,n){
    		cout<<ans[i];
    	}
    	cout<<endl;
    }
}