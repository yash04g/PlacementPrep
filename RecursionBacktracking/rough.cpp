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
int board[11][11];
int ans[21][21];
bool isPossible(int n,int row,int col){
	for(int i=row-1;i>=0;i--){
		if(board[i][col]==1){
			return false;
		}
	}
	for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
		if(board[i][j]==1)
			return false;
	}
	for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
		if(board[i][j]==1)
			return false;
	}
	return true;
}
void helper(int n,int row){
	if(row==n){
		fo(i,n){
			fo(j,n){
				cout<<board[i][j]<<" ";
			}
		}
		cout<<endl;
		return;
	}
	for(int j=0;j<n;j++){
		if(isPossible(n,row,j)){
			board[row][j] = 1;
			helper(n,row+1);
			board[row][j] = 0;
		}
	}
	return;
}
void placeNQueens(int n){
	memset(board,0,sizeof(board));
	helper(n,0);
}
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
	if(row>=n || row<0 || col>=n || col<0 || maze[row][col]==0 || ans[row][col] =`= 1){
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
bool isPossible(int board[][9],int n,int num,int row,int col){
    for(int x=0;x<n;x++){
        if(board[x][col]==num || board[row][x]==num)
            return false;
    }
    int sx = (row/3)*3;
    int sy = (row/3)*3;
    for(int i=sx;i<sx+3;i++){
        for(int j=sy;j<sy+3;j++){
            if(board[i][j]==num){
                return false;
            }
        }
    }
    return true;
}
bool helper(int board[][9],int n,int row,int col){
    if(row==n){
        return true;
    }
    if(col==n){
        return helper(board,row+1,col);
    }
    if(board[row][col]!=0){
        return helper(board,row,col+1);
    }
    for(int num=1;num<=n;num++){
        if(isPossible(board,n,num,row,col)){
            board[row][col] = num;
            bool canSolve = helper(board,n,row,col+1);
            if(canSolve)
                return true;
        }
    }
    board[row][col] = 0;
    return false;
}
bool sudokuSolver(int board[][9]){
    return helper(board,9,0,0);

int main(){
    int n;
    cin>>n;
    placeNQueens(n);

}