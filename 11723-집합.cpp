#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int s = 0;
    while (n--)
    {
        string t;
        int m;
        cin >> t;
        if (t != "all" && t != "empty")
        {
            cin >> m;
        }
        if (t == "add")
        {
            s |= 1 << (m - 1);
        }
        else if (t == "remove")
        {
            s &= ~(1 << (m - 1));
        }
        else if (t == "check")
        {
            if (s & (1 << (m - 1)))
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (t == "toggle")
        {
            if (s & (1 << (m - 1)))
            {
                s &= (1 << 20) - 1 - (1 << (m - 1));
            }
            else
            {
                s |= 1 << (m - 1);
            }
        }
        else if (t == "all")
        {
            s |= (1 << 20) - 1;
        }
        else if (t == "empty")
        {
            s &= 0;
        }
    }
    return 0;
}