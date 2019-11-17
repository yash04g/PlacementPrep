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
    int n;
    cin>>n;
    vi a(n);
    fo(i,n){
    	cin>>a[i];
    }
    int cnt = 1;
    int sum = a[0];
    vi ans;
    Fo(i,1,n){
    	sum += a[i];
    	cnt += 1;
    	if(sum==0){
    		ans.pb(cnt);
    		cnt = 0;
    	}
    }
    bool flag = true;
    if(sum!=0){
    	cout<<-1<<endl;
    	exit(0);
    }
    set<int> s;
    fo(i,n){
    	if(sum==0){
    		s.clear();
    		sum += a[i];
    		s.insert(a[i]);
    	}
    	else{
    		if(s.find(a[i])==s.end()){
    			s.insert(a[i]);
    			sum += a[i];
    		}else{
    			flag = false;
    			break;
    		}

    	}
    }
    
    if(!flag){
    	cout<<-1<<endl;
    }else{
    	cout<<ans.size()<<endl;
    	fo(i,ans.size()){
    		cout<<ans[i]<<" ";
    	}
    	cout<<endl;
    }
}