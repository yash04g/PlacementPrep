#include<bits/stdc++.h>
using namespace std;
int multiplyNumbers(int m, int n) {
	if(n==0){
		return 0;
	}
	return m+multiplyNumbers(m,n-1);
}

int countZeros(int n) {
	if(n>0){
 		if(n%10==0){
    		return countZeros(n/10)+1;
  	}
  		return countZeros(n/10);
	}
	return 0;
}
double geometricSum(int k) {
	if(k==0){
		return 1;
	}
	double ans = 1;
	return 1+geometricSum(k-1)/2;
}
bool checkPalindromeHelper(char* input,int be,int end){
	if(be>=end){
		return true;
	}
	if(input[be] != input[end]){
		return false;
	}
	else{
		return checkPalindromeHelper(input,be+1,end-1);
    }
}
bool checkPalindrome(char input[]){
	int length = strlen(input);
	int be = 0;
	int end = length-1;
	return checkPalindromeHelper(input,be,end);
}
int sumOfDigits(int n){
	if(n==0)
		return 0;
	return n%10 + sumOfDigits(n/10);
}



int main(){

}