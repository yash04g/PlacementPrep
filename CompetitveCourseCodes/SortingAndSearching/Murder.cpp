#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
#define mp make_pair
ll merge(vi &arr,int l,int mid,int r){
    int i = l;
    int j = mid;
    vi temp(r-l+1);
    ll count = 0;
    int k = 0;
    while(i<mid && j<=r){
        if(arr[i]<arr[j]){
            count += (r-j+1)*arr[i];
            temp[k++] = arr[i++];
            // i++;
        }
        else{
            temp[k++] = arr[j++];
            // j++;
        }
    }
    while(i<mid){
        temp[k++] = arr[i++];
    }
    while(j<=r){
        temp[k++] = arr[j++];
    }
    for(int i=l,k=0;i<=r;i++,k++){
        arr[i] = temp[k];
    }
    return count;
    
}
ll merge_sort(vi &arr,int l,int r){
    ll ans = 0;
    if(r>l){
        int mid = (r+l)/2;
        ll lcount = merge_sort(arr,l,mid);
        ll rcount = merge_sort(arr,mid+1,r);
        ll mcount = merge(arr,l,mid+1,r);
        return lcount+rcount+mcount;
    }
    return ans;
}
ll staircase(vi &arr,int n){
    return merge_sort(arr,0,n-1);
}
int main(){
    int t;
    cin >> t;
    while (t--){
    	int n;
    	cin>>n;
    	vi contribution(n);
    	fo(i,n)
    		cin>>contribution[i];
    	cout<<staircase(contribution,n)<<endl;
    }
}