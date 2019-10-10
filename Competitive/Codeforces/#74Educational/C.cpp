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

	int q;
  	cin>>q;
  	while(q--){
  		ll h,n;
  		cin>>h>>n;
  		ll *platform = new ll[n+1]();
  		// vll platform(h+1,0);
  		for(int j=0;j<n;j++){
  			ll temp;
  			cin>>temp;
  			platform[temp]=1;
  		}
  		ll cnt=0;
  		ll index=h;
  		while(index){
	  		if(platform[index-1]==0)
	  			index--;
	  		else if(platform[index-2]==1)
	  			index-=2;
	  		else{
	  			if(index!=2)
	  				cnt++;
	  			index-=2;
	  		}
	  	}
  		cout<<cnt<<endl;
  	}
}