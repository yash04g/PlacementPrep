#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
void groups(vi &a,int n){
	if(n==0)
		return;
	for(int i=0;i<n/2;i++){
		int groups = 0;
		int left = 0;
		groups = (a[i]+a[n-i-1])/10;
		left = (a[i]+a[n-i-1])%10;
		cout<<groups<<left<<endl;
	}
	return;
}
int main(){
    int n;
    cin>>n;
    vi population(n);
    fo(i,n){
    	cin>>population[i];
    }
    groups(population,n);
}