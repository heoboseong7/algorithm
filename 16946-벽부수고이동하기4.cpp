#include <bits/stdc++.h>

using namespace std;

int n, m;
int MAP[1002][1002];
int ans[1002][1002];
bool visited[1002][1002];
int move_num[1002 * 1002];
int color[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            if (s[j - 1] == '0')
            {
                MAP[i][j] = 2;
            }
            else
            {
                MAP[i][j] = 1;
            }
        }
    }
    int clr = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int cnt = 0;
            if (MAP[i][j] == 2 && !visited[i][j])
            {
                queue<int> xq, yq;
                xq.push(i);
                yq.push(j);
                while (!xq.empty())
                {
                    int x = xq.front(), y = yq.front();
                    xq.pop();
                    yq.pop();
                    if (visited[x][y])
                        continue;
                    color[x][y] = clr;
                    visited[x][y] = true;
                    cnt++;
                    for (int k = 0; k < 4; k++)
                    {
                        if (MAP[x + dx[k]][y + dy[k]] == 2 && !visited[x + dx[k]][y + dy[k]])
                        {
                            xq.push(x + dx[k]);
                            yq.push(y + dy[k]);
                        }
                    }
                }
                move_num[clr] = cnt;
                clr++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (MAP[i][j] == 1)
            {
                set<int> SET;
                for (int ii = 0; ii < 4; ii++)
                {
                    int x = i + dx[ii], y = j + dy[ii];
                    if (MAP[x][y] == 2 && SET.find(color[x][y]) == SET.end())
                    {
                        SET.insert(color[x][y]);
                        ans[i][j] += move_num[color[x][y]];
                    }
                }
                ans[i][j] = (ans[i][j] + 1) % 10;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    // cout << move_num[1];
    return 0;
}