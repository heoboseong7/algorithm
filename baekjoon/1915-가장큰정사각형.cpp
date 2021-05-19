#include <bits/stdc++.h>

using namespace std;

int dp[1002][1002];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%1d", &dp[i][j]);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dp[i][j] != 0)
            {
                int size = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                dp[i][j] = size + 1;
                ans = max(dp[i][j], ans);
            }
        }
    }
    printf("%d\n", ans * ans);
    return 0;
}