#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
vector<int> *getPathBFS(int **edges,int n,int sv,int ev){
	bool *visited = new bool[n];
	queue<int> pn;
	pn.push(sv);
	visited[sv] = true;
	vector<int>* output;
	unordered_map<int,int> parent;
	bool done = false;
	while(!pn.empty() && !done){
		int front = pn.front();
		if(front==ev){
			output->push_back(front);
		}
		pn.pop();
		for(int i=0;i<n;i++){
			if(edges[front][i] && !visited[i]){
				parent[i] = front;
				pn.push(i);
				visited[i] = true;
				if(i==ev){
					done = true;
					break;
				}
			}
		}
	}
	delete [] visited;
	if(!done){
		return NULL;
	}else{
		vector<int>* output = new vector<int>();
		output->push_back(ev);
		int curr = ev;
		while(curr!=sv){
			curr = parent[curr];
			output->push_back(curr);
		}
		return output;
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	int **edges = new int*[n];
	for(int i=0;i<n;i++){
		edges[i] = new int[n];
		for(int j=0;j<n;j++){
			edges[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++){
		int s,f;
		cin>>s>>f;
		edges[s][f] = 1;
		edges[f][s] = 1;
	}
	int sv,ev;
	cin>>sv>>ev;
	vector<int>* output = getPathBFS(edges,n,sv,ev);
	if(output!=NULL){
		for(int i=0;i<output->size();i++){
			cout<<output->at(i)<<" ";
		}
	}
}