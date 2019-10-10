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
    int t;
    cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	vi a(n);
    	bool flag = false;
    	fo(i,n){
    		cin>>a[i];
    		if(a[i]==2048){
    			flag = true;
    		}
    	}
    	map<int,int> hash;
    	for(int i=0;i<12;i++){
    		hash[(int)pow(2,i)] = 0;
    	}
    	fo(i,n){
    		if(a[i]<=2048){
    			hash[a[i]]++;
    		}
    	}
    	map<int,int> :: iterator it;
    	for(it = hash.begin();it!=hash.end();it++){
    		if(it->first!=2048){
	    		if(it->second >= 2){
	    			int freq = it->second/2;
	    			map<int,int> :: iterator it1 = it;
	    			it1++;
	    			it1->second += freq;
	    		}
    		}
    	}
    	if(hash[2048]>0){
    		flag = true;
    	}
    	if(flag){
    		cout<<"YES"<<endl;
    	}else{
    		cout<<"NO"<<endl;
    	}
    }
}