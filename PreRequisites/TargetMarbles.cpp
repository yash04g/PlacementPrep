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
vi isPossible(vi &marbles,int n,bool &flag,int target){
	vi ans;
	int endIndex = -1;
	int minLen = INT_MAX;
	int currlen = 0;
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += marbles[i];
		if(sum==target && currlen<minLen){
			minLen = currlen+1;
			currlen = 0;
			endIndex = i;
			sum = 0;
			flag = true;
			i--;
			// continue;
		}
		if(sum>target){
			sum = 0;
			currlen = 0;
			// continue;
		}
		else{
			currlen++;
			continue;
		}
	}
	if(flag){
		int start = endIndex+1-minLen;
		for(int i=start;i<=endIndex;i++){
			ans.pb(marbles[i]);
		}
	}
	return ans;
}
int main(){
    int n,target;
    cin>>n>>target;
    vi marbles(n);
    fo(i,n){
    	cin>>marbles[i];
    }
    bool flag = false;
    vi ans = isPossible(marbles,n,flag,target);
    if(flag){
    	cout<<"true"<<endl;
    	for(int j=0;j<ans.size();j++){
    		cout<<ans[j]<<" ";
    	}
    	cout<<endl;
    }
    else{
    	cout<<"false"<<endl;
    }
}