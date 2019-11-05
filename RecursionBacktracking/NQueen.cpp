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
bool isPossible(int n,int row,int col){
	// Check int the col 
	for(int i=row-1;i>=0;i--){
		if(board[i][col]==1)
			return false;
	}
	// Check in the upper left diagonal
	for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
		if(board[i][j]==1)
			return false;
	}
	// Check in upper right diagonal
	for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
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
	fo(j,n){
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
int main(){
    int n;
    cin>>n;
    placeNQueens(n);
}