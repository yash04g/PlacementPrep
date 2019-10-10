#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
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
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int n;
    cin>>n;
    char **a = new char*[n];
    for(int i=0;i<n;i++){
    	a[i] = new char[n];
    }
    int cnt = 0;
    string str = "BW";
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if((i+j)%2==0){
    			a[i][j] = 'B';
    		}else{
    			a[i][j] = 'W';
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cout<<a[i][j];
    	}
    	cout<<endl;
	}
}