#include <bits/stdc++.h>

using namespace std;

int ans;
int r, c;

int _search(int x, int y, int m)
{
    int ret = 0;
    for (int i = x; i < x + 2 * m; i += m)
    {
        for (int j = y; j < y + 2 * m; j += m)
        {
            if (r >= i && r < i + m && c >= j && c < j + m)
            {
                return ret;
            }
            ret++;
        }
    }
}

void solve(int x, int y, int n)
{
    if (x == r && y == c)
        return;

    int m = pow(2, n - 1);
    int s = _search(x, y, m);
    ans += s * m * m;
    int nx = x + m * (s / 2);
    int ny = y + m * (s % 2);
    solve(nx, ny, n - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n >> r >> c;
    solve(0, 0, n);
    cout << ans;

    return 0;
}