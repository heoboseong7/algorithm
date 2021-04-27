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

int A[1001];
int B[1001];
int moveA[1001];
int moveB[1001];
int dp[1001][2]; // a 0 b 1
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> A[i] >> B[i] >> moveA[i] >> moveB[i];
    }
    cin >> A[n - 1] >> B[n - 1];

    for (int i = 0; i < 1001; i++)
    {
        dp[i][0] = dp[i][1] = 987654321;
    }
    dp[0][0] = A[0];
    dp[0][1] = B[0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = min(dp[i][0], min(dp[i - 1][0], dp[i - 1][1] + moveB[i - 1]) + A[i]);
        dp[i][1] = min(dp[i][1], min(dp[i - 1][1], dp[i - 1][0] + moveA[i - 1]) + B[i]);
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]);
    return 0;
}
