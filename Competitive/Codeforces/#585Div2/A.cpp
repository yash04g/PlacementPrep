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
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double>

int main(){
    int a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;
    int maxima = 0;
    int minima = a1+a2;
    int n1 = n;
    int n2 = n;
    if(n==(a1*k1+a2*k2)){
    	maxima = a1+a2;
    	minima = a1+a2;
    }else{
    	if(k1>k2){
    		int count1 = n/k2;
    		if(count1>=a2){
    			maxima = a2;
    		}else{
    			maxima = count1;
    		}
    		n1 -= k2*a2;
    		if(n1>0){
	    		int count2 = n1/k1;
	    		if(count2>=a1){
	    			maxima += a1;
	    		}else{
	    			maxima += count2;
	    		}
    		}
    	}else{
    		int count1 = n/k1;
    		if(count1>=a1){
    			maxima = a1;
    		}else{
    			maxima = count1;
    		}
    		n1 -= k1*a1;
    		if(n1>0){
	    		int count2 = n1/k2;
	    		if(count2>=a2){
	    			maxima += a2;
	    		}else{
	    			maxima += count2;
	    		}
    		}
    	}
    	//Minima
    	n2 = n2-((k1-1)*a1+(k2-1)*a2);
    	if(n2<=0){
    		minima = 0;
    	}else{
    		minima = n2;
    	}
    }

    cout<<minima<<" "<<maxima<<endl;
}