#include<bits/stdc++.h>
using namespace std;
vector<int> repeatedNumber(vector<int> &A){
	long long sumA = 0;
	long long sumN = 0;
	long long sumAsq = 0;
	long long sumNsq = 0;
	long long n = A.size();
	for(int i=1;i<=n;i++){
		sumN += i;
		sumA += A[i-1];
		sumNsq += (long long)i*(long long)i;
		sumAsq += (long long)A[i-1]*(long long)A[i-1];
	}
	long long a;
	long long b;
	a = 0.5*((sumAsq-sumNsq)/(sumA-sumN) + sumA - sumN);
	b = 0.5*((sumAsq-sumNsq)/(sumA-sumN) - sumA + sumN);
	vector<int> ans;
	ans.push_back(a);
	ans.push_back(b);
	return ans;
}

int main(){
	vector<int> a;
	a.push_back(3);
	a.push_back(1);
	a.push_back(2);
	a.push_back(5);
	a.push_back(3);
	// a.push_back(5);
	vector<int> ans = repeatedNumber(a);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}

}