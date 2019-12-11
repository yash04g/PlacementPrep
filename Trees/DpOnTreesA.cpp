#include<bits/stdc++.h>
using namespace std;
void dfs(int child,int parent,vector<int> &dp,vector<int> &values,vector<vector<int> > &edges){
	dp[child] = values[child];
	int maxima = 0;
	for(int i:edges[child]){
		if(child == parent){
			continue;
		}
		dfs(i,child,dp,values,edges);
		maxima = max(maxima,dp[child]);
	}
	dp[child] += maxima;
}
int main(){
// 	14 13
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 5 11
// 5 12
// 3 7
// 7 13
// 7 14
// 4 8
// 4 9
// 4 10
// 3 2 1 10 1 3 9 1 5 3 4 5 9 8  ans=> 22
	int n,e;
	cin>>n>>e;
	vector<vector<int> > edges(n+1);
	for(int i=1;i<=e;i++){
		int f,s;
		cin>>f>>s;
		edges[f].push_back(s);
		edges[s].push_back(f);
	}
	vector<int> values;
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		values.push_back(temp);
	}
	vector<int> dp(n+1,0);
	dfs(1,0,dp,values,edges);
	cout<<dp[1]<<endl;
}