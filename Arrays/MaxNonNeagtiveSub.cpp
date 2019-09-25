#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int> maxSet(vector<int> &a){
	long long int currentSum = 0;
    long long int maxSum = INT_MIN;
    long long int si = 0;
    long long int ei = -1;
    long long int n = a.size();
    long long int length = 0;
    long long int ansLength = 0;
    long long int ansStart = 0;
    long long int ansEnd = -1;
    long long int i=0;
    while(i<n){
        if(a[i]>=0){
            si = i;
            currentSum = 0;
            length = 0;
            while(a[i]>=0 && i<n){
                currentSum+=a[i];
                ++i;
            }
            ei = i-1;
        }
        if((currentSum>maxSum)|| (currentSum==maxSum && ei-si+1 < ansLength)){
            ansStart = si;
            ansEnd = ei;
            ansLength = si+ei-1;
            maxSum = currentSum;
        }
        ++i;
    }
    vector<int> ans;
    for(long long int j=ansStart;j<=ansEnd;j++){
        ans.push_back(a[j]);
    }
    return ans;
}
int main(){

}