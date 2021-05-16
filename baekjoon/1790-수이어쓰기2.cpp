#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
string s;
vector<ll> p10;
vector<ll> v;

// 현재 남은 k 숫자, 자리수
ll solve(int k)
{
    int flag = 0;
    if (k < 10)
    {
        s += k + 48;
        return k;
    }
    while (k >= 10)
    {
        int tn = 1;
        while (k > v[tn])
        {
            tn++;
        }
        int tk = (k - v[tn - 1]);
        for (int i = 0; i < 10; i++)
        {
            int a = p10[tn - 1] * tn * i + 1;
            int b = p10[tn - 1] * tn * (i + 1) + 1;
            if (tk >= a && tk < b)
            {
                //cout << i + 1 << ' ';
                s += i + 49;
                flag = tk % 2;
                k = tk - a;
                k /= tn;
                break;
            }
        }
    }
    //cout << '\n';
    int back = (int)s.back() - 48;
    s += k + 48;
    if (flag == 1)
    {
        return back;
    }

    return k;
}
int main()
{
    int n, k;
    cin >> n >> k;
    v.push_back(0);
    p10.push_back(1);
    for (ll i = 1; i < 100000000; i++)
    {
        p10.push_back(p10[i - 1] * 10);
        v.push_back(v[i - 1] + p10[i - 1] * 9 * i);
        //cout << v.back() << '\n';
        if (v[i] > 1000000000)
            break;
    }
    int ans = solve(k);

    if (atoi(s.c_str()) <= n)
        cout << ans;
    else
        cout << -1;

    return 0;
}