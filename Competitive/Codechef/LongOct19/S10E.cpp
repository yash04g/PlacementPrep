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
    int t;
    cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	vi a(n);
    	fo(i,n) cin>>a[i];
    	int cnt = 0;
    	int minPrice = INT_MAX;
    	fo(i,5){
    		if(i<n){
    			if(a[i]<minPrice){
    				minPrice = a[i];
    				cnt++;
    			}
    		}
    	}
    	Fo(i,5,n){
    		int price = INT_MAX;
    		// minPrice = a[i];
    		Fo(j,i-5,i){
    			price = min(price,a[j]);
    		}
    		if(a[i]<price){
    			cnt++;
    		}
    	}
    	cout<<cnt<<endl;
    }

}