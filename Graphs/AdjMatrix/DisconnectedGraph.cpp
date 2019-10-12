#include<bits/stdc++.h>
using namespace std;
void printDFS(int **edges,int n,int sv,bool *visited){
	cout<<sv<<" ";
	visited[sv] = true;
	for(int i=0;i<n;i++){
		if(i==sv){
			continue;
		}
		if(edges[sv][i] && !visited[i]){
			printDFS(edges,n,i,visited);
		}
	}
}
void DFS(int **edges,int n){
	bool *visited = new bool[n]();
	for(int i=0;i<n;i++){
		if(!visited[i])
			printDFS(edges,n,i,visited);
	}
	delete [] visited;
}
void printBFS(int **edges,int n,int sv,bool *visited){
	queue<int> pn;
	pn.push(sv);
	visited[sv] = true;
	while(!pn.empty()){
		int front = pn.front();
		cout<<front<<" ";
		pn.pop();
		for(int i=0;i<n;i++){
			if(edges[i][front] && !visited[i]){
				pn.push(i);
				visited[i] = true;
			}
		}
	}
}
void BFS(int **edges,int n){
	bool *visited = new bool[n]();
	for(int i=0;i<n;i++){
		if(!visited[i])
			printBFS(edges,n,i,visited);
	}
	delete [] visited;
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
	DFS(edges,n);
	cout<<endl;
	BFS(edges,n);
	
	// Delete the memory
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
}