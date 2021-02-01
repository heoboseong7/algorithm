#include <bits/stdc++.h>

using namespace std;

int N;
string s[64];
string ans;

void solve(int x, int y, int n)
{
    bool flag = false;
    for (int i = x; i < x + n; i++)
    {
        for (int j = y; j < y + n; j++)
        {
            if (s[x][y] != s[i][j])
            {
                flag = true;
                break;
            }
        }
    }
    if (!flag)
    {
        ans += s[x][y];
        return;
    }
    ans += '(';
    int half = int(n / 2);
    solve(x, y, half);
    solve(x, y + half, half);
    solve(x + half, y, half);
    solve(x + half, y + half, half);
    ans += ')';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> s[i];
    }
    solve(0, 0, N);
    cout << ans;

    return 0;
}