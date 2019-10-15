#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int, int>>
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; i < n; ++i)
#define deb(x) cout << #x << " " << x << endl;
#define mp make_pair
#define mod 1000000007
#define pii pair<int, int>
#define pdd pair < double, double
#define endl "\n"
class Graph{
    int V;
    list<int> *adjList;

public:
    Graph(int v)
    {
        this->V = v;
        adjList = new list<int>[V + 1];
    }
    void addEdge(int u, int v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void dfsHelper(int src, bool *visited,vi &res,vll &c){
        res.pb(c[src]);
        visited[src] = true;
        for (int neighbour : adjList[src]){
            if (!visited[neighbour]){
                dfsHelper(neighbour, visited,res,c);
            }
        }
    }
    vvi dfs(int src,vll &c){
        bool *visited = new bool[V + 1]();
        vvi ans;
        for (int i = 1; i <= V; i++){
            if (!visited[i]){
                vi res;
                dfsHelper(i,visited,res,c);
                ans.pb(res);
            }
        }
        return ans;
    }
};
int main(){
    int n,e;
    cin >> n >> e;
    vll c(n+1);
    Fo(i,1,n+1) cin >> c[i];
    Graph g(n);
    fo(i,e){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    ll ans = 0;
    if(e==0){
        Fo(i,1,n+1){
            ans += c[i];
        }
    }else{
        vvi arr = g.dfs(1,c);
        int components = arr.size(); 
        for(int i=0;i<components;i++){
            int minCost = INT_MAX;
            for(int node : arr[i]){
                minCost = min(minCost,node);
            }
            ans += minCost;
        }
    }
    cout<<ans<<endl;


}