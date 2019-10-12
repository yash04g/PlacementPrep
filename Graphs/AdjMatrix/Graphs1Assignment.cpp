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
#define pdd pair<double,double>
#define MAXN 100005
char pattern[11] = {'C','O','D','I','N','G','N','I','N','J','A'};
int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
int visited[MAXN][MAXN];

int validPoint(int x,int y,int M,int N){
	return (x>=0 && x<N && y>=0 && y<M);
}

int DFS(char Graph[][MAXN],int N, int M,int x,int y,int idx){
	if(idx==11){
		return 1;
	}
	visited[x][y] = 1;
	int i,newx,newy;
	int found = 0;
	for(int i=0;i<8;i++){	
		newx = x+dir[i][0];
		newy = y+dir[i][1];
		if(validPoint(newx,newy,M,N) && Graph[newx][newy]==pattern[idx] && !visited[newx][newy]){
			found = found | DFS(Graph,N,M,newx,newy,idx+1);
		}
	}
	visited[x][y] = 0;
	return found;
}
int solve(char Graph[][MAXN],int N, int M){
    int foundIdx = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(Graph[i][j]=='C'){
 				foundIdx = DFS(Graph,N,M,i,j,1);
 				if(foundIdx){
 					break;
 				}               
            }
        }
        if(foundIdx){
        	break;
        }
    }
    return foundIdx;
}


int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int t;
    cin >> t;
    while (t--){

    }
}