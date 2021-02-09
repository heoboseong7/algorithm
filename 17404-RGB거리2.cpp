#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int main()
{
    int a[1001][3];
    int b[3][1001][3];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    for (int i = 0; i < 3; i++)
    {
        b[i][0][0] = INF;
        b[i][0][1] = INF;
        b[i][0][2] = INF;
    }
    b[0][0][0] = a[0][0];
    b[1][0][1] = a[0][1];
    b[2][0][2] = a[0][2];
    // 1번을 무엇을 선택하느냐에 따라 dp값을 나눔
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            b[j][i][0] = a[i][0] + min(b[j][i - 1][1], b[j][i - 1][2]);
            b[j][i][1] = a[i][1] + min(b[j][i - 1][0], b[j][i - 1][2]);
            b[j][i][2] = a[i][2] + min(b[j][i - 1][1], b[j][i - 1][0]);
        }
    }
    // n번째 선택하는 경우 a a : b or c /  a b : c /  a c : b
    /* if i != j
     * b[i][n - 1][j] = a[n-1][j] + min n-2들 중 j != k 를 찾음
    */
    int ans = INF;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i != j)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (j != k)
                        ans = min(ans, a[n - 1][j] + b[i][n - 2][k]);
                }
            }
        }
    }
    cout << ans;
    return 0;
}