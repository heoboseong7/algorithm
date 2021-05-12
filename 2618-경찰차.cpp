#include <bits/stdc++.h>
#define SIZE 1010

using namespace std;

int n;
int dp[1010][1010];
int p[1010][1010];
int bef[1010][1010][2];
int w[1010][2];
int t;
// 차의 현재 위치가 아래와 같을 때 이번 사건을 car1이 해결하는 경우와 car2가 해결하는 경우로 나눔
int solve(int num, int car1, int car2)
{
    if (num > t)
        return 0; // dp[car1][car2];
    if (dp[car1][car2] != -1)
        return dp[car1][car2];
    int x1 = 1, y1 = 1, x2 = n, y2 = n;
    if (car1 > 0)
    {
        x1 = w[car1][0];
        y1 = w[car1][1];
    }
    if (car2 > 0)
    {
        x2 = w[car2][0];
        y2 = w[car2][1];
    }
    int dist1 = abs(w[num][0] - x1) + abs(w[num][1] - y1);
    int dist2 = abs(w[num][0] - x2) + abs(w[num][1] - y2);
    dp[car1][car2] = solve(num + 1, num, car2) + dist1;
    int two = solve(num + 1, car1, num) + dist2;

    if (two < dp[car1][car2])
    {
        dp[car1][car2] = two;
        p[car1][car2] = 1;
    }

    return dp[car1][car2];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // 이 사건을 1번이 처리하는 경우, 2번이 처리하는 경우를 나눈다.
    cin >> n;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> w[i][0] >> w[i][1];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(1, 0, 0) << '\n';
    int x = 0, y = 0;
    while (max(x, y) < t)
    {
        cout << p[x][y] + 1 << '\n';
        if (p[x][y] == 1)
            y = max(x, y) + 1;
        else
            x = max(x, y) + 1;
    }
    return 0;
}