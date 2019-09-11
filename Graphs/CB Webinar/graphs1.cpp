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
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(3,2);
	g.addEdge(3,5);
	g.addEdge(3,4);
	g.printAllEdges();
	g.bfs(0,3);
}