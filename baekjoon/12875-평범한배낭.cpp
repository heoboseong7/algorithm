#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int n, k;
int dp[100001];
int w[1001];
int v[1001];
int ans;

int main()
{
    scanf("%d %d", &n, &k);
    // fill(dp, dp + 100001, INF);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &w[i], &v[i]);

    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= w[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            ans = max(ans, dp[j]);
        }
    }
    printf("%d", ans);
    return 0;
}