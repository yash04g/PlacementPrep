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
    int n,k;
    cin>>n;
    vi a(n);
    fo(i,n) cin>>a[i];
    cin>>k;
    // We have to process the first K elements
    deque<int> q(k);
    int i=0;
    for(;i<k;i++){
    	while(!q.empty() && a[i]>a[q.back()]){
    		q.pop_back();
    	}
    	q.push_back(i);
    }
    // Now after this loop we have the index of the largest element in the first k elements

    // Processing the remaining elements
    for(;i<n;i++){
    	cout<<a[q.front()]<<endl;
    	// Remove the elements which are not the part of window ->Contraction
    	while((!q.empty()) && (q.front()<=(i-k))){
    		q.pop_front();
    	}
    	// Remove the elements which are not useful and are in window
    	while(!q.empty() && a[i]>=a[q.back()]){
    		q.pop_back();
    	}
    	// Add the new elements ->expansion
    	q.push_back(i);
    }
    cout<<a[q.front()]<<endl;
}