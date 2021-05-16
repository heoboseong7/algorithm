#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> x(n, 0);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    sort(x.begin(), x.end());
    int l = 1, r = x[n - 1] - x[0];
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int prev = 0;
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (mid <= x[i] - x[prev])
            {
                cnt++;
                prev = i;
            }
        }
        if (cnt >= c)
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans;

    return 0;
}