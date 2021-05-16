#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll n, m;
vector<ll> h;
ll ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    h = vector<ll>(n, 0);
    ll l = 0, r = 0, mid;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        r = max(r, h[i]);
    }

    while (l <= r)
    {
        mid = (l + r) / 2;
        ll t = 0;
        for (int i = 0; i < n; i++)
        {
            t += h[i] > mid ? h[i] - mid : 0;
        }
        if (t >= m)
        {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}