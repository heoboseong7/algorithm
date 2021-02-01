#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

vector<ll> p;

int main()
{
    ll n, k;
    vector<ll> v;
    v.push_back(0);
    cin >> n >> k;
    p.push_back(1);
    for (int i = 1; i < 10; i++)
    {
        p.push_back(p[i - 1] * 10);
    }
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(v.back() + p[i] * 9 * (i + 1));
        if (v.back() > 1000000000)
            break;
    }

    for (int i = 1; i < v.size(); i++)
    {
        if (k > v[i - 1] && k <= v[i])
        {
            ll origin = ((k - v[i - 1] - 1) / i) + p[i - 1];
            ll idx = (k - v[i - 1] - 1) % i;
            if (origin > n)
            {
                cout << -1;
                return 0;
            }
            else
            {
                cout << (origin / p[i - idx - 1]) % 10;
                return 0;
            }
        }
    }
    return 0;
}