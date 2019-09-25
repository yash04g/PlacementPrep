#include<bits/stdc++.h>
using namespace std;
int FindUnique(vector<int> input,int size){
	int Xor = 0;
	for(int i=0;i<size;i++){
		Xor = input[i]^Xor;
	}
	return Xor;
}
int main(){
	vector<int> a;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	cout<<"The unique element is "<<FindUnique(a,n)<<endl;

}