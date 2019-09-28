#include<bits/stdc++.h>
using namespace std;
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