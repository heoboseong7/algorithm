#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
string s1, s2;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> s1 >> s2;
    int n1 = s1.length();
    int n2 = s2.length();
    int t = 1;
    string ans = "";
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    int x = n1, y = n2;
    while (dp[x][y] != 0)
    {
        if (dp[x][y] == dp[x - 1][y])
        {
            x--;
        }
        else if (dp[x][y] == dp[x][y - 1])
        {
            y--;
        }
        else
        {
            x--;
            y--;
            ans = s2[y] + ans;
        }
    }

    cout << dp[n1][n2] << '\n'
         << ans;
    return 0;
}