#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
int profit(vi &price,int n){
	if(n<=1)
		return 0;
	vi sample;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(price[j]>=price[i]){
				sample.pb(price[j]-price[i]);
			}
		}
	}
	sort(sample.begin(),sample.end());
	int n1 = sample.size();
	return sample[n1-1];
}
int main(){
    int n;
    cin>>n;
    vi price(n);
    fo(i,n){
    	cin>>price[i];
    }
    cout<<profit(price,n)<<endl;
}