#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int h[9];
    for (int i = 0; i < 9; i++)
    {
        cin >> h[i];
    }
    sort(h, h + 9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == j)
                continue;
            int sum = 0;
            for (int k = 0; k < 9; k++)
            {
                if (k != i && k != j)
                {
                    sum += h[k];
                }
            }
            if (sum == 100)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k != j)
                    {
                        cout << h[k] << '\n';
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}