#include <bits/stdc++.h>

using namespace std;

vector<int> adj[2001];
int ans;
bool check[2001];

void dfs(int here, int deepth)
{
    if (deepth >= 5)
    {
        ans = 1;
        return;
    }
    check[here] = true;
    for (int i = 0; i < adj[here].size(); i++)
    {
        int next = adj[here][i];
        if (!check[next])
            dfs(next, deepth + 1);
    }
    check[here] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        memset(check, false, sizeof(check));
        dfs(i, 1);
        if (ans > 0)
            break;
    }
    cout << ans;
    return 0;
}