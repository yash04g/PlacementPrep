#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vvi vector<vector<int>>
#define pb push_back
#define vi vector<int>
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1000000001
int main(){
	freopen("bendin.txt","r",stdin);
	freopen("bendout.txt","w",stdout);
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	int x3,y3,x4,y4;
	cin>>x3>>y3>>x4>>y4;
	int total_area = 0;
	int a1 = abs((x2-x1)*(y2-y1));
	int a2 = abs((x4-x3)*(y4-y3));
	int li = max(x1,x3);
	int ri = min(x2,x4);
	int ti = min(y2,y4);
	int bi = max(y1,y3);
	int inter_a = 0;
	if(li<=ri && bi<=ti){
		inter_a = abs((ri-li)*(ti-bi));
	}
	total_area = a1+a2-inter_a;
	cout<<total_area<<endl;
}