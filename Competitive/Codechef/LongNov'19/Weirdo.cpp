#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sb __builtin_popcount
#define MOD (ll)1000000007

bool isVowel(char a)
{
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
    {
        return true;
    }
    return false;
}
bool solve(string s){
    bool flag = false;
    for(ll i=0;i<s.size();++i){
        // cout<<s[i]<<endl;
        if(!isVowel(s[i]) && (i<s.size()-2)){
            if(isVowel(s[i+1]) && isVowel(s[i+2])){
                flag = true;
            }else{
                // cout<<s[i]<<endl;
                return false;
            }
        }
        if(!isVowel(s[i]) && (i==s.size()-2)){
            if(isVowel(s[i+1])){
                return true;
            }else{
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll l;
        cin >> l;
        vector<string> a;
        vector<string> b;
        for(ll i=0;i<l;++i){
            string temp;
            cin>>temp;
            bool flag = solve(temp);
            if(flag){
                a.pb(temp);
            }else{
                b.pb(temp);
            }
        }
        if (a.size() == 0)
        {
            cout << 0.0 << endl;
            continue;
        }
        if (b.size() == 0)
        {
            cout << "Infinity" << endl;
            continue;
        }
        ll tc[26];
        ll c[26];
        memset(tc, 0, sizeof(tc));
        memset(c, 0, sizeof(c));
        for (auto i : b)
        {
            set<char> st;
            for (auto j : i)
            {
                tc[j - 'a']++;
                st.insert(j);
            }
            for (auto j : st)
            {
                c[j - 'a']++;
            }
        }
        double ans = 0;
        for (ll i = 0; i < 26; i++)
        {
            if (tc[i])
            {
                ans += (-log10(c[i])) + (double)b.size() * (log10(tc[i]));
            }
        }
        memset(tc, 0, sizeof(tc));
        memset(c, 0, sizeof(c));
        for (auto i : a)
        {
            set<char> st;
            for (auto j : i)
            {
                tc[j - 'a']++;
                st.insert(j);
            }
            for (auto j : st)
            {
                c[j - 'a']++;
            }
        }
        for (ll i = 0; i < 26; i++)
        {
            if (tc[i])
            {
                ans += log10(c[i]) - (double)a.size() * (log10(tc[i]));
            }
        }
        if (ans > 7)
        {
            cout << "Infinity" << endl;
        }
        else
        {
            cout << fixed;
            cout << setprecision(10) << pow(10.00, ans) << endl;
        }
    }
}