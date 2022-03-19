#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[101][51][51];
int r[101];
int b[101];
int d[101];
pair<int, int> ans[100001];

// 빨간알약개수, 파란알약개수 위험도
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> r[i] >> b[i] >> d[i];
    }

    fill(dp[0][0], dp[100][0], -1);
    dp[0][r[0]][b[0]] = d[0];
    dp[0][0][0] = 0;

    for (int i = 1; i < m; i++)
    {
        int redNum = r[i];
        int blueNum = b[i];
        for (int j = 50; j >= 0; j--)
        {
            for (int k = 50; k >= 0; k--)
            {
                int prevRed = j - redNum;
                int prevBlue = k - blueNum;

                if (prevRed >= 0 && prevBlue >= 0 && dp[i - 1][prevRed][prevBlue] != -1)
                {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][prevRed][prevBlue] + d[i]);
                }
                else
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int red, blue;
        cin >> red >> blue;

        ans[i].first = dp[m - 1][red][blue] != -1 ? dp[m - 1][red][blue] : 0;
        ans[i].second = i + 1;
    }

    sort(ans, ans + n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i].second << ' ' << ans[i].first << '\n';
    }
    return 0;
}