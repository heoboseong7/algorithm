#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// map을 사용하지않고 p와 q로 나눈 횟수를 dp[p][q]로 표현
ull dp[50][50], N, P, Q;
// 구하려는 n과 지금까지 p와 q로 나눈 횟수를 인자로 넘김
// dp[p][q]에 저장하고 있으면 그 값을 활용 없으면 그 값을 구한다.
// 윗줄로 인해 계산횟수 감소(중복되는 계산부분을 제거)
ull solve(ull x, int p, int q) {
    if (x == 0)
        return 1;
    if (dp[p][q] != 0)
        return dp[p][q];
    return dp[p][q] = solve((ull)x / P, p + 1, q) + solve((ull)x / Q, p, q + 1);
}

int main() {
    scanf("%lld%lld%lld", &N, &P, &Q);
    printf("%lld\n", solve(N, 0, 0));
    return 0;
}
