#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
bool HotelBookingPossible(vector<int> &arrive,vector<int> &depart,int k){
	vector<pair<int,int> > ans;
	int n = arrive.size();
	for(int i=0;i<n;i++){
		ans.push_back(make_pair(arrive[i],1));
		ans.push_back(make_pair(depart[i],0));
	}
	sort(ans.begin(),ans.end());
	int current_booking = 0;
	int max_booking = 0;
	for(int i=0;i<ans.size();i++){
		if(ans[i].second==1){
			current_booking++;
			max_booking = max(max_booking,current_booking);
		}
		else{
			current_booking--;
		}
	}
	return k>=max_booking;
}
int main(){
	vector<int> arrive;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		arrive.push_back(temp);
	}
	vector<int> depart;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		depart.push_back(temp);
	}
	int k;
	cin>>k;	
	cout<<HotelBookingPossible(arrive,depart,k)<<endl;
}