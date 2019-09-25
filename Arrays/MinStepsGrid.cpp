#include<iostream>
#include<vector>
using namespace std;
int MinStepsGrid(vector<int>& A,vector<int>& B){
	if(A.size()<=1 || B.size()<=1){
        return 0;
    }
    int m = B.size();
    int n = A.size();
    int distance = 0;
    for(int i=0;i<m;i++){
        if(i==m-1){
            return distance;
        }
        else{
        distance +=max(abs(A[i+1]-A[i]),abs(B[i+1]-B[i]));
        }
    }
    return distance;
}
int main(){
	int j;
	cin>>j;
	vector<int> A;
	for(int k=0;k<j;k++){
		int input;
		cin>>input;
		A.push_back(input);
	}
	int i;
	cin>>i;
	vector<int> B;
	for(int k=0;k<i;k++){
		int input;
		cin>>input;
		B.push_back(input);
	}
	cout<<MinStepsGrid(A,B)<<endl;

}