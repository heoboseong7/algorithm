#include <bits/stdc++.h>

using namespace std;

int n;
bool now[100000];
string s1, s2;
void change(int idx)
{
    if (idx == 0)
    {
        now[0] = !now[0];
        now[1] = !now[1];
    }
    else if (idx == n - 1)
    {
        now[n - 2] = !now[n - 2];
        now[n - 1] = !now[n - 1];
    }
    else
    {
        now[idx - 1] = !now[idx - 1];
        now[idx] = !now[idx];
        now[idx + 1] = !now[idx + 1];
    }
}

int calc(bool flag)
{
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            now[i] = true;
        }
        else
        {
            now[i] = false;
        }
    }
    int cnt = 0;
    int ans = -1;
    if (flag)
    {
        change(0);
        cnt++;
    }

    for (int i = 1; i < n; i++)
    {
        if (now[i - 1])
        {
            change(i);
            cnt++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (now[i])
        {
            return -1;
        }
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    cin >> s1 >> s2;

    int ans = -1;
    int a = calc(false), b = calc(true);
    if (a != -1 && b != -1)
    {
        ans = min(a, b);
    }
    else if (a != -1 || b != -1)
    {
        ans = max(a, b);
    }

    cout << ans;

    return 0;
}