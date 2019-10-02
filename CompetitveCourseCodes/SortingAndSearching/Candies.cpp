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
bool possible(vi &candies,int mid,int k){
	int total_person = 0;
	fo(i,candies.size()){
		total_person += candies[i]/mid;
	}
	if(total_person>=k){
		return true;
	}
	return false;
}
ll distribution(vi &candies,int n,int k){
	sort(candies.begin(),candies.end());
	int s = 0;
	int e = candies[n-1];
	int ans = 0;
	while(s>=e){
		int mid = (s+e)/2;
		if(possible(candies,mid,k)){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	return ans;
}
int main(){
    int t;
    cin >> t;
    while (t--){
    	ll n,k;
    	cin>>n>>k;
    	vi candies(n);
    	fo(i,n)
    		cin>>candies[i];
    	cout<<distribution(candies,n,k)<<endl;
    }
}	