#include <bits/stdc++.h>

using namespace std;

int T;
int dp[501][501];
int sum[501];
int k;

int main()
{
    scanf("%d", &T);
    int n = sizeof(dp);
    while (T--)
    {
        fill(&dp[0][0], &dp[500][501], 98765432);
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &dp[i][i]);
            if (i == 0)
                sum[i + 1] = dp[i][i];
            else
                sum[i + 1] = sum[i] + dp[i][i];
            //printf("s: %d\n", sum[i + 1]);
        }

        for (int len = 2; len <= k; len++)
        {
            for (int s = 0; s <= k - len; s++)
            {
                int e = s + len - 1;
                for (int mid = s; mid < e; mid++)
                {
                    dp[s][e] = min(dp[s][e], dp[s][mid] + dp[mid + 1][e] + sum[e + 1] - sum[s]);
                    //printf("%d %d %d %d\n", s, e, dp[s][e], sum[e + 1] - sum[s]);
                }
            }
        }
        printf("%d\n", dp[0][k - 1] - sum[k]);
    }
    return 0;
}