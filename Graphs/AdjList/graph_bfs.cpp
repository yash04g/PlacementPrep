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
	void bfsHelper(int src,int dest,bool *visited){
		queue<int> q;
		int *dist = new int[V+1]();
		int *parent = new int[V+1];
		for(int i=0;i<V;i++){
			parent[i] = -1;
		}
		q.push(src);
		visited[src] = true;
		parent[src] = src;
		dist[src] = 0;
		while(!q.empty()){
			int node = q.front();
			cout<<node<<" ";
			q.pop();
			for(auto neighbour:adjList[node]){
				if(!visited[neighbour]){
					q.push(neighbour);
					visited[neighbour] = true;
					dist[neighbour] = dist[node]+1;
					parent[neighbour] = node;
				}
			}
		}
		cout<<endl;
		/// Print the distance of every node from source
		for(int i=0;i<V;++i){
			cout<<i<<" node having dist "<<dist[i]<<endl;
		}
		cout<<"Shortest distance is "<<dist[dest]<<endl;
		cout<<"Shortest Path is ";
		int temp = dest;
		while(temp!=src){
			cout<<temp<<"<-- ";
			temp = parent[temp];
		}
		cout<<src<<endl; // As the loop terminates there
	}
	void bfs(int src,int dest){
		bool *visited = new bool[V]();
		int component = 0;
		for(int i=0;i<V;i++){
			if(!visited[i]){
				bfsHelper(src,dest,visited);
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
	g.printAllEdges();
	g.bfs(0,5);
	// g.bfs(0,3);
}