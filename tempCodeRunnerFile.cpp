<<<<<<< HEAD
#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int n;
int dp[101][10][1 << 10];

int solve(int cnt, int num, int bits)
{
    int ret = dp[cnt][num][bits];
    if (dp[cnt][num][bits] != -1)
    {
        return ret;
    }

    if (cnt == n)
    {
        if (bits == (1 << 10) - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    ret = 0;
    if (num == 0)
    {
        ret += solve(cnt + 1, num + 1, bits | (1 << (num + 1)));
        ret %= MOD;
    }
    else if (num == 9)
    {
        ret += solve(cnt + 1, num - 1, bits | (1 << (num - 1)));
        ret %= MOD;
    }
    else
    {
        ret += solve(cnt + 1, num + 1, bits | (1 << (num + 1)));
        ret %= MOD;
        ret += solve(cnt + 1, num - 1, bits | (1 << (num - 1)));
        ret %= MOD;
    }

    return ret;
}

int main()
{
    scanf("%d", &n);
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i < 10; i++)
    {
        ans += solve(1, i, 1 << i);
        ans %= MOD;
    }

    printf("%d", ans);
    return 0;
}
=======
f (v.size() == 3)
    {
        for (int i = 0; i < v.size(); i++)
        {
            int x = v[i] / m, y = v[i] % m;
            lab[x][y] = 1;
        }
        ans = max(ans, test());
        for (int i = 0; i < v.size(); i++)
        {
            int x = v[i] / m, y = v[i] % m;
            lab[x][y] = 0;
        }
        return;
    }
>>>>>>> 7863e7f04309c4d06efc49374e2ab935fa3fe38e
