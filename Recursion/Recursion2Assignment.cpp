#include<bits/stdc++.h>
using namespace std;
bool checkABHelper(char *input,int startIndex){
	if(input[startIndex]=='\0')
		return true;
	if(input[startIndex]!='a')
		return false;
	if(input[startIndex+1]!='\0' && input[startIndex+2]!='\0'){
		if(input[startIndex+1] == 'b' && input[startIndex+2]=='b'){
			return checkABHelper(input,startIndex+3);
		}
	}
	return checkABHelper(input,startIndex+1);
}
bool checkAB(char *input){
	if(input[0]=='\0')
		return false;
	bool ans = checkABHelper(input,0);
	return ans;
}
int staircase(int n){
	if(n<=1)
		return 1;
	if(n==2)
		return 2;
	return staircase(n-1)+staircase(n-2)+staircase(n-3); 
}
int subsetHelper(int input[], int n,int startIndex, int output[][20]){
	if(startIndex==n){
		output[0][0] = 0;
		return 1;
	}
	int smallOutputSize = subsetHelper(input,n,startIndex+1,output);
	for(int i=0;i<smallOutputSize;i++){
		output[i+smallOutputSize][0] = output[i][0]+1;
		output[i+smallOutputSize][1] = input[startIndex];
		for(int j=1;j<=output[i][0];j++){
			output[i+smallOutputSize][j+1] = output[i][j];
		}
	}
	return 2*smallOutputSize;
}
int subset(int input[], int n, int output[][20]) {
	return subsetHelper(input,n,0,output);
}
void printSubsetsOfArray(int *input,int n,int *output,int m){
	if(n==0){
		for(int i=0;i<m;i++){
			cout<<output[i]<<" ";
		}
		cout<<endl;
		return;
	}
	int newOutput[m+1];
	for(int i=0;i<m;i++){
		newOutput[i] = output[i];
	}
	newOutput[m] = input[0];
	printSubsetsOfArray(input+1,n-1,newOutput,m+1);
	printSubsetsOfArray(input+1,n-1,output,m);

}
void printSubsetsOfArray(int input[], int size) {
	int output[1000];
	printSubsetsOfArray(input,size,output,0);    
}
int subsetSumToKHelper(int input[], int n, int output[][50], int k,int startIndex){
	if(startIndex==n){
		if(k==0){
			output[0][0] = 0;
			return 1;
		}
		else{
			return 0;
		}
	}
	int smallOutput1[1000][50];
	int smallOutput2[1000][50];
	int size1 = subsetSumToKHelper(input,n,smallOutput1,k-input[startIndex],startIndex+1);
	int size2 = subsetSumToKHelper(input,n,smallOutput2,k,startIndex+1);
	int row = 0;
	for(int i=0;i<size1;i++){
		output[row][0] = smallOutput1[i][0]+1;
		output[row][1] = input[startIndex];
		for(int j=1;j<=smallOutput1[i][0];j++){
			output[row][j+1] = smallOutput1[i][j];
		} 
		row++;
	}
	for(int i=0;i<size2;i++){
		for(int j=0;j<=smallOutput2[i][0];j++){
			output[row][j] = smallOutput2[i][j];
		}
		row++;
	}
	return row;
}
int subsetSumToK(int input[], int n, int output[][50], int k){
	return subsetSumToKHelper(input,n,output,k,0);
}
void printSubsetSumToKHelper(int input[], int n, int k,int *output,int m){
	if(n==0){
		if(k==0){
			for(int i=0;i<m;i++){
				cout<<output[i]<<" ";
			}
			cout<<endl;
			return;
		}
		else{
			return;
		}
	}
	int newOutput[m+1];
	for(int i=0;i<m;i++){
		newOutput[i] = output[i];
	}
	newOutput[m] = input[0];
	printSubsetSumToKHelper(input+1,n-1,k-input[0],newOutput,m+1);
	printSubsetSumToKHelper(input+1,n-1,k,output,m);

}
void printSubsetSumToK(int input[], int size, int k) {
    int output[1000];
    printSubsetSumToKHelper(input,size,k,output,0);
}

char getOptions(int n){
	if(n==0){
		return '\0';
	}
	int sum = n-1;
	return 'a'+sum; 
}
int stringToInt(string input){
	int sum = 0;
	for(int i=0;i<input.size();i++){
		int temp = input[i] - '0';
		sum += temp*((int)pow(10,input.size()-1-i));
	}	
	return sum;
}
int stringToIntAlternate(string input){
	stringstream geek(input);
	int x = 0;
	geek>>x;
	return x;
}
int getCodes(string input, string output[10000]){
	if(input.empty()){
		output[0] = "";
		return 1;
	}
	string smallOutput1[1000];
	string smallOutput2[1000];
	int size1 = getCodes(input.substr(1),smallOutput1);
	int size2 = 0;
	int num = 0;
	if(input[1]!='\0'){
		string num1 = input.substr(0,2);
		num = stringToInt(num1);
		if(num>=10 && num<=26){
			size2 = getCodes(input.substr(2),smallOutput2);
		}
	}
	int k=0;
	for(int i=0;i<size1;i++){
		output[k] = getOptions(input[0]-'0')+smallOutput1[i];
		k++;
	}
	for(int i=0;i<size2;i++){
		output[k] = getOptions(num)+smallOutput2[i];
		k++;
	}
	return k;
}
string getString(char x){
	string s(1,x);
	return s;
}
void printAllPossibleCodesHelper(string input,string output){
	if(input.empty()){
		cout<<output<<endl;
		return;
	}
	int num2 = input[0]-'0';
	string smallOutput1 = getString(getOptions(num2));
	printAllPossibleCodesHelper(input.substr(1),output+smallOutput1);
	string num1 = input.substr(0,2);
	int num = stringToInt(num1);
	if(num>=10 && num<=26){
		string smallOutput2 = getString(getOptions(num));
		printAllPossibleCodesHelper(input.substr(2),output+smallOutput2);
	}
}
void printAllPossibleCodes(string input){
	printAllPossibleCodesHelper(input,"");
}
// int returnPermutations(string input, string output[]){
// 	if(input.empty()){
// 		output[0] = "";
// 		return 1;
// 	}
// 	string smallOutput[1000];
// 	int smallOutputSize = returnPermutations(input.substr(1),smallOutput);
// 	int k=0;
// 	for(int i=0;i<smallOutputSize;i++){
// 		for(int j=0;j<input.size();j++){
// 			output[k] ;
// 			k++;
// 		}
// 	}
// 	return k;
// }
void printPermutationsHelper(string input,string output){
	if(input.empty()){
		cout<<output<<endl;
		return;
	}
	for(int i=0;i<input.size();i++){
		printPermutationsHelper(input.substr(0,i)+input.substr(i+1),output+input[i]);
	}
}
void printPermutations(string input){
	printPermutationsHelper(input,"");
}


int main(){
}