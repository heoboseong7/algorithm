#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        int t = i;
        while (t > 0)
        {
            int mt = t % 10;
            if (mt % 3 == 0 && mt > 0)
            {
                ans++;
            }
            t /= 10;
        }
    }
    cout << ans;

    return 0;
}