#include<bits/stdc++.h>
using namespace std;
void replacePi(char input[]){
	if(input[0]=='\0')
		return;
	if(input[0]!='p' || input[1]!='i'){
		return replacePi(input+1);
	}
	else{
		int length = strlen(input);
		int i = length-1;
		for( ;i>1;i--){
			input[i+2] = input[i];
		}
		input[i+2] = '\0';
		input[0] = '3';
		input[1] = '.';
		input[2] = '1';
		input[3] = '4';
		replacePi(input+4);
	}
}
void removeX(char input[]) {
	if(input[0] == '\0')
		return;
	if(input[0]!='x'){
		removeX(input+1);
	}
	else{
		int length = strlen(input);
		for(int i=0;i<length-1;i++){
			input[i] = input[i+1];
		}
		input[length-1] = '\0';
		removeX(input);
	}
}
int stringToNumberHelper(char input[],int length){
	if(length==0)
		return 0;
	int sum = 0;
	int temp = input[0]-'0';
	sum += temp*((int)pow(10,length-1));
	return sum+stringToNumberHelper(input+1,length-1);
}
int stringToNumber(char input[]) {
	int length = strlen(input);
	return stringToNumberHelper(input,length);
}
void pairStar(char input[]){
	if(input[0]=='\0')
		return;
	if(input[1]!=input[0]){
		pairStar(input+1);
	}
	else{
		int length = strlen(input);
		int i = length-1;
		for(;i>0;i--){
			input[i+1] = input[i];
		}
		input[1] = '*';
		input[length+1] = '\0';
		pairStar(input+2);
	}
}
void towerOfHanoi(int n, char source, char auxiliary, char destination){
	if(n<=0)
		return;
	towerOfHanoi(n-1,source,destination,auxiliary);
	cout<<source<<" "<<destination;
	towerOfHanoi(n-1,auxiliary,source,destination);
}
int main(){

}