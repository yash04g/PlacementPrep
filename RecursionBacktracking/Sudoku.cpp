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
bool isPossible(int board[][9],int n,int num,int row,int col){
    // Corressponding column 
	for(int i=0;i<n;i++){
		if(board[i][col] == num)
			return false;
	}
	// Corressponding row
	for(int i=0;i<n;i++){
		if(board[row][i] == num)
			return false;
	}
    int rn = sqrt(n);
	int sx = (row/rn)*rn;
	int sy = (col/rn)*rn;
	for(int i=sx;i<sx+rn;i++){
		for(int j=sy;j<sy+rn;j++){
			if(board[i][j] == num)
				return false;
		}
	}
	return true;
}
bool helper(int board[][9],int n,int row,int col){
    if(row==n){
        return true;
    }
    if(col==n){
        return helper(board,n,row+1,0);
    }
    if(board[row][col]!=0){
        return helper(board,n,row,col+1);
    }
    for(int i=1;i<=n;i++){
		if(isPossible(board,n,i,row,col)){
			// canPlace function will see if the number i can be placed in that smallgrid or row or column
			board[row][col] = i;
			bool ans = helper(board,n,row,col+1);
			if(ans){
				return true;
			}
		}
	}
    board[row][col] = 0;
    return false;
}
bool sudokuSolver(int board[][9]){
    return helper(board,9,0,0);
}
int main(){
	
}