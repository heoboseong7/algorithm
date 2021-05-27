#include <bits/stdc++.h>

using namespace std;

int n, m;
bool dp[31][15001];
int w[30];

void solve(int i, int sum)
{
    if (i > n || dp[i][sum])
        return;
    if (i > -1)
        dp[i][sum] = true;
    solve(i + 1, sum + w[i]);
    solve(i + 1, abs(sum - w[i]));
    solve(i + 1, sum);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", w + i);
    }
    solve(0, 0);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int b;
        scanf("%d", &b);
        if (dp[n][b])
            printf("Y ");
        else
            printf("N ");
    }

    return 0;
}