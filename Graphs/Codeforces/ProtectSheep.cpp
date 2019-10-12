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
int r,c;
char pasture[505][505];
int direction[4][4] = {{-1,0},{1,0},{0,1},{0,-1}};
bool isPossible(int x,int y,int r,int c){
	return (x>=1 && x<=r && y>=1 && y<=c);
}

bool possible(int r,int c){
	bool flag = true;
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(pasture[i][j]=='S'){
				for(int k=0;k<4;k++){
					int newX = i+direction[k][0];
					int newY = j+direction[k][1];
					if(isPossible(newX,newY,r,c)){
						if(pasture[newX][newY]=='W'){
							flag = false;
						}else if(pasture[newX][newY]=='.'){
							pasture[newX][newY] = 'D';
						}
					}
				}
			}
		}
	}
	return flag;
}

int main(){
	ios::sync_with_stdio(false);
  	cin.tie(0);
  	cout.tie(0);
    cin>>r>>c;
    for(int i=1;i<=r;i++){
    	for(int j=1;j<=c;j++){
    		cin>>pasture[i][j];
    	}
    }
    if(possible(r,c)){
    	cout<<"Yes"<<endl;
    	for(int i=1;i<=r;i++){
    		for(int j=1;j<=c;j++){
    			cout<<pasture[i][j];
    		}
    		cout<<endl;
		}
		cout<<endl;
    }else{
    	cout<<"No"<<endl;
    }
}