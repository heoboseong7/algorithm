#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101];
bool check[101];

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

    queue<int> q;
    q.push(1);
    check[1] = true;
    int ans = 0;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int i = 0; i < adj[here].size(); i++)
        {
            int next = adj[here][i];
            if (!check[next])
            {
                check[next] = true;
                q.push(next);
                ans++;
            }
        }
    }
    cout << ans;

    return 0;
}