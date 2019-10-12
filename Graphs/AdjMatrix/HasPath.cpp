#include<bits/stdc++.h>
using namespace std;
bool hasPath(int **edges,int n,int start,int end,bool *visited){
	if(edges[start][end]){
		return true;
	}
	visited[start] = true;
	for(int i=0;i<end;i++){
		if(edges[start][i] && !visited[i]){
			bool ans = hasPath(edges,n,i,end,visited);
			if(ans){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int n,e;
	cin>>n>>e;
	int **edges = new int*[n];
	for(int i=0;i<n;i++){
		edges[i] = new int[n];
		for(int j=0;j<n;j++){
			edges[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;	
	}
	int start,end;
	cin>>start>>end;
	bool *visited = new bool[n]();
	bool ans = hasPath(edges,n,start,end,visited);
	if(ans){
		cout<<"true";
	}else{
		cout<<"false";
	}
}