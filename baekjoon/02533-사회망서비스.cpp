#include <bits/stdc++.h>

using namespace std;

// 0: 일반인, 1: 얼리어댑터
int dp[1000001][2];
vector<int> tree[1000001];
bool visited[1000001];
int n;

void solve(int here)
{
    dp[here][1] = 1;
    visited[here] = true;
    for (int i = 0; i < tree[here].size(); i++)
    {
        int next = tree[here][i];
        if (visited[next])
            continue;
        solve(next);
        dp[here][0] += dp[next][1];
        dp[here][1] += min(dp[next][0], dp[next][1]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int u, v;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    solve(1);
    cout << min(dp[1][0], dp[1][1]);

    return 0;
}