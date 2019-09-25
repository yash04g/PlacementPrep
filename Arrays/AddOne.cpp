#include<bits/stdc++.h>
using namespace std;
vector<int> AddOne(vector<int> &A){
	if(A.size()==0){
        return A;
    }
    reverse(A.begin(),A.end());
    for(int i=A.size();i>0;i--){
        if(A[A.size()-1]==0){
            A.pop_back();
        }
    }
    reverse(A.begin(),A.end());
    for(int i=A.size();i>0;i--){
        if(A[i-1]==9){
            A[i-1] = 0;
        }
        else{
            A[i-1] += 1;
            break;
        }
    }
    int count = 0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            count++;
        }
    }
    if(count == A.size()){
        A.push_back(1);
        reverse(A.begin(),A.end());
    }
    return A;
}
int main(){
	vector<int> a;
}