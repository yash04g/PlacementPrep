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
	bool isCyclicBFS(T src){
		map<T,bool> visited;
		map<T,int> parent;
		queue<int> q;
		visited[src] = true;
		parent[src] = src;
		q.push(src);
		while(!q.empty()){
			T node = q.front();
			q.pop();
			for(auto neighbour : adjList[node]){
				if(visited[neighbour] && parent[node]!=neighbour){
					return true;
				}else if(!visited[neighbour]){
					parent[neighbour] = node;
					visited[neighbour] = true;
					q.push(neighbour);
				}
			}
		}
		return false;
	}
};
int main(){
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,2);
	// g.addEdge(1,2);
	g.addEdge(2,3);
	if(g.isCyclicBFS(2)){
		cout<<"Graph is cyclic"<<endl;
	}else{
		cout<<"Graph is Not cyclic"<<endl;
	}
}