#include <bits/stdc++.h>

using namespace std;

string a, b;
int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> a;
    cin >> b;

    int n = a.length();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << dp[n][n] << '\n';
    return 0;
}