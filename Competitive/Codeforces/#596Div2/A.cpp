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
    int a,b;
    cin>>a>>b;
    if(a==9 && b==1){
    	cout<<9<<" "<<10<<endl;
    	exit(0);
    }
    else if(b<a){
    	cout<<-1<<endl;
    	exit(0);
    }
    if(abs(b-a)>1){
    	cout<<-1<<endl;
    	exit(0);
    }
    string da = "",db = "";
    da += (a+'0');
    db += (b+'0');
    if(a==b){
    	da += '1';
    	db += '2';
    	cout<<da<<" "<<db<<endl;
    }else{
    	da += '9';
    	db += '0';
    	cout<<da<<" "<<db<<endl;
	}
}