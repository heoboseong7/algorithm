#include <bits/stdc++.h>

using namespace std;

vector<int> adj[101];
int cnt[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(cnt, 999999, 101 * sizeof(int));
    cnt[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int now = q.front();
        bool flag = false;
        q.pop();
        while (!adj[now].empty())
        {
            // q.push(adj[now][0]);
            if (cnt[adj[now][0]] > cnt[now])
            {
                cnt[adj[now][0]] = cnt[now];
                now = adj[now][0];
            }
            else
            {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        for (int i = 1; i <= 6; i++)
        {
            if (now + i > 100)
                break;

            if (cnt[now + i] > cnt[now] + 1)
            {
                cnt[now + i] = cnt[now] + 1;
                q.push(now + i);
            }
        }
    }
    cout << cnt[100];

    return 0;
}