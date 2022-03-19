#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
int n, m;
int color[100001];
int colorIdx = 1;
int lecture[100001];

void dfs(int here, int c)
{
    color[here] = c;
    for (int i = 0; i < adj[here].size(); i++)
    {
        int next = adj[here][i];
        if (color[next] == 0)
        {
            dfs(next, c);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int ta, tb;
    for (int i = 0; i < m; i++)
    {
        cin >> ta >> tb;
        adj[ta].push_back(tb);
        adj[tb].push_back(ta);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> lecture[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (color[i] == 0)
        {
            dfs(i, colorIdx);
            colorIdx++;
        }
    }

    int ans = 0;

    for (int i = 1; i < n; i++)
    {
        int prev = lecture[i - 1];
        int now = lecture[i];

        if (color[prev] != color[now])
        {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}