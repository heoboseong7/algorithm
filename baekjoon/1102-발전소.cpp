#include <bits/stdc++.h>
#define INF 98765432

using namespace std;

int n, k;
int cost[16][16];
int dp[(1 << 16) - 1];
int state;
int ans = INF;

int solve(int num, int s)
{
    if (num == k)
        return 0;
    if (dp[s] < INF)
        return dp[s];
    vector<int> v0;
    vector<int> v1;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((s & (1 << i)) == 0)
        {
            v0.push_back(n - i - 1);
        }
        else
        {
            v1.push_back(n - i - 1);
        }
    }
    //printf("hi%d %d", v0.size(), v1.size());
    for (int i = 0; i < v0.size(); i++)
    {
        int m = INF;
        for (int j = 0; j < v1.size(); j++)
        {
            m = min(m, cost[v1[j]][v0[i]]);
        }
        int next = s | (1 << (n - v0[i] - 1));
        //printf("%d\n", dp[next]);
        //dp[next] = dp[s] + m;
        dp[s] = min(dp[s], m + solve(num + 1, next));
    }
    return dp[s];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    memset(dp, INF, sizeof(dp));
    int cnt = 0;
    getchar();
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf("%c", &c);
        if (c == 'Y')
        {
            cnt++;
            state |= 1 << (n - 1 - i);
        }
    }
    scanf("%d", &k);
    //dp[state] = 0;
    //printf("state : %d", state);
    ans = solve(cnt, state);
    if (k <= cnt)
        ans = 0;
    if (ans < INF)
        printf("%d", ans);
    else
        printf("-1");
    return 0;
}