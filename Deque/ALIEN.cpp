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
    	int maxima = INT_MAX;
    	int maxCnt = 0;
    	int cnt = 0;
    	int sum = 0;
    	fo(i,n){
    		if(q.empty() && a[i]<=b){
    			q.push_back(a[i]);
    			sum += a[i];
    		}
    		else{
    			if(a[i]>b){
    				cnt = q.size();
    				if(maxCnt<=cnt && sum<=b){
    					maxima = min(maxima,sum);
    					maxCnt = cnt;
    				}
    				sum = 0;
    				q.erase(q.begin(),q.end());
    			}
    			else{
    				if(sum+a[i]>b){
    					cnt = q.size();
    					if(maxCnt<=cnt && sum<=b){
    						maxima = min(maxima,sum);
    						maxCnt = cnt;
    					}
    					sum += a[i];
    					q.push_back(a[i]);
    					while(sum>b){
    						sum -= q.front();
    						q.pop_front();
    					}
    				}
    				else{
    					sum += a[i];
    					q.push_back(a[i]);
    				}
    			}
    		}
    	}
    	if(maxCnt<=cnt && sum<=b){
			maxima = min(maxima,sum);
			maxCnt = cnt;
		}
    	cout<<maxima<<" "<<maxCnt<<endl;
    }
}