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
  		long h;
  		int n;
  		cin>>h>>n;
  		string s(h+1,'0');
  		// cout<<s;
  		Fo(i,1,n+1){
  			int m;
  			cin>>m;
  			s[m] = '1';
  		}
  		s[h] = '1';
  		long i=h;
  		int cnt = 0;
  		while(i){
  			if(s[i-1]=='0'){
  				i -= 1;
  			}else if(s[i-2]=='1'){
  				i -= 2;
  			}else{
  				if(i!=2){
  					cnt++;
  				}
  				i -= 2;
  			}
  		}
  		cout<<cnt<<endl;
  	}
}