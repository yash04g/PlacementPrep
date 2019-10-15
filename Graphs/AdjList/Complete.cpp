#include <bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int>* adjList;
public:
    Graph(int v){
        this->V = v;
        adjList = new list<int>[V+1];
    }   
    void addEdge(int u,int v,bool bidir = true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }
    void print(){
        for(int i=1;i<=V;i++){
            cout<<i<<"->";
            // for(int node : adjList[i]){
            //     cout<<node<<",";
            // }
            list<int>::iterator it;
            for (it = adjList[i].begin(); it != adjList[i].end(); it++){
                cout << *it << ",";
            }
            cout<<endl;
        }
    }
    void bfsHelper(int src,int dest,bool *visited){
        int *parent = new int[V+1];
        int *dist = new int[V+1]();
        queue<int> q;
        q.push(src);
        parent[src] = src;
        visited[src] = true;
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            for(int neighbour : adjList[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                    dist[neighbour] = dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }
        cout<<endl<<"The shortest distance from source to node is "<<dist[dest]<<endl;
        cout<<"The shortest Path is ";
        int temp = dest;
        while(temp!=src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;
    }
    void bfs(int src,int dest){
        bool *visited = new bool[V+1]();
        int component = 0;
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                bfsHelper(i,dest,visited);
                component++;
            }
        }
        cout<<component<<endl;
    }
    void dfsHelper(int src,bool *visited){
        cout<<src<<" ";
        visited[src] = true;
        for(int neighbour : adjList[src]){
            if(!visited[neighbour]){
                dfsHelper(neighbour,visited);
            }
        }
    }
    void dfs(int src){
        bool *visited = new bool[V + 1]();
        int component = 0;
        for (int i = 1; i <= V; i++){
            if (!visited[i]){
                dfsHelper(i,visited);
                component++;
            }
        }
        cout << endl << component << endl;
    }
    void dfsTSHelper(int node,bool *visited,list<int> &ordering){
        visited[node] = true;
        for (int neighbour : adjList[node]){
            if (!visited[neighbour]){
                dfsTSHelper(neighbour,visited,ordering);
            }
        }
        ordering.push_front(node);
    }
    void dfsTopologicalSort(){
        list<int> ordering;
        bool *visited = new bool[V+1]();
        for(int i=1;i<=V;i++){
            if(!visited[i]){
                dfsTSHelper(i,visited,ordering);
            }
        }
        for(int elem : ordering){
            cout<<elem<<" ";
        }
        cout<<endl;
    }
    void bfsTopologicalSort(){
        bool *visited = new bool[V+1]();
        int *indegree = new int[V+1]();
        queue<int> q;
        // Initializing the indegrees of all nodes
        for(int i=1;i<=V;i++){
            for(int node : adjList[i]){
                indegree[node]++;
            }
        }
        // Finding all nodes with 0 indegree
        for(int i=1;i<=V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        // Start with algorithm
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout<<node<<"-->";
            for(int neighbour : adjList[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
    }

};


int main(){
	Graph g(5);
    g.addEdge(1,2);
    g.addEdge(3,2);
    g.addEdge(5,2);
    g.addEdge(4,5);
    g.addEdge(5,3);
    g.print();
    cout<<"BFS"<<endl;
    g.bfs(1,4);
    cout<<"DFS"<<endl;
    g.dfs(1);
    Graph g2(6);
    g2.addEdge(1,3,false);
    g2.addEdge(2,3,false);
    g2.addEdge(3,5,false);
    g2.addEdge(3,4,false);
    g2.addEdge(5,6,false);
    g2.addEdge(4,6,false);
    g2.addEdge(2,5,false);
    cout<<"DFS Topological Sort is "<<endl;
    g2.dfsTopologicalSort();
    cout<<"BFS Topological Sort is "<<endl;
    g2.bfsTopologicalSort();
}