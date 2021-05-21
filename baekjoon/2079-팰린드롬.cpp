#include <bits/stdc++.h>

using namespace std;

bool palindrome[2001][2001];
int dp[2001];
string s;

int main()
{
    cin.tie();
    ios_base::sync_with_stdio(false);

    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        palindrome[i][i] = true;
    }

    for (int i = 1; i < n; i++)
    {
        if (s[i - 1] == s[i])
        {
            palindrome[i - 1][i] = true;
        }
    }

    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[j] == s[j + i] && palindrome[j + 1][j + i - 1])
            {
                palindrome[j][j + i] = true;
            }
        }
    }

    fill(dp, dp + 2001, 99999);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (palindrome[i][j])
            {
                if (i == 0)
                    dp[j] = min(dp[0], dp[j]);
                else
                    dp[j] = min(dp[i - 1] + 1, dp[j]);
            }
        }
    }

    printf("%d", dp[n - 1] + 1);

    return 0;
}