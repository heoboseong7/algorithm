#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 중국인의 나머지 정리 사용
    int n[3] = {15, 28, 19};
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    int mn = n[0] * n[1] * n[2];
    int N[3];
    int x[3];
    // 식 설계 gcd(N[i], n[i]) = 1
    for (int i = 0; i < 3; i++)
    {
        N[i] = mn / n[i];
    }
    // 선형 합동식의 특수해 x에 저장
    for (int i = 0; i < 3; i++)
    {
        int t = 1;
        while ((N[i] * t) % n[i] != 1)
        {
            t++;
        }
        x[i] = t;
    }
    int ans = 0;
    // 연립 합동식의 해 계산
    for (int i = 0; i < 3; i++)
    {
        // 범위가 0 ~ 시작하는 프로그램과 1 ~로 시작하는 문제의 차이점 반영
        ans += (a[i] - 1) * N[i] * x[i];
    }
    ans = ans % mn;
    // 범위가 1부터 시작하므로 정답에 1 더해줌.
    cout << ans + 1;

    return 0;
}