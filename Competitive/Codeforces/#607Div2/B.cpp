#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define fo(i,n) for(int i=0;i<n;++i)
#define Fo(i,k,n) for(int i=k;i<n;++i)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
#define all(v) v.begin(),v.end()
#define mi map<int,int>
#define mc map<char,int>  
#define pll pair<int,int>
#define pdd pair<double,double>
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

void get_it_done(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}
const int N = 1e5+5;
int dp[N];


int32_t main(){
	get_it_done();
    int t=1;
    cin >> t;
    while (t--){
    	string s,c;
    	cin>>s>>c;
    	char min = 'z';
    	int idx = -1;
    	bool flag = true;
    	Fo(i,1,s.size()){
    		if(s[i]==s[0] && flag){
    			if((i!=s.size()-1) && s[i+1]!=s[0]){
    				flag = false;
    			}
    			continue;
    		}
    		if(s[i]<min){
    			min = s[i];
    			idx = i;
    			flag = false;
    		}
    	}
    	if(idx==-1){
    		if(s>=c){
    			cout<<"---"<<endl;
    			continue;
    		}
    	}else{
    		if(min<s[0]){
    			char temp = s[0];
    			s[0] = min;
    			s[idx] = temp;
    			if(s<c){
    				cout<<s<<endl;
    				continue;
    			}else{
    				cout<<"---"<<endl;
    				continue;
    			}
    		}else{
    			int j = 1;
    			while(j<idx){
    				if(s[j]>min){
    					char temp = s[j];
    					s[j] = min;
    					s[idx] = temp;
    					break;
    				}
    				j++;
    			}
    			if(s<c){
    				cout<<s<<endl;
    				continue;
    			}else{
    				cout<<"---"<<endl;
    				continue;
    			}
    		}
    	}

    }
}
