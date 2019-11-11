#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define vvll vector<vector<ll> >
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define vpll vector<pair<ll,ll> >
#define fo(i,n) for(ll i=0;i<n;++i)
#define Fo(i,k,n) for(ll i=k;i<n;++i)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define mp make_pair
#define mod 1000000007 
#define pii pair<int,int>
#define pdd pair<double,double>
#define endl "\n"
#define inf 100000000005.0

double dist(pair<ll,ll> S, pair<ll,ll> E){
    double res = pow(S.first-E.first,2)+pow(S.second-E.second,2);
	double distance = sqrt(res);
	return distance;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		pair <ll,ll> start;
		ll x,y;
		cin>>x>>y;
		start = make_pair(x,y);
		ll N,M,K;
		cin>>N>>M>>K;

		vector<pair<ll,ll>> A;
		vector<pair<ll,ll>> B;
		vector<pair<ll,ll>> C;
		fo(j,N){
			pair <ll,ll> point;
			ll x,y;
			cin>>x>>y;
			point = make_pair(x,y);
			A.push_back(point);
		}

		fo(j,M){
			pair <ll,ll> point;
			ll x,y;
            cin>>x>>y;
			point = make_pair(x,y);
			B.push_back(point);
		}

		fo(j,K){
			pair <ll,ll> point;
			ll x,y;
			cin>>x>>y;
			point = make_pair(x,y);
			C.push_back(point);
		}

		vector<double> S_A;
		vector<double> S_B;
		vector<vector<double>> A_B;
		vector<double> A_C;
		vector<double> B_C;
		fo(j,N){
			double distance = dist(start,A[j]);
			S_A.push_back(distance);
		}
		fo(j,M){
			double distance = dist(start,B[j]);
			S_B.push_back(distance);
		}
		fo(j,N){
			vector<double> temp;
			fo(k,M){
				double distance = dist(A[j],B[k]);
				temp.push_back(distance);
			}
			A_B.push_back(temp);
		}
		fo(j,N){
			double min_distance = dist(A[0],C[0]);
			fo(k,K){
				double distance = dist(A[j],C[k]);
				if(distance<min_distance){
					min_distance = distance;
				}
			}
			A_C.push_back(min_distance);
		}
		fo(j,M){
			double min_distance = dist(B[0],C[0]);
			fo(k,K){
				double distance = dist(B[j],C[k]);
				if(distance<min_distance){
					min_distance = distance;
				}
			}
			B_C.push_back(min_distance);
		}
		double dist1 = inf;
        double dist2 = inf;
		fo(j,N){
			fo(k,M){
				double distance = S_A[j] + A_B[j][k] + B_C[k];
				dist1 = min(dist1,distance);
			}
		}
		fo(j,M){
			fo(k,N){
				double distance = S_B[j] + A_B[k][j] + A_C[k];
				dist2 = min(dist2,distance);
			}
		}
        double Finaldist = min(dist1,dist2);
        cout<<fixed;
		cout<<setprecision(11)<<Finaldist<<endl;
	}
	return 0;
}