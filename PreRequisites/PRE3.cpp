#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define pb push_back
#define vi vector<int>
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
int sum(vvi a,int n){
	map<pair<int,int>,bool> hash;
	int sum = 0;

	for(int i=0;i<n;i++){
		if(!hash[mp(i,0)]){
			sum += a[i][0];
			hash[mp(i,0)] = true;
		}
		if(!hash[mp(0,i)]){
			sum += a[0][i];
			hash[mp(0,i)] = true;
		}
		if(!hash[mp(i,i)]){
			sum += a[i][i];
			hash[mp(i,i)] = true;
		}
		if(!hash[mp(n-i-1,i)]){
			sum += a[n-i-1][i];
			hash[mp(n-i-1,i)] = true;;
		}
		if(!hash[mp(i,n-1)]){
			sum += a[i][n-1];
			hash[mp(i,n-1)] = true;
		}
		if(!hash[mp(n-1,i)]){
			sum += a[n-1][i];
			hash[mp(n-1,i)] = true;
		}
	}
	return sum;
}
int main(){
	int n;
	cin>>n;
	vvi a(n,vi(n,0));
	fo(i,n){
		fo(j,n){
			int temp;
			cin>>temp;
			a[i][j] = temp;
		}
	}
	cout<<sum(a,n)<<endl;
}