#include <bits/stdc++.h>

using namespace std;

int n, m;
int ans;
bool check[4][4];
// 1 세로 0 가로
int calc(int k, vector<vector<int>> v)
{
    int ret = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            check[i][j] = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check[i][j])
                continue;
            int here = i * m + j;
            int nx = i, ny = j;
            int cur = 0;
            if (k & (1 << here))
            {
                while (nx < n && ny < m)
                {
                    if ((k & (1 << here)) && !check[nx][ny])
                    {
                        cur = cur * 10 + v[nx][ny];
                        check[nx][ny] = true;
                        nx += 1;
                        here += m;
                    }
                    else
                        break;
                }
            }
            else
            {
                while (nx < n && ny < m)
                {
                    if (((k & (1 << here)) == 0) && !check[nx][ny])
                    {
                        cur = cur * 10 + v[nx][ny];
                        check[nx][ny] = true;
                        ny += 1;
                        here += 1;
                    }
                    else
                        break;
                }
            }
            ret += cur;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            v[i][j] = (int)(c - 48);
        }
    }

    for (int k = 0; k < (1 << 16); k++)
    {
        ans = max(ans, calc(k, v));
    }
    cout << ans;

    return 0;
}