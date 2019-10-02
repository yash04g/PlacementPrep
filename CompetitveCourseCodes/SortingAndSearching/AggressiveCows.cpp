#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
bool possible(vll &positions,int c,int d){
	int count = 1;
	ll currpos = positions[0];
	Fo(i,1,positions.size()){
		if(positions[i]-currpos>=d){
			count++;
			currpos = positions[i];
		}
		if(count==c){
			return true;
		}
	}
	return false;
}
int helper(vll &positions,int n,int c,int s,int e){
	ll ans = -1;
	while(s<=e){
		ll mid = s+(e-s)/2;
		if(possible(positions,c,mid)){
			ans = mid;
			s = mid+1;
		}
		else{
			// ans = 0;
			e = mid-1;
		}
	}
	return ans;
}
int aggressiveCows(vll &positions,int n,int cows){
	sort(positions.begin(),positions.end());
	int end = positions[n-1]-positions[0];
	return helper(positions,n,cows,0,end);
}
int main(){
    int t;
    cin >> t;
    while (t--){
    	int n,c;
    	cin>>n>>c;
    	vll positions(n);
    	fo(i,n)
    		cin>>positions[i];
    	cout<<aggressiveCows(positions,n,c)<<endl;
    }
}