#include <bits/stdc++.h>

using namespace std;

int m, n;
int h[501][501];
int dp[501][501];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int solve(int x, int y)
{
    if (x == n && y == m)
        return 1;
    if (dp[x][y] > -1)
        return dp[x][y];

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (h[xx][yy] < h[x][y])
            dp[x][y] += solve(xx, yy);
    }

    return dp[x][y];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &h[i][j]);
            dp[i][j] = -1;
        }

    printf("%d", solve(1, 1));
    return 0;
}