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
	
	void TopologicalSort(){
		map<T,bool> visited;
		map<T,int> indegree;
		queue<T> q;
		
		for(auto i:adjList){
			// i is the pair of node and its adjList
			T node = i.first;
			visited[node] = false;
			indegree[node] = 0;
		}
		// Initialize the indegrees of all nodes
		for(auto i:adjList){
			T u = i.first;
			for(T v:adjList[u]){
				indegree[v]++;
			}
		}
		// Find all Nodes with 0 indegrees
		for(auto i:adjList){
			T node = i.first;
			if(indegree[node]==0)
				q.push(node);
		}
		// Algorithm starts
		while(!q.empty()){
			T node = q.front();
			cout<<node<<"-->";
			q.pop();
			for(T neighbour : adjList[node]){
				indegree[neighbour]--;
				if(indegree[neighbour]==0){
					q.push(neighbour);
				}
			}
		}

	}
};
int main(){
	Graph<string> g;
	g.addEdge("English","Programming Logic",false);
	g.addEdge("Maths","Programming Logic",false);
	g.addEdge("Programming Logic","HTML",false);
	g.addEdge("Programming Logic","Python",false);
	g.addEdge("Programming Logic","Java",false);
	g.addEdge("Programming Logic","JS",false);
	g.addEdge("Python","WebD",false);
	g.addEdge("HTML","CSS",false);
	g.addEdge("CSS","JS",false);
	g.addEdge("JS","WebD",false);
	g.addEdge("Java","WebD",false);
	g.addEdge("Python","WebD",false);
	g.TopologicalSort();
}