#include<bits/stdc++.h>
using namespace std;
vector<int>* getPathDSF_helper(int **edges,int n,int sv,int ev,bool* visited){
	if(sv==ev){
		vector<int>* output = new vector<int>();
		output->push_back(ev);
		return output;
	}
	visited[sv] = true;
	for(int i=0;i<n;i++){
		if(edges[sv][i] && !visited[i]){
			vector<int>* smallOutput = getPathDSF_helper(edges,n,i,ev,visited);
			if(smallOutput!=NULL){
				smallOutput->push_back(sv);
				return smallOutput;
			}
		}
	}
	return NULL;
}
vector<int>* getPath_DSF(int **edges,int n,int sv,int ev){
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++){
		visited[i]= false;
	}
	vector<int>* output= getPathDSF_helper(edges,n,sv,ev,visited);
	delete[] visited;
  	return output;
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
	vector<int>* output = getPath_DSF(edges,n,sv,ev);
	if(output!=NULL){
	    for(int i=0;i<output->size();i++){
		    cout<<output->at(i)<<" ";
	    }
    delete output;
	}
  	for(int i=0;i<n;i++){
        delete edges[i];
    }
  	delete[] edges;
}