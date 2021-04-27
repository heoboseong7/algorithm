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
ll store[10001][101];
ll dp[10001][101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> store[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    dp[i][j] = store[i][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] + store[i][j];
                }
            }
            else
            {
                if (j == 0)
                {
                    dp[i][j] = dp[i - 1][j] + store[i][j];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + store[i][j];
                }
            }
        }
    }
    cout << dp[m - 1][n - 1];
    return 0;
}
