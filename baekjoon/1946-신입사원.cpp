#include <bits/stdc++.h>

using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        vector<pair<int, int>> v;
        int n;
        int a, b;

        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            v.push_back(make_pair(a, b));
        }
        sort(v.begin(), v.end());
        int ans = 1;
        int cmp = v[0].second;
        for (int i = 1; i < n; i++)
        {
            if (cmp > v[i].second)
            {
                ans++;
                cmp = v[i].second;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}