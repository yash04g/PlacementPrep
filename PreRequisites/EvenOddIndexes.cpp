#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
int main(){
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sumo = 0;
	int sume = 0;
	for(int i=0;i<n;i++){
		if(i%2==0 && a[i]%2==0){
			sume += a[i];
		}
		if(i%2!=0 && a[i]%2!=0){
			sumo += a[i];
		}
	}
	cout<<sume<<" "<<sumo<<endl;
}