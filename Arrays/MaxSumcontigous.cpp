#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int> &A){
	int Max_Sum = INT_MIN;
	int current_Sum = 0;
	for(int i=0;i<A.size();i++){
		current_Sum+= A[i];
		if(Max_Sum<current_Sum){
			Max_Sum = current_Sum;
		}
		if(current_Sum<0){
			current_Sum = 0;
		}
	}
	return Max_Sum;
}