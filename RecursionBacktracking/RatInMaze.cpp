#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
#define mod 1000000007
int ans[21][21];
void helper(int maze[][20],int n,int row,int col){
	if(row==n-1 && col==n-1){
		ans[row][col] = 1;
		fo(i,n){
			fo(j,n){
				cout<<ans[i][j]<<" ";
			}
		}
		cout<<endl;
		return;
	}
	if(row>=n || row<0 || col>=n || col<0 || maze[row][col]==0 || ans[row][col] == 1){
		return;
	}
	ans[row][col] = 1;
	helper(maze,n,row-1,col);
	helper(maze,n,row+1,col);
	helper(maze,n,row,col-1);
	helper(maze,n,row,col+1);
	ans[row][col] = 0;
}
void ratInAMaze(int maze[][20], int n){
	memset(ans,0,sizeof(ans));
	helper(maze,n,0,0);
}
int main(){
    int t;
    cin >> t;
    while (t--){

    }
}