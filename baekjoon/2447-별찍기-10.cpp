#include <bits/stdc++.h>

using namespace std;

string s[6561];

void solve(int x, int y, int n)
{
    if (n <= 1)
        return;

    int m = n / 3;
    for (int i = x + m; i < x + 2 * m; i++)
    {
        for (int j = y + m; j < y + 2 * m; j++)
        {
            s[i][j] = ' ';
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!(i == 1 && j == 1))
            {
                solve(x + m * i, y + m * j, n / 3);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s[i].assign(n, '*');
    }
    solve(0, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << '\n';
    }
    return 0;
}