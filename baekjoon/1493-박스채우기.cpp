#include <bits/stdc++.h>

using namespace std;

int A[20];
int p2[21];
bool flag = true;
int ans = 0;

void solve(int L, int W, int H)
{
    if (!flag)
        return;
    int t = 19;
    int m = min(L, min(W, H));
    if (m == 0)
        return;
    while (p2[t] > m)
    {
        cout << t << ' ';
        t--;
        cout << t << '\n';
    }
    while (A[t] == 0)
    {
        t -= 1;
        if (t < 0)
        {
            flag = false;
            return;
        }
    }
    int l, w, h;
    A[t]--;
    ans++;
    l = w = h = p2[t];
    solve(L - l, W, H);
    solve(l, w, H - h);
    solve(l, W - w, H);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int l, w, h, n;
    cin >> l >> w >> h >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        A[a] = b;
        //cout << a << A[a] << '\n';
    }

    p2[0] = 1;
    for (int i = 1; i < 21; i++)
    {
        p2[i] = p2[i - 1] * 2;
        //cout << p2[i] << '\n';
    }

    solve(l, w, h);
    if (flag)
        cout << ans;
    else
        cout << -1;
    return 0;
}