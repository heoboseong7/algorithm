#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int dp[1002][1002];
int tmp[2][1002];
int val[1002][1002];
int n, m;

int main()
{
    fill(dp[0], &dp[1002][1003], -INF);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &val[i][j]);
        }
    }
    dp[1][1] = val[1][1];
    for (int i = 2; i <= m; i++)
        dp[1][i] = dp[1][i - 1] + val[1][i];

    for (int i = 2; i <= n; i++)
    {
        tmp[0][1] = dp[i - 1][1] + val[i][1];
        for (int j = 2; j <= m; j++)
        {
            tmp[0][j] = max(tmp[0][j - 1], dp[i - 1][j]) + val[i][j];
        }
        tmp[1][m] = dp[i - 1][m] + val[i][m];
        for (int j = m - 1; j > 0; j--)
        {
            tmp[1][j] = max(tmp[1][j + 1], dp[i - 1][j]) + val[i][j];
        }
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(tmp[0][j], tmp[1][j]);
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}