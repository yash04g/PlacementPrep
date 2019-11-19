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

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second<b.second;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t=1;
    cin >> t;
    while (t--){
    	int n,m;
    	cin>>n>>m;
    	vector<pair<int,int> > a(n);
    	fo(i,n){
    		int x;
    		cin>>x;
    		a[i] = mp(i+1,x);
    	}
    	if(m<=n-1){
    		cout<<-1<<endl;
    		continue;
    	}
    	if(n==2){
    		cout<<-1<<endl;
    		continue;
    	}
    	sort(a.begin(),a.end(),cmp);
    	int ans = 0;
    	fo(i,n-1){
    		ans += (a[i].second+a[i+1].second);
    	}
    	ans += (a[0].second+a[n-1].second);
    	cout<<ans<<endl;
    	fo(i,n-1){
    		cout<<a[i].first<<" "<<a[i+1].first<<endl;
    	}
    	cout<<a[0].first<<" "<<a[n-1].first<<endl;


    }
}