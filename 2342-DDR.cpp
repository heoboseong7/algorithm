#include <bits/stdc++.h>
#define SIZE 100001

using namespace std;

int dp[SIZE][5][5];

int cost(int here, int next)
{
    if (here == 0)
        return 2;
    else if (here == next)
        return 1;
    else if (abs(here - next) == 2)
        return 4;
    else
        return 3;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int input;
    cin >> input;
    int cnt = 0;
    dp[0][0][input] = 2;
    dp[0][input][0] = 2;

    while (input)
    {
        cin >> input;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (i == j)
                    continue;
                if (dp[cnt][i][j] != 0)
                {
                    if (dp[cnt + 1][input][j] == 0)
                        dp[cnt + 1][input][j] = dp[cnt][i][j] + cost(i, input);
                    else
                        dp[cnt + 1][input][j] = min(dp[cnt][i][j] + cost(i, input), dp[cnt + 1][input][j]);

                    if (dp[cnt + 1][i][input] == 0)
                        dp[cnt + 1][i][input] = dp[cnt][i][j] + cost(j, input);
                    else
                        dp[cnt + 1][i][input] = min(dp[cnt][i][j] + cost(j, input), dp[cnt + 1][i][input]);
                }
                //cout << dp[cnt][i][j] << ' ';
            }
        }
        cnt++;
    }
    int ans = 987654321;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (dp[cnt - 1][i][j] != 0)
                ans = min(ans, dp[cnt - 1][i][j]);
        }
    }

    cout << ans;
    return 0;
}