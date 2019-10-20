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
    	int n;
    	cin>>n;
    	vi a(n);
    	int minima = INT_MAX;
    	int maxima = INT_MIN;
    	int minIndex = -1;
    	int maxIndex = -1;
    	fo(i,n){ 
    		cin>>a[i];
    		if(maxima<a[i]){
    			maxima = max(maxima,a[i]);
    			maxIndex = i;
    		}
    		if(minima>a[i]){
    			minima = min(minima,a[i]);
    			minIndex = i;
    		}
    	}
    	if(minIndex>maxIndex){
    		cout<<maxima<<" "<<minima<<endl;
    	}else{
    		cout<<minima<<" "<<maxima<<endl;
    	}
    	

    }
}