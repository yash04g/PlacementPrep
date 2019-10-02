#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
ll merge(int* arr,int left,int mid,int right){
	int i=left,j=mid,k=0;
	int cnt = 0;
	int temp[right-left+1];
	while(i<mid && j<=right){
		if(arr[i]<=arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
			cnt += mid-i;
		}
	}
	while(i<mid){
		temp[k++] = arr[i++];
	}
	while(j<=right){
		temp[k++] = arr[j++];
	}
	for(int i=left,k=0;i<=right;i++,k++){
		arr[i] = temp[k];
	}
	return cnt;
}
ll merge_sort(int *arr,int left,int right){
	ll count = 0;
	if(left<right){
		int mid = (left+right)/2;
		ll lcount = merge_sort(arr,left,mid);
		ll rcount = merge_sort(arr,mid+1,right);
		ll mergecount = merge(arr,left,mid+1,right);
		return lcount+rcount+mergecount;
	}
	return count;
}
ll solve(int A[],int n){
	ll ans = merge_sort(A,0,n-1);
	return ans;
}
int main(){
    int t;
    cin >> t;
    while (t--){

    }
}