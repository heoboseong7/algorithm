#include <bits/stdc++.h>

using namespace std;

int ans[3];
vector<vector<int>> v;

void solve(int x, int y, int n)
{
    int m = n / 3;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (v[x][y] != v[i][j])
            {
                for (int a = 0; a < 3; a++)
                {
                    for (int b = 0; b < 3; b++)
                    {
                        solve(x + m * a, y + m * b, m);
                    }
                }
                return;
            }
        }
    }
    ans[v[x][y] + 1]++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    v.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    solve(0, 0, n);
    cout << ans[0] << '\n'
         << ans[1] << '\n'
         << ans[2];
    return 0;
}