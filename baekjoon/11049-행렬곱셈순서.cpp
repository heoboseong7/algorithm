#include <bits/stdc++.h>

using namespace std;

int dp[501][501];
int check[501][501];
int r[501];
int c[501];
int n;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r[i] >> c[i];
    }
    // 길이
    for (int i = 1; i < n; i++)
    {
        // 현재 시작 지점
        for (int j = 0; i + j < n; j++)
        {
            int e = j + i;
            for (int k = 0; k < i; k++)
            {
                if (dp[j][e] != 0)
                    dp[j][e] = min(dp[j][e], dp[j][j + k] + dp[j + k + 1][e] + r[j] * c[j + k] * c[e]);
                else
                    dp[j][e] = dp[j][j + k] + dp[j + k + 1][e] + r[j] * c[j + k] * c[e];
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}