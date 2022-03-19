#include <bits/stdc++.h>

using namespace std;

int A[100];
int B[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int pos = 1;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int sum1 = 0;
        int sum2 = 0;
        int idx = 0;
        while (1)
        {
            if (idx % 2 == 0)
            {
                cin >> A[idx];
                sum1 += A[idx];
            }
            else
            {
                cin >> B[idx];
                sum2 += B[idx];
            }
            if (sum1 == 14 && sum2 == 13)
                break;
            idx++;
        }
        int lSum = 0;
        int rSum = 0;
        if (pos <= 13)
        {
            // left
            for (int j = 0; j < idx + 1; j++)
            {
                if (j % 2 == 1)
                {
                    if (lSum + B[j] >= pos)
                    {
                        pos = rSum + pos;
                        // cout << pos << '\n';
                        break;
                    }
                    lSum += B[j];
                }
                else
                {
                    rSum += A[j];
                }
            }
        }
        else
        {
            // right
            pos -= 13;
            for (int j = 0; j < idx + 1; j++)
            {
                if (j % 2 == 1)
                {
                    lSum += B[j];
                }
                else
                {
                    if (rSum + A[j] >= pos)
                    {
                        pos = lSum + pos;
                        // cout << pos << '\n';
                        break;
                    }
                    rSum += A[j];
                }
            }
        }
    }
    cout << pos << '\n';

    return 0;
}