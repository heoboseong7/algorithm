#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int N;
ll A, B, C;
ll D[101];
ll nowcost, nowcal;

ll calc(ll cost, ll cal)
{
    return (ll)(cal / cost);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> A >> B >> C;
    nowcost = A;
    nowcal = C;
    for (int i = 0; i < N; i++)
    {
        cin >> D[i];
    }
    sort(D, D + N, greater<int>());

    int idx = 0;
    // nowcal / nowcost < (nowcal + D[i]) / (nowcost + B)
    while (nowcal * (nowcost + B) < (nowcal + D[idx]) * nowcost)
    {
        nowcost += B;
        nowcal += D[idx];
        idx++;
    }
    cout << calc(nowcost, nowcal);

    return 0;
}