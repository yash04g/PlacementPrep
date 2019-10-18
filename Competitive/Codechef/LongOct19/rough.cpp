#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define ll long long int
#define vvi vector<vector<int> >
#define pb push_back
#define popb pop_back
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<int,int> >
#define fo(i,n) for(int i=0;i<n;i++)
#define Fo(i,k,n) for(int i=k;i<n;i++)
#define deb(x) cout<<#x<<" "<<x<<endl;
#define inf 1e12
#define mp make_pair
#define mod 1000000007
#define pii pair<int,int>
#define pdd pair<double,double
#define endl "\n"

ll getVal(char a){
    if(a=='A'){
        return 10;
    }
    ll num = 10+(a-'A');
    return num;
}
ll power(int a,int b){
    ll ans = 1;
    for(int i=1;i<=b;i++){
        ans *= a;
    }   
    return ans;
}
ll calculate(string a,int b){
    ll ans = 0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='0' || a[i]=='1' || a[i]=='2' || a[i]=='3' || a[i]=='4' || a[i]=='5' || a[i]=='6' || a[i]=='7' || a[i]=='8' || a[i]=='9'){
            ll num = a[i]-'0';
            ans += num*power(b,a.size()-1-i);
        }else{
            ll num = getVal(a[i]);
            ans += num*power(b,a.size()-1-i);
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        string *str = new string[n];
        bool flag = false;
        ll ans = -1;
        bool flag2 = false;
        fo(i,n){
            int b;
            string y;
            cin>>b>>y;
            if(b!=-1){
                ans = calculate(y,b);
                flag = true;
            }
            str[i] = y;
        }
        if(n==1 && !flag && (str[0]=="0" || str[0]=="1")){
            if(str[0]=="0"){
                cout<<0<<endl;
            }else{
                cout<<1<<endl;
            }
        }
        else if(flag && n==1){
            if(ans>1e12)
                ans = -1;
            cout<<ans<<endl;
        }else{
            ll res[n][38];
            for(int i=0;i<n;i++){
                string a = str[i];
                for(int j=2;j<37;j++){
                    if(a.size()==1){
                        res[i][2] = calculate(a,j);
                        for(int j=3;j<37;j++){
                            res[i][j] = -1;
                        }
                        break;
                    }
                    else
                        res[i][j] = calculate(a,j);
                }
            }
            ll output = -1;
            map<ll,int> m;
            for(int j=2;j<37;j++){
                for(int i=0;i<n;i++){
                    if(res[i][j]!=-1)
                        m[res[i][j]]++;
                }
            }
            map<ll,int> :: iterator it;
            vector<int> res1;
            bool flag1 = false;
            for(it = m.begin();it!=m.end();it++){
                if(it->second==n){
                    res1.push_back(it->first);
                    flag1 = true;
                }
            }
            sort(res1.begin(),res1.end());
            if(flag1){
                output = res1[0];
            }
            if(output>(1e12)){
                output = -1;
            }
            cout<<output<<endl;
        }
    }
}