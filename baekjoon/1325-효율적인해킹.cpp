#include <bits/stdc++.h>

using namespace std;

vector<int> adj[10001];
bool check[10001];
vector<int> ans;
int num = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> b >> a;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        memset(check, false, 10001);
        queue<int> q;
        q.push(i);
        check[i] = true;
        int cnt = 1;
        while (!q.empty())
        {
            int here = q.front();
            q.pop();

            for (int j = 0; j < (int)adj[here].size(); j++)
            {
                if (!check[adj[here][j]])
                {
                    q.push(adj[here][j]);
                    cnt++;
                    check[adj[here][j]] = true;
                }
            }
        }

        if (num < cnt)
        {
            ans.clear();
            ans.push_back(i);
            num = cnt;
        }
        else if (num == cnt)
        {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}