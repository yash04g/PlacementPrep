#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
int main(){
    int t;
    cin >> t;
    while (t--){
    	int n,m;
    	cin>>n>>m;
    	vp intervals;
    	fo(i,n){
    		int s,e;
    		cin>>s>>e;
    		intervals.pb(mp(s,e));
    	}
    	sort(intervals.begin(),intervals.end());
    	while(m--){
    		int currtime;
    		cin>>currtime;
    		int position = lower_bound(intervals.begin(),intervals.end(),mp(currtime,0))-intervals.begin();
    		if(position==0){
    			int ans = intervals[0].first-currtime;
    			cout<<ans<<endl;
    		}
    		else{
    			int ans = -1;
    			if(intervals[position-1].second > currtime){
    				ans = 0;
    			}
    			else if(position<intervals.size()){
    				ans = intervals[position].first-currtime;
    			}
    			cout<<ans<<endl;
    		}
    	}
    }
}