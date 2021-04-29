#include <bits/stdc++.h>

using namespace std;

int n, M;
int memory[101];
int c[101];
int dp[10001];
int sum;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> M;
    for (int i = 0; i < n; i++)
    {
        cin >> memory[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        sum += c[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j >= c[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - c[i]] + memory[i]);
        }
    }
    for (int i = 0; i <= sum; i++)
    {
        if (dp[i] >= M)
        {
            printf("%d", i);
            break;
        }
    }
    return 0;
}