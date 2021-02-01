#include <bits/stdc++.h>

using namespace std;

int n, len, k;

int main()
{
    cin >> n;
    len = 3;
    k = 3;
    while (n > len)
    {
        k++;
        len = len * 2 + k;
    }

    while (1)
    {
        int t = (len - k) / 2;
        if (n <= t)
        {
            len = t;
            k--;
        }
        else if (n > t + k)
        {
            n -= t + k;
            len = t;
            k--;
        }
        else
        {
            n -= t;
            break;
        }
    }
    if (n == 1)
        cout << 'm';
    else
        cout << 'o';
    return 0;
}