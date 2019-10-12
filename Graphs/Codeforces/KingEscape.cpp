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
int dir[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
bool visited[1005][1005]={0};
bool isPossible(int x,int y,int n){
	return (x>=1 && x<=n && y>=1 && y<=n);
}
bool possible(int **edges,int n,int bx,int by,int cx,int cy){
	visited[bx][by] = true;
	// cout<<visited[cx][cy]<<endl;
	if(bx==cx && by==cy){
		return true;
	}
	if(edges[bx][by]==-1){
		return false;
	}
	for(int i=0;i<8;i++){
		int newX = bx+dir[i][0];
		int newY = by+dir[i][1];
		// cout<<"1"<<endl;
		if(isPossible(newX,newY,n) && !visited[newX][newY] && edges[newX][newY]==0){
			bool ans = possible(edges,n,newX,newY,cx,cy);
			if(ans){
				return true;
			}
		}
	}
	return false;
}
 

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    int n;
    cin>>n;
    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;
    int **edges = new int*[n+1];
	for(int i=1;i<=n;i++){
		edges[i] = new int[n+1];
		for(int j=1;j<=n;j++){
			edges[i][j] = 0;
		}
	}
	Fo(i,1,n+1){
			edges[ax][i] = -1;
			edges[i][ay] = -1;
			if(ax+i<=n && ax-i>=1 && ay+i<=n && ay-i>=1){
				edges[ax+i][ay+i] = -1;
				edges[ax+i][ay-i] = -1;
				edges[ax-i][ay+i] = -1;
				edges[ax-i][ay-i] = -1;
			}
	}
	
	if(possible(edges,n,bx,by,cx,cy)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	// cx -= ax;
	// cy -= ay;
	// bx -= ax;
	// by -= ay;
	// if(cx*bx>0 && cy*by>0){
	// 	cout<<"YES"<<endl;
	// }else{
	// 	cout<<"NO"<<endl;
	// }
}