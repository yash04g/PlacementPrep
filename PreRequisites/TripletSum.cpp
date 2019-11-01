#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
void FindTriplet(int arr[], int size, int x){
	vvi ans;
	sort(arr,arr+size);
	fo(i,size-2){
		if(x-arr[i]>0){
			vi row;
			row.pb(i);
			int j=i+1;
			int k=size-1;
			bool flag = false;
			while(j<k){
				int sum = x-arr[i];
				if(arr[j]+arr[k]==sum){
					row.pb(arr[j]);
					row.pb(arr[k]);
					j++;
					k--;
				}
				else if(arr[j]+arr[k]<sum){
					j++;
				}
				else{
					k--;
				}
			}
			if(row.size()>1){
				int numrows = (row.size()-1)/2;
				fo(k,numrows){
					vi row1;
					row1.pb(arr[i]);
					row1.pb(row[numrows+1]);
					row1.pb(row[numrows+2]);
					ans.pb(row1);
				}
			}
			else{
				row.clear();
			}
		}
		else{
			break;
		}
	}
	int numrows = ans.size();
	int col = 3;
	for(int i=0;i<numrows;i++){
		for(int j=0;j<col;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
    int t;
    cin >> t;
    while (t--){

    }
}