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
bool isValidHorizontal(vector<string> &input,string word,int row,int col){
	int size = word.length();
	fo(i,size){
		if(col+i>=10){
			return false;
		}
		if(input[row][col+i]=='-' || input[row][col+i]==word[i]){
			// input[row][col+i]=word[i];
			continue;
		}else{
			return false;
		}
	}
	return true;
}
void setHorizontal(vector<string> &input,string word,vector<bool> &visited,int r,int c){
	int n = word.size();
	fo(i,n){
		if(input[r][c+i]=='-'){
			input[r][c+i] = word[i];
			visited[i] = true;
		}
	}
}
void resetHorizontal(vector<string> &input,string word,vector<bool> &visited,int r,int c){
	int n = word.size();
	fo(i,n){
		if(visited[i]==true){
			input[r][c+i] = '-';
		}
	}
}
bool isValidVertical(vector<string> &input,string word,int row,int col){
	int size = word.length();
	fo(i,size){
		if(row+i>=10){
			return false;
		}
		if(input[row+i][col]=='-' || input[row+i][col]==word[i]){
			// input[row+i][col]=word[i];
			continue;
		}else{
			return false;
		}
	}
	return true;
}
void setVertical(vector<string> &input,string word,vector<bool> &visited,int r,int c){
	int n = word.size();
	fo(i,n){
		if(input[r+i][c]=='-'){
			input[r+i][c] = word[i];
			visited[i] = true;
		}
	}
}
void resetVertical(vector<string> &input,string word,vector<bool> &visited,int r,int c){
	int n = word.size();
	fo(i,n){
		if(visited[i]==true){
			input[r+i][c] = '-';
		}
	}
}
void printCrossword(vector<string> &input){
	fo(i,10){
		fo(j,10){
			cout<<input[i][j];
		}
		cout<<endl;
	}
}
bool crossword(vector<string> &input,vector<string>&words,int index){
	if(index==words.size()){
		// Print the crossword
		printCrossword(input);
		return true;
	}
	fo(r,10){
		fo(c,10){
			if(input[r][c]=='-' || input[r][c]==words[index][0]){
				if(isValidVertical(input,words[index],r,c)){
					vector<bool> visited(words[index].length(),false);
					setVertical(input,words[index],visited,r,c);
					bool possible = crossword(input,words,index+1);
					if(possible){
						return true;
					}else{
						resetVertical(input,words[index],visited,r,c);
					}
				}
				if(isValidHorizontal(input,words[index],r,c)){
					vector<bool> visited(words[index].length(),false);
					setHorizontal(input,words[index],visited,r,c);
					bool possible = crossword(input,words,index+1);
					if(possible){
						return true;
					}else{
						resetHorizontal(input,words[index],visited,r,c);
					}
				}
			}
		}
	}
	return false;
}
int main(){
// 	+++++++++-
// -++++++++-
// -------++-
// -++++++++-
// -++++++++-
// -++++-----
// ------+++-
// -++++++++-
// +---------
// ++++++++++
// Physics;chemistry;maths;civics;geography;history
    vector<string> input;
    for(int i=0;i<10;i++){
    	string temp="";
    	for(int j=0;j<10;j++){
    		char c;
    		cin>>c;
    		temp += c;
    	}
    	input.pb(temp);
    }
    string word;
    cin>>word;
    vector<string> words;
    string temp = "";
    fo(i,word.length()){
    	if(word[i]==';'){
    		words.pb(temp);
    		temp = "";
    	}else{
    		temp += word[i];
    	}
    }
    words.pb(temp);
 	bool ans = crossword(input,words,0);   
}