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
bool sieve[1000005];

void printPrimes(int n){
	fo(i,n+1){
		sieve[i] = true;
	}
	sieve[0] = false;
	sieve[1] = false;
	for(int i=2;i*i<=n;i++){
		if(sieve[i]){
			for(int j=i*i;j<=n;j+=i){
				sieve[j] = false;
			}
		}
	}
	fo(i,n+1){
		if(sieve[i]){
			cout<<i<<" ";
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int n;
    cin>>n;
    printPrimes(n);
}