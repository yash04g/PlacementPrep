#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
template<typename T>
class Graph{
	map<T,list<T> > adjList;
public:
	Graph(){

	}
	void addEdge(T u,T v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	void print(){
		// Iterate over the map
		for(auto i:adjList){
			cout<<i.first<<"-> ";
			// i.second is the LL
			for(auto entry:i.second){
				cout<<entry<<",";
			}
			cout<<endl;
		}
	}
	void bfsHelper(T src,T dest,map<T,bool> &visited){
		queue<T> q;
		map<T,int> dist;
		map<T,T> parent;
		q.push(src);
		visited[src] = true;
		parent[src] = src;
		dist[src] = 0;
		while(!q.empty()){
			T node = q.front();
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
		for(int i=0;i<dist.size();++i){
			cout<<i<<" node having dist "<<dist[i]<<endl;
		}
		cout<<"Shortest distance is "<<dist[dest]<<endl;
		cout<<"Shortest Path is ";
		T temp = dest;
		while(temp!=src){
			cout<<temp<<"<-- ";
			temp = parent[temp];
		}
		cout<<src<<endl; // As the loop terminates there
	}
	void bfs(T src,T dest){
		map<T,bool> visited;
		int component = 1;
		bfsHelper(src,dest,visited);
		cout<<endl;
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				bfsHelper(node,dest,visited);
				component++;
			}
		}
		cout<<component<<endl;
	}

	void dfsHelper(T src, map<T,bool> &visited){
		// Whenever you come to node mark it visited
		visited[src] = true;
		cout<<src<<" ";
		// Find a node which is neighbour of src and not visited
		for(T neighbour:adjList[src]){
			if(!visited[neighbour]){
				dfsHelper(neighbour,visited);
			}
		}
	}
	void dfs(T src){
		map<T,bool> visited;
		int component = 1;
		dfsHelper(src,visited);
		cout<<endl;
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				dfsHelper(node,visited);
				component++;
			}
		}
		cout<<component<<endl;
	}

};
int main(){
	// Graph<string> g;
	// g.addEdge("Putin","Trump",false);
	// g.addEdge("Putin","Modi",false);
	// g.addEdge("Putin","Pope",false);
	// g.addEdge("Modi","Trump",true);
	// g.addEdge("Modi","Yogi",true);
	// g.addEdge("Yogi","Prabhu",false);
	// g.addEdge("Prabhu","Modi",false);
	// g.print();
	// Graph<int> g1;
	// g1.addEdge(1,2);
	// g1.addEdge(100,20);
	// g1.addEdge(1,100);
	// g1.print();
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(3,2);
	g.addEdge(3,5);
	g.addEdge(3,4);
	g.print();
	g.bfs(0,5);
	g.dfs(0);
}