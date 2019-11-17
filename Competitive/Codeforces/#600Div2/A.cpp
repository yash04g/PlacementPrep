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
 		ll n;
 		cin>>n;
 		vll a(n);
 		vll b(n);
 		fo(i,n) cin>>a[i];
 		fo(i,n) cin>>b[i];
 		if(n==1){
 			if(a[0]<=b[0]){
 				cout<<"YES"<<endl;
 			}else{
 				cout<<"NO"<<endl;
 			}
 			continue;
 		}
 		bool flag = true;
 		set<ll> diff;
 		ll prev = a[0]-b[0];
 		diff.insert(prev);
 		Fo(i,1,n){
 			if(a[i]-b[i]>0){
 				flag = false;
 				break;
 			}
 			if(a[i]-b[i]!=prev){
 				prev = a[i]-b[i];
 				if(diff.find(prev)!=diff.end() && prev!=0){
 					flag = false;
 					break;
 				}else{
 					diff.insert(a[i]-b[i]);
 				}
 			}
 		}
 		if(diff.size()>2){
 			flag = false;
 		}
 		set<ll> :: iterator it;
 		int cnt = 0;
 		for(it=diff.begin();it!=diff.end();it++){
 			if(*it!=0){
 				cnt++;
 			}
 		}
 		if(cnt>1){
 			flag = false;
 		}
 		if(flag){
 			cout<<"YES"<<endl;
 		}else{
 			cout<<"NO"<<endl;
 		}  	
    }
}