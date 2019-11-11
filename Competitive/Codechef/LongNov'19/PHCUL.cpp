#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sb __builtin_popcount
#define MOD (ll)1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, y;
        cin >> x >> y;
        ll n, m, k;
        cin >> n >> m >> k;
        vector<pair<pair<ll, ll>, pair<double, double>>> a;
        vector<pair<pair<ll, ll>, pair<double, double>>> b;
        vector<pair<ll, ll>> c;
        for (ll i = 0; i < n; i++)
        {
            ll ta, tb;
            cin >> ta >> tb;
            a.push_back({{ta, tb}, {-1, -1}});
        }
        for (ll i = 0; i < m; i++)
        {
            ll ta, tb;
            cin >> ta >> tb;
            b.push_back({{ta, tb}, {-1, -1}});
        }
        for (ll i = 0; i < k; i++)
        {
            ll ta, tb;
            cin >> ta >> tb;
            c.push_back({ta, tb});
        }
        for (ll i = 0; i < m; i++)
        {
            ll mini = LONG_LONG_MAX;
            for (ll j = 0; j < k; j++)
            {
                ll dis = (c[j].first - b[i].first.first) * (c[j].first - b[i].first.first) + (c[j].second - b[i].first.second) * (c[j].second - b[i].first.second);
                mini = min(mini, dis);
            }
            b[i].second.first = sqrt(mini);
        }
        for (ll i = 0; i < n; i++)
        {
            ll mini = LONG_LONG_MAX;
            ll ind = -1;
            for (ll j = 0; j < k; j++)
            {
                ll dis = (c[j].first - a[i].first.first) * (c[j].first - a[i].first.first) + (c[j].second - a[i].first.second) * (c[j].second - a[i].first.second);
                mini = min(mini, dis);
            }
            a[i].second.first = sqrt(mini);
        }
        for (ll i = 0; i < n; i++)
        {
            double mini = 10.0e18;
            ll ind = -1;
            for (ll j = 0; j < m; j++)
            {
                double dc = b[j].second.first;
                ll dis = (a[i].first.first - b[j].first.first) * (a[i].first.first - b[j].first.first) + (a[i].first.second - b[j].first.second) * (a[i].first.second - b[j].first.second);
                double td = sqrt(dis) + dc;
                mini = min(mini, td);
            }
            a[i].second.second = mini;
        }
        for (ll i = 0; i < m; i++)
        {
            double mini = 10.0e18;
            ll ind = -1;
            for (ll j = 0; j < n; j++)
            {
                double dc = a[j].second.first;
                ll dis = (a[j].first.first - b[i].first.first) * (a[j].first.first - b[i].first.first) + (a[j].first.second - b[i].first.second) * (a[j].first.second - b[i].first.second);
                double td = sqrt(dis) + dc;
                mini = min(mini, td);
            }
            b[i].second.second = mini;
        }
        double ans = 10.0e18;
        for (ll i = 0; i < n; i++)
        {
            ll dis = (a[i].first.first - x) * (a[i].first.first - x) + (a[i].first.second - y) * (a[i].first.second - y);
            double td = sqrt(dis) + a[i].second.second;
            ans = min(ans, td);
        }
        for (ll i = 0; i < m; i++)
        {
            ll dis = (b[i].first.first - x) * (b[i].first.first - x) + (b[i].first.second - y) * (b[i].first.second - y);
            double td = sqrt(dis) + b[i].second.second;
            ans = min(ans, td);
        }
        cout << std::fixed << setprecision(10) << ans << endl;
    }
}