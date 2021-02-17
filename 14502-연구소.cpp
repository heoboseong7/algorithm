#include <bits/stdc++.h>

using namespace std;

int lab[8][8];
bool visited[8][8];
int n, m, nm;
int ans = -9876;
vector<int> v;

int test()
{
    queue<int> qx, qy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
            if (lab[i][j] == 2)
            {
                qx.push(i);
                qy.push(j);
            }
        }
    }
    int ret = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!qx.empty())
    {
        int x = qx.front(), y = qy.front();
        qx.pop();
        qy.pop();
        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if (nx >= 0 && ny >= 0 && nx < n && ny < m)
            {
                if (!visited[nx][ny] && lab[nx][ny] != 1)
                {
                    qx.push(nx);
                    qy.push(ny);
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && lab[i][j] == 0)
            {
                ret++;
            }
        }
    }
    return ret;
}

void solve(int here)
{
    int herex = here / m, herey = here % m;
    if (v.size() == 3)
    {
        for (int i = 0; i < v.size(); i++)
        {
            int x = v[i] / m, y = v[i] % m;
            lab[x][y] = 1;
        }
        ans = max(ans, test());
        for (int i = 0; i < v.size(); i++)
        {
            int x = v[i] / m, y = v[i] % m;
            lab[x][y] = 0;
        }
        return;
    }
    if (here >= nm)
        return;
    if (lab[herex][herey] == 0)
    {
        if (here < nm)
        {
            v.push_back(here);
            solve(here + 1);
            v.pop_back();
            solve(here + 1);
        }
    }
    else
    {
        if (here < nm)
        {
            solve(here + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    nm = n * m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> lab[i][j];
        }
    }
    solve(0);
    cout << ans;

    return 0;
}