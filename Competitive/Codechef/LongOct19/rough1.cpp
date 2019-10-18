#include<bits/stdc++.h>
#include<math.h>
using namespace std;

void number(int N, vector <string> Y, vector <int> B){
	/*if(N>=35){
		vector<string> X = Y;
		sort(X.begin(),X.end());
		int count = distance(X.begin(),unique(X.begin(), X.end()));
		if(count>35){
			cout<<"-1 \n";
			return;
		}
	}*/

	long long int val=-1;
	for(int i=0; i<N; i++){
		if(B[i]!= -1){
			long long int val_=0;
			int s=Y[i].length();
			for(int j=s-1; j>=0; j--){
				long long int y;
				if(Y[i][j]>=48 && Y[i][j]<=57)
					y=Y[i][j]-48;
				else if(Y[i][j]>=65 && Y[i][j]<=90)
					y=Y[i][j]-55;
				val_+=y*pow(B[i],s-1-j); 
			}
			if(val!=-1){
				if(val!=val_){
					cout<<"-1 \n";
					return;
				}
			}
			val=val_;
		}
	}
	int limit;	
	if(val>=36)
		limit=36;
	else
		limit=val+1;
	vector< pair <int,string> > vect;
	for(int i=2;i<=limit;i++){
		pair<int,string> g;
		g.first=i;
		string str;
		long long int num = val;
		while(num>=1){
			long long int a;
			a=num%i;
			if(a>=0 && a<=9)
				a=a+48;
			else
				a=a+55;
			str.push_back(a);
			num=num/i;
		}
		reverse(str.begin(), str.end());
		g.second=str;
		vect.push_back(g);
	}

	/*for(int i=0;i<=limit-2;i++){
		cout<<vect[i].first<<" "<<vect[i].second<<"\n";
	}*/

	for(int i=0;i<N;i++){
		if(B[i]== -1){
			for(int j=0;j<=limit-2;j++){
				if(Y[i].compare(vect[j].second)==0){
					B[i]=vect[j].first;
					break;
				}
			}
		}
		if(B[i]== -1){
			cout<<"-1 \n";
			return;
		}
	}
	if(val>1e12){
		val = -1;
	}
	cout<<val<<"\n";
}
int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int N;
		cin>>N;
		vector <string> Y(N);
		vector <int> B(N);
		for(int j=0; j<N; j++){
			cin>>B[j]>>Y[j];
		}
		number(N,Y,B);
	}
}