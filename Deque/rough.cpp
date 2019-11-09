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
    	int n,b;
    	cin>>n>>b;
    	vi a(n);
    	fo(i,n) cin>>a[i];
    	deque<int> q;
    	int maxima = 0;
    	int maxCnt = 0;
    	int cnt = 0;
    	int sum = 0;
    	fo(i,n){
    		if(q.empty() && a[i]<=b){
    			q.push_back(a[i]);
    			sum += a[i];
    		}else{
    			if(sum+a[i]>b){
    				if(a[i]>b){
    					maxima = max(maxima,sum);
    					cnt = q.size();
    					maxCnt = max(maxCnt,cnt);
    					sum = 0;
    					q.erase(q.begin(),q.end());
    				}else{
    					// maxima = max(maxima,sum);
    					if(maxima>=sum){
    						cnt = q.size();
    						maxCnt = max(maxCnt,cnt);
    						maxima = sum;
    					}    					
    					sum -= q.front();
    					sum += a[i];
    					q.pop_front();
    					q.push_back(a[i]);
    				}
    			}else{
    				sum += a[i];
    				q.push_back(a[i]);
    			}
    		}
    	}
    	cout<<maxCnt<<" "<<maxima<<endl;
    }
}