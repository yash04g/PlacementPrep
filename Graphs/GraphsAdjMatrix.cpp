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
void printBFS(int **edges,int n,int sv){
	bool *visited = new bool[n]();
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
int main(){
// 7
// 8
// 0 1
// 0 2
// 1 3
// 1 4
// 4 5
// 5 6
// 6 2
// 3 5
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
	bool *visited = new bool[n]();
	printDFS(edges,n,0,visited);
	cout<<endl;
	printBFS(edges,n,0);
	
	// Delete the memory
	delete [] visited;
	for(int i=0;i<n;i++){
		delete [] edges[i];
	}
	delete [] edges;
}