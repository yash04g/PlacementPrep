#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll cost = 0;
	ll i=0;
	while(i<(n-1)){
		ll j = i+1;
		while(j<(n-1)){
			if( ( abs(a[i]) > abs(a[j]) ) || ( ( abs(a[i])==abs(a[j]) ) && a[i]>0 ) ){
				break;
			}else{
				j++;
			}
		}
		cost += (j-i)*a[i] + (j*j-i*i)*a[i]*a[i];
		i = j;
	}
	cout<<cost<<endl;	
}