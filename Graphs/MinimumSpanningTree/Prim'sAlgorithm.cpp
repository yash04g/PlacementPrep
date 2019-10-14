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

int getMinVertex(bool *visited,int *weight,int n){
	int minVertex = -1;
	fo(i,n){
		if(!visited[i] && (minVertex==-1 || weight[i]<weight[minVertex])){
			minVertex = i;
		}
	}
	return minVertex;
}

void prims(int n,int **edges){
	bool *visited = new bool[n]();
	int *parent = new int[n];
	int *weight = new int[n];
	fo(i,n){
		weight[i] = INT_MAX;
	}
	parent[0] = -1;
	weight[0] = 0;

	fo(i,n){
		//Find the minVertex i.e unvisited vertex with minimum weight
		int minVertex = getMinVertex(visited,weight,n);
		visited[minVertex] = true;
		fo(j,n){
			if(!visited[j] && edges[minVertex][j]!=0){
				if(weight[j]>edges[minVertex][j]){
					parent[j] = minVertex;
					weight[j] = edges[minVertex][j];
				}
			}
		}
	}
	Fo(i,1,n){
		if(i<parent[i]){
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		}else{
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
		}
	}
}

int main(){
// 5 7
// 0 1 4
// 0 2 8
// 1 2 2
// 1 3 6
// 2 3 3
// 2 4 9
// 3 4 5
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int n,e;
    cin>>n>>e;
    int **edges = new int*[n];
	fo(i,n){
		edges[i] = new int[n];
		fo(j,n){
			edges[i][j] = 0;
		}
	}
	fo(i,e){
		int f,s,w;
		cin>>f>>s>>w;
		edges[f][s] = w;
		edges[s][f] = w;	
	}
	prims(n,edges);

}