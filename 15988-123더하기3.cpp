#include <bits/stdc++.h>
#define MOD 1000000009
#define MAX 1000001
using namespace std;

long long dp[MAX + 3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    dp[0] = 1;
    for (int i = 0; i < MAX; i++)
    {
        dp[i + 1] = (dp[i] + dp[i + 1]) % MOD;
        dp[i + 2] = (dp[i] + dp[i + 2]) % MOD;
        dp[i + 3] = (dp[i] + dp[i + 3]) % MOD;
    }

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}