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
    int t=1;
    cin >> t;
    while (t--){
    	int n,m;
    	cin>>n>>m;
    	vi a(n);
    	fo(i,n) cin>>a[i];
    	if((m>((2*n)-2)) || (n==3 && m==4) || (m<n) || (n==2 && m==1)){
    		cout<<-1<<endl;
    		continue;
    	}
    	vvi edges(n,vi(n),0);
    	vi cnt(n,0);
    	int ans = 0;
    	fo(i,n){
    		fo(j,n){
    			if(i==j){
    				continue;
    			}
    			if(edges[i][j]==0){
    				edges[i][j] = 1;
    				ans += (2*(a[i]+a[j]));		
    				m -= 1;
    			}
    		}
    	}
    	int idx1 = -1;
    	int idx2 = -1;
    	int minima1 = 1e5;
    	fo(i,n){
    		if(minima1<a[i]){
    			minima1 = a[i];
    			idx1 = i;
    		}
    	}
    	fo(i,n){
    		if(minima2<a[i]){
    			minima2 = a[i];
    			idx2 = i;
    		}
    	}
    	int cnt = 0;
    	while(m>0){
    		ans += (2*(a[idx1]+a[idx2]));
    		cnt++;
    	}
    	cout<<ans<<endl;
    	fo(i,n){
    		fo(j,n){
    			if(edges[i][j]==1){
    				cout<<i<<" "<<j;
    			}
    		}
    	}

    }
}