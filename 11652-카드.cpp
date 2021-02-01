#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long int ll;
typedef vector<ll> vll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vll v;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        v.pb(a);
    }
    sort(v.begin(), v.end());
    pair<int, int> ans, temp;
    ans.first = 0;
    ans.second = 0;
    temp.first = 0;
    temp.second = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[temp.first] == v[i])
        {
            temp.second++;
        }
        else
        {
            ans = ans.second < temp.second ? temp : ans;
            temp.first = i;
            temp.second = 1;
        }
        if (i + 1 == n)
        {
            ans = ans.second < temp.second ? temp : ans;
            temp.first = i;
            temp.second = 1;
        }
    }
    cout << v[ans.first];
    return 0;
}
