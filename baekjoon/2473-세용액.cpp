#include <bits/stdc++.h>
#define MAX 4000000000

typedef long long int ll;
using namespace std;

vector<ll> values;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        values.push_back(a);
    }
    sort(values.begin(), values.end());

    ll ans[3];
    ll minSum = MAX;
    for (int i = 0; i < n - 2; i++)
    {
        int start = i + 1;
        int end = n - 1;
        ll sum = MAX;
        while (start < end)
        {
            sum = values[i] + values[start] + values[end];
            if (abs(sum) < abs(minSum))
            {
                minSum = sum;
                ans[0] = values[i];
                ans[1] = values[start];
                ans[2] = values[end];
            }

            if (sum > 0)
            {
                end--;
            }
            else if (sum < 0)
            {
                start++;
            }
            else
            {
                cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
                return 0;
            }
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    return 0;
}