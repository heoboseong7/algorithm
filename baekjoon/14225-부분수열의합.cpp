#include <bits/stdc++.h>

using namespace std;

int n;
int S[20];
bool check[2000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
    }
    int to = (int)pow(2, n);
    for (int i = 1; i < to; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                sum += S[j];
        }
        check[sum] = true;
    }
    for (int i = 1; i < 2000001; i++)
    {
        if (!check[i])
        {
            cout << i;
            break;
        }
    }

    return 0;
}