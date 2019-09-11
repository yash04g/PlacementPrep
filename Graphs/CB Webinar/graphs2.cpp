#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
	map<T,list<T> > adjList;
public:
	Graph(){

	}
	void addEdge(T u,T v,bool bidir = true){
		adjList[u].push_back(v);
		if(bidir){
			adjList[v].push_back(u);
		}
	}
	void printAdjList(){
		for(auto row:adjList){
			T key = row.first;
			cout<<key<<"->";
			for(T element : row.second){
				cout<<element<<",";
			}
			cout<<endl;
		}
	}
};
int main(){
	Graph<string> g;
	g.addEdge("Amritsar","Delhi");
	g.addEdge("Amritsar","Jaipur");
	g.addEdge("Siachen","Delhi");
	g.addEdge("Bangalore","Delhi");
	g.addEdge("Agra","Delhi");
	g.addEdge("Amritsar","Siachen");
	g.printAdjList();

}