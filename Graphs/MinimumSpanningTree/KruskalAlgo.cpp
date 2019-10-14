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
class Edge{
public:
	int src;
	int dest;
	int weight;
};
bool compare(Edge e1,Edge e2){
	return e1.weight<e2.weight;
}

int getParent(int a,int *parent){
	if(parent[a]==a){
		return a;
	}
	return getParent(parent[a],parent);
}

Edge *KruskalsAlgo(Edge* edges,int n,int e){
	// Sort the edges array in the increasing order
	sort(edges,edges+e,compare);

	Edge *output = new Edge[e];
	int *parent = new int[n];
	for(int i=0;i<e;i++){
		parent[i] = i;
	}
	int cnt = 0;
	int i = 0;
	while(cnt<(n-1)){
		Edge currEdge = edges[i];
		int srcParent = getParent(currEdge.src,parent);
		int destParent = getParent(currEdge.dest,parent);
		if(srcParent!=destParent){
			output[cnt] = currEdge;
			cnt++;
			parent[destParent] = srcParent;
		}
		i += 1;
	}
	return output;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int n,e;
    cin>>n>>e;
    Edge *edges = new Edge[e];
    for(int i=0;i<e;i++){
    	cin>>edges[i].src;
    	cin>>edges[i].dest;
    	cin>>edges[i].weight;
    }
    Edge *output = KruskalsAlgo(edges,n,e);
    for(int i=0;i<n-1;i++){
		if(output[i].src<output[i].dest){
			cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
		}
		else{
			cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
		}
	}

}