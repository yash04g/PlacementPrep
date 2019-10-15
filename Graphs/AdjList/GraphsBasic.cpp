#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"
class Graph{
	int V;
	list<int>* l;
public:
	Graph(int v){
		V = v;
		// Array of Linked Lists
		l = new list<int>[V];
	}
	void addEdge(int u,int v,bool bidir=true){
		l[u].push_back(v);
		if(bidir){
			l[v].push_back(u);
		}
	}
	void printAdjList(){
		for(int i=0;i<V;i++){
			cout<<i<<"-> ";
			for(int vertex : l[i]){
				cout<<vertex<<",";
			}
			cout<<endl;
		}
	}

};


int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(3,4);
	g.addEdge(1,4);
	g.addEdge(2,1);    
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.printAdjList();
}
