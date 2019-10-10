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
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double>

int main(){
	// ios::sync_with_stdio(false);
 //  	cin.tie(0);
 //  	cout.tie(0);
  	int n;
  	cin>>n;
  	string s;
  	cin>>s;
  	int numz = 0;
  	int numn = 0;
  	fo(i,n){
  		if(s[i]=='z'){
  			numz++;
  		}
  		if(s[i]=='n'){
  			numn++;
  		}
  	}
  	fo(i,numn){
  		cout<<"1 ";
  	}
  	fo(i,numz){
  		cout<<"0 ";
  	}
}