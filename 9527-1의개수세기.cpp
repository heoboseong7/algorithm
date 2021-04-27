#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;

ll sum[54];
ll a, b;

ll calc(ll t)
{
    ll ret = 0, cnt = 0;
    for (ll i = 53; i >= 0; i--)
    {
        ll one = 1ll;
        if (t & (one << i) && t >= (one << i))
        {
            ret += sum[i] + 1ll + cnt * (ll)pow(2ll, i);
            cnt++;
        }
    }
    return ret;
}

int main()
{
    scanf("%lld %lld", &a, &b);
    a--;
    sum[1ll] = 1ll;
    for (ll i = 2ll; i < 54ll; i++)
    {
        sum[i] = sum[i - 1ll] * 2ll + pow(2ll, i - 1ll);
    }

    printf("%lld", calc(b) - calc(a));

    return 0;
}