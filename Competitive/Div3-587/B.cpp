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
bool compare(pii a,pii b){
	return a.first>b.first;
}
int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int n;
    cin>>n;
    vi a(n);
    fo(i,n){
    	cin>>a[i];
    }
    vp ab(n);
    fo(i,n){
    	ab[i].first = a[i];
    	ab[i].second = i;
    }
    sort(ab.begin(),ab.end(),compare);
    int count = 0;
    int ans = 0;
    fo(i,n){
    	ans += (ab[i].first*count) + 1;
    	count++;
    }
    cout<<ans<<endl;
    fo(i,n){
    	cout<<ab[i].second+1<<" ";
    }
}