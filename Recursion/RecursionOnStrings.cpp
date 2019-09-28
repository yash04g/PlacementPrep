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
void replaceCharacter(char input[], char c1, char c2) {
	if(input[0]=='\0')
		return;
	if(input[0]!=c1){
		replaceCharacter(input+1,c1,c2);
	}
	else{
		int length = strlen(input);
		for(int i=0;i<length;i++){
			input[0] = c2;
		}
		replaceCharacter(input+1,c1,c2);
	}
}
void removeConsecutiveDuplicates(char *input) {
 if(input[0]=='\0')
      return;
 	if(input[0]!=input[1])
    	removeConsecutiveDuplicates(input+1);
  	else{
    int i=1;
    for( ;input[i]!='\0';i++){
      input[i-1]=input[i];
    }
    input[i-1]=input[i];
    removeConsecutiveDuplicates(input);
  }
}
int subsequences(string input,string* output){
	if(input.empty()){
		output[0] = "";
		return 1;
	}
	string smallString = input.substr(1);
	int smallStringSize = subsequences(smallString,output);
	for(int i=0;i<smallStringSize;i++){
		output[i+smallStringSize] = input[0]+output[i];
	}
	return 2*smallStringSize;
}
string getOptions(int n){
	if(n==2){
		return "abc";
	}
	if(n==3){
		return "def";
	}
	if(n==4){
		return "ghi";
	}
	if(n==5){
		return "jkl";
	}
	if(n==6){
		return "mno";
	}
	if(n==7){
		return "pqrs";
	}
	if(n==8){
		return "tuv";
	}
	if(n==9){
		return "wxyz";
	}
	return " ";
}
// Returns the count of the output size and all the changes are reflected int the output array thus using for loop print it
int keypadApproach(int n,string* output){
	if(n<=1){
		output[0] = "";
		return 1;
	}
	int lastDigit = n%10;
	int smallOutputSize = keypadApproach(n/10,output);
	string options = getOptions(lastDigit);
	for(int i=0;i<options.length()-1;i++){
		for(int j=0;j<smallOutputSize;j++){
			output[j+(i+1)*smallOutputSize] = output[j];
		}
	}
	int k=0;
	for(int i=0;i<options.size();i++){
		for(int j=0;j<smallOutputSize;j++){
			output[k] += options[i];
			k++;
		}
	}
	return smallOutputSize*options.size();
}
//This prints all the subsequences
void print_SubsequencesHelper(string input,string output){
	if(input.size()==0){
		cout<<output<<endl;
		return;
	}
	print_SubsequencesHelper(input.substr(1),output);
	print_SubsequencesHelper(input.substr(1),output+input[0]);
}
void print_Subsequences(string input){
	return print_SubsequencesHelper(input,"");
}
// prints the keypad approach directly
void printKeypadHelper(int n,string output){
	if(n==0){
		cout<<output<<endl;
		return;
	}
	string options = getOptions(n%10);
	for(int i=0;i<options.size();i++){
		printKeypadHelper(n/10,options[i]+output);
	}
}
void printKeypad(int num){
	return printKeypadHelper(num,"");
}
int main(){
	string input;
	cin>>input;
	string* output = new string[(int)pow(2,input.size())];
	int count = subsequences(input,output);
	for(int i=0;i<count;i++){
		cout<<output[i]<<endl;
	}
}