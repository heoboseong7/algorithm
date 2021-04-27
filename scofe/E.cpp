#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for (int var = start; var < to; var++)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
#define ABS(a) ((a < 0) ? -a : a)
#define fi first
#define se second
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m;
string board[1001];
int cnt[1001][21];

void move(int x, int y, int cost)
{
    cnt[x][y] = cost;
    if (x == m - 1)
        return;

    if (x + 1 < m)
    {
        if (cnt[x + 1][y] > cost && board[x + 1][y] != 'x')
        {
            move(x + 1, y, cost);
        }
    }
    if (y + 1 < n)
    {
        if (cnt[x][y + 1] > cost + 1 && board[x][y + 1] != 'x')
        {
            move(x, y + 1, cost + 1);
        }
    }
    if (y - 1 >= 0)
    {
        if (cnt[x][y - 1] > cost + 1 && board[x][y - 1] != 'x')
        {
            move(x, y - 1, cost + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> board[i];
    }
    vii vp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cnt[i][j] = INF;
            if (board[i][j] == 'c')
            {
                vp.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < (int)vp.size(); i++)
    {
        int x = vp[i].first;
        int y = vp[i].second;
        cnt[x][y] = 0;
        move(x, y, 0);
    }
    int ans = INF;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, cnt[m - 1][i]);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cnt[i][j] << ' ';
        }
        cout << '\n';
    }

    if (ans == INF)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    return 0;
}
