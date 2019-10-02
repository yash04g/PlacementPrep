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
int variation(vi &sequence,int n,int k){
	if(n<=1){
		return 0;
	}
	sort(sequence.begin(),sequence.end());
	int j;
	int count = 0;
	fo(i,n){
		j = i+1;
		while(abs(sequence[i]-sequence[j])<k){
			j++;
		}
		count += n-j;
	}
	return count;
}
int main(){
    int n,k;
    cin>>n>>k;
    vi sequence(n);
    fo(i,n){
    	cin>>sequence[i];
    }
    cout<<variation(sequence,n,k)<<endl;
}