#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m;
int ans = -1;
vector<int> gen(int k)
{
    vector<int> ret(10);
    for (int i = 0; i < 10; i++)
    {
        ret[i] = (k & 3);
        k = k >> 2;
    }
    return ret;
}

bool is_valid(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] == v[i])
            return false;
        if (v[i - 1] == 0 && v[i] == 1)
            return false;
        if (v[i - 1] == 2 && v[i] == 3)
            return false;
        if (v[i - 1] == 1 && v[i] == 0)
            return false;
        if (v[i - 1] == 3 && v[i] == 2)
            return false;
    }
    return true;
}

pair<bool, bool> simulate(vector<string> &a, int dir, int &x, int &y)
{
    //  해당 좌표의 이미 공이 구멍에 들어간 경우
    if (a[x][y] == '.')
        return make_pair(false, false);
    bool moved = false;
    while (1)
    {
        int nx = x + dx[dir], ny = y + dy[dir];
        if (a[nx][ny] == '#')
            return make_pair(moved, false);
        else if (a[nx][ny] == 'B' || a[nx][ny] == 'R')
            return make_pair(moved, false);
        else if (a[nx][ny] == '.')
        {
            swap(a[x][y], a[nx][ny]);
            x = nx;
            y = ny;
            moved = true;
        }
        else if (a[nx][ny] == 'O')
        {
            a[x][y] = '.';
            moved = true;
            return make_pair(moved, true);
        }
    }
    return make_pair(false, false);
}

int check(vector<string> a, vector<int> &dir)
{
    int rx, ry, bx, by, hx, hy;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
            if (a[i][j] == 'R')
            {
                rx = i;
                ry = j;
            }
            if (a[i][j] == 'O')
            {
                hx = i;
                hy = j;
            }
        }
    }
    for (int i = 0; i < dir.size(); i++)
    {
        bool rhole = false, bhole = false;
        while (1)
        {
            auto s1 = simulate(a, dir[i], rx, ry); // red ball
            auto s2 = simulate(a, dir[i], bx, by); // blue ball

            if (!s1.first && !s2.first)
            {
                break;
            }
            if (s1.second)
            {
                rhole = true;
            }
            if (s2.second)
            {
                bhole = true;
            }
        }
        if (bhole)
            return -1;
        if (rhole)
        {
            return (i + 1);
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    vector<string> a(10);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < (1 << 20); i++)
    {
        vector<int> v = gen(i);
        if (!is_valid(v))
            continue;
        int cur = check(a, v);

        if (cur == -1)
            continue;
        if (ans == -1 || ans > cur)
        {
            ans = cur;
        }
    }
    cout << ans;

    return 0;
}
