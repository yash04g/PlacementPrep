#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(pair<int,int> &a,pair<int,int> &b){
	if(a.second!=b.second){
		return a.second>b.second;
	}
	return a.first<b.first;
}
int main(){
	int n,k;
	cin>>n>>k;
	pair<int,int>* pieces = new pair<int,int>[n];
	for(int i=0;i<n;i++){
		cin>>pieces[i].first>>pieces[i].second;
	}
	sort(pieces,pieces+n,compare);

	multiset<int> m;
	for(int i=0;i<k;i++){
		int weight;
		cin>>weight;
		m.insert(weight);
	}
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(m.empty()){
			break;
		}
		else if(m.lower_bound(pieces[i].first)!=m.end()){
			ans += pieces[i].second;
			m.erase(m.lower_bound(pieces[i].first));
		}
	}
	cout<<ans<<endl;
}