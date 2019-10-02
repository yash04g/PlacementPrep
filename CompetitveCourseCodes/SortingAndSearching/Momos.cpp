#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
void momos(vi &prices,int n,int q,int money){
	vi prefixSum(n-1);
	Fo(i,1,n){
		prefixSum[i-1] = prices[i-1]+prices[i];
	}
	int s = 0;
	int e = n-2;
	int moneyLeft = 0;
	while(q--){
		int ans = 0;
		while(s<=e){
			int mid = (s+e)/2;
			int money1 = money+moneyLeft;
			if(prefixSum[mid]<=money1){
				ans = mid;
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}
		moneyLeft = money - prefixSum[ans];
		cout<<ans+1<<" "<<moneyLeft<<endl;
	}
}
int main(){
    int n;
    cin>>n;
    vi prices(n);
    fo(i,n)
    	cin>>prices[i];
    int q;
    cin>>q;
    int money;
    cin>>money;
    momos(prices,n,q,money);
}