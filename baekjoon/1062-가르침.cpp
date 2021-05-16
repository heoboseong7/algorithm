#include <bits/stdc++.h>

using namespace std;
int word[50];
int n, k;
int base = 532741; // "antic"
int taught;
int ans = 0;

void rec(int here, int cnt)
{
    if (base & taught)
        return;
    if (cnt == k - 5)
    {
        int sum = 0;
        taught |= base;
        for (int i = 0; i < n; i++)
        {
            if ((word[i] & taught) == word[i])
                sum++;
        }
        ans = max(ans, sum);
        taught -= base;
        return;
    }
    if (here < 26)
    {
        taught += 1 << here;
        rec(here + 1, cnt + 1);
        taught -= 1 << here;
        rec(here + 1, cnt);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            word[i] |= 1 << (s[j] - 'a');
        }
        //cout << word[i] << ' ';
    }
    if (k - 5 < 0)
    {
        cout << 0;
        return 0;
    }
    rec(0, 0);
    cout << ans;

    return 0;
}