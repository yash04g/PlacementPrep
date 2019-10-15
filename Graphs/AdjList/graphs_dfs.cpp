#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	// Making array of LL
	list<int> *adjList;
public:
	Graph(int v){
		V = v;
		adjList = new list<int>[V];
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
	void dfsHelper(int src, bool *visited){
		// Whenever you come to node mark it visited
		visited[src] = true;
		cout<<src<<" ";
		// Find a node which is neighbour of src and not visited
		for(int neighbour:adjList[src]){
			if(!visited[neighbour]){
				dfsHelper(neighbour,visited);
			}
		}
	}
	void dfs(int src){
		bool *visited = new bool[V]();
		int component = 0;
		for(int i=0;i<V;i++){
			if(!visited[i]){
				dfsHelper(src,visited);
				component++;
			}
		}
		cout<<endl<<component<<endl;
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
	// g.printAllEdges();
	g.dfs(0);
} 