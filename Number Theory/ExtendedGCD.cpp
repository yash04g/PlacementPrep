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

class triplet{
public:
	int x;
	int y;
	int gcd;
};

triplet extendedGCD(int a,int b){
	// if(a<b){
	// 	return extendedGCD(b,a);
	// }
	if(b==0){
		triplet ans;
		ans.gcd = a;
		ans.x = 1;
		ans.y = 0;
		return ans;
	}
	triplet smallAns = extendedGCD(b,a%b);
	triplet ans;
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.y;
	ans.y = smallAns.x-(a/b)*smallAns.y;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    triplet ans = extendedGCD(16,10);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
    // ans = extendedGCD(2,5);
    // cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
    ans = extendedGCD(10,16);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;
}