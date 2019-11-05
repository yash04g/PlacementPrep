#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool possible(ll k,ll n){
    ll sum = 0;
    ll curr = n;
    while(curr>0){
        sum += min(curr,k);
        curr -= k;
        curr -= (curr/10);
    }
    if(2*sum>=n){
        return true;
    }
    return false;
}
ll solve(ll n){
    ll ans = 1;
    ll start = 1;
    ll end = n;
    while(start<=end){
        ll mid = start +(end-start)/2;
        if(possible(mid,n)){
            ans = mid;
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    ll n;
    cin>>n;
    cout<<solve(n)<<endl;
}
