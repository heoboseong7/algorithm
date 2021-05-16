#include <bits/stdc++.h>

using namespace std;

int dp[1 << 16][16] = {};
int n;
int w[16][16];
int ans = 987654321;

int tsp(int here, int visited)
{
    if (visited == (1 << n) - 1)
    {
        if (w[here][0] != 0)
            return w[here][0];
        else
            return 987654321;
    }
    if (dp[visited][here] != 0)
        return dp[visited][here];

    //int cost = 987654321;
    dp[visited][here] = 987654321;
    for (int next = 1; next < n; next++)
    {
        int next_state = visited | (1 << next);

        if (w[here][next] != 0 && (visited & (1 << next)) == 0)
        {
            dp[visited][here] = min(dp[visited][here], tsp(next, next_state) + w[here][next]);
        }
    }
    //dp[visited][here] = cost;
    return dp[visited][here];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> w[i][j];

    //tsp(0, 1);
    cout << tsp(0, 1);

    return 0;
}