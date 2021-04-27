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

int k, n;
int L[101][101];
int m[101][101];
int dp[101][101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> L[i][j];
            // cout << L[i][j] << ' ';
        }
        if (i < n - 1)
            for (int j = 0; j < k; j++)
            {
                cin >> m[i][j];
            }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            dp[i][j] = 987654321;
        }
    }

    for (int j = 0; j < k; j++)
    {
        dp[0][j] = L[0][j];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int t = 0; t < k; t++)
            {
                if (j == t)
                    dp[i][j] = min(dp[i][j], dp[i - 1][t] + L[i][j]);
                else
                    dp[i][j] = min(dp[i][j], dp[i - 1][t] + m[i - 1][t] + L[i][j]);
            }
        }
    }
    int ans = 987654321;
    for (int i = 0; i < k; i++)
    {
        ans = min(ans, dp[n - 1][i]);
    }
    cout << ans;
    return 0;
}
