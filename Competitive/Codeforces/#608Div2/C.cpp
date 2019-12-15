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
    // cin >> t;
    while (t--){
		int n;
		cin>>n;
		int sx,sy;
		cin>>sx>>sy;
		int gsx=0,ssx=0,gsy=0,ssy=0;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			if(x>sx){
				gsx++;
			}
			else if(x<sx){
				ssx++;
			}
			if(y>sy){
				gsy++;
			}
			else if(y<sy){
				ssy++;
			}
		}
		if(gsx>=ssx && gsx>=gsy && gsx>=ssy){
			cout<<gsx<<endl;
			cout<<sx+1<<" "<<sy;
		}
		else if(ssx>=gsx && ssx>=gsy && ssx>=ssy){
			cout<<ssx<<endl;
			cout<<sx-1<<" "<<sy;
		}
		else if(gsy>=ssx && gsy>=gsx && gsy>=ssy){
			cout<<gsy<<endl;
			cout<<sx<<" "<<sy+1;
		}
		else if(ssy>=ssx && ssy>=gsy && ssy>=gsx){
			cout<<ssy<<endl;
			cout<<sx<<" "<<sy-1;
		}
    }
}
