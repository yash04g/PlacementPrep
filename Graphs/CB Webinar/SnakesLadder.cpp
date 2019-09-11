#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	// Making array of LL
	list<int> *adjList;
public:
	Graph(int v){
		V = v;
		adjList = new list<int>[v];
	}
	void addEdge(int u,int v,bool bidir = true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	void printAllEdges(){
		for(int i=0;i<V;i++){
			cout<<i<<"-> ";
			for(int node:adjList[i]){
				cout<<node<<",";
			}
			cout<<endl;
		}
	}
	void bfs(int src,int target){
		queue<int> q;
		vector<bool> visited(V,false);
		vector<int> dist(V,0);
		vector<int> parent(V,-1); // initially parent of each node is -1, For source it will always be -1
		q.push(src);
		visited[src] = true;
		while(!q.empty()){
			int node = q.front();
			q.pop();
			cout<<node<<" ";
			for(int neighbour : adjList[node]){
				if(!visited[neighbour]){
					visited[neighbour] = true;
					q.push(neighbour);
					dist[neighbour] = dist[node]+1;
					parent[neighbour] = node;
				}
			}
		}
		cout<<endl;
		// Print the distance of each node from source node
		for(int i=0;i<V;i++){
			cout<<i<<" Node has dist "<<dist[i]<<endl;
		}
		// Shortest path of a given node from source
		cout<<"Shortest distance is "<<dist[target]<<endl;
		cout<<"Shortest Path is ";
		int temp = target;
		while(temp!=-1){
			cout<<temp<<"<--";
			temp = parent[temp];
		}
		cout<<" -1"<<endl;
	}
};

int main(){
	Graph g(50);
	int board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;
	// Insert Edges

	for(int u=0;u<=36;u++){
		//Throw dice from 1 to 6
		for(int i=1;i<=6;i++){
			int v = u+i+board[u+i];
			g.addEdge(u,v,false);
		}
	}
	// Shortest Path
	g.bfs(0,36);
}