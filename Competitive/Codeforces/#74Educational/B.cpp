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
    int t;
    cin >> t;
    while (t--){
    	int n,r;
    	cin>>n>>r;
    	vi pos(n);
    	fo(i,n)
    		cin>>pos[i];
    	sort(pos.begin(),pos.end());
    	int cnt = 0;
    	int largest = pos[n-1];
    	int index = n-1;
    	int deaths = 0;

    	while(1){
    		if(deaths==n){
    			break;
    		}
    		for(int i=index;i>=0 && pos[i]>0;i--){
    			if(pos[i]==largest){
    				pos[i] = 0;
    				index = i-1;
    				deaths++;
    			}
    			else{
    				pos[i] -=r;
    				if(pos[i]<=0){
    					deaths++;
    				}
    			}
    		}
    		largest = pos[index];
    		cnt++;
    	}
    	cout<<cnt<<endl;

    }

}