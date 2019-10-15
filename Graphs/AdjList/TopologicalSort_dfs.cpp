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
	void dfsHelper(T node,map<T,bool> &visited,list<T> &ordering){
		visited[node] = true;
		for(auto neighbour:adjList[node]){
			if(!visited[neighbour]){
				dfsHelper(neighbour,visited,ordering);
			}
		}
		// Add 1 line for Topological Sort
		// At this point all the children of current node have been visited so we can add current node to the list
		ordering.push_front(node);
	}
	void dfsTopologicalSort(){
		map<T,bool> visited;
		list<T> ordering;
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				dfsHelper(node,visited,ordering);
			}
		}
		for(T elem:ordering){
			cout<<elem<<"-->";
		}
		cout<<endl;
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
	g.dfsTopologicalSort();
	Graph<int> g2;
    g2.addEdge(1,3,false);
    g2.addEdge(2,3,false);
    g2.addEdge(3,5,false);
    g2.addEdge(3,4,false);
    g2.addEdge(5,6,false);
    g2.addEdge(4,6,false);
    g2.addEdge(2,5,false);
    cout<<"DFS Topological Sort is "<<endl;
    g2.dfsTopologicalSort();
}