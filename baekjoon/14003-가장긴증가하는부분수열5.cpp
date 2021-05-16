#include <bits/stdc++.h>
#define MIN -1987654321

using namespace std;

int n;
int A[1000001];
int D[1000001];
int LIS[1000001];
int m = 1;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        LIS[i] = MIN;
    }
    for (int i = 0; i < n; i++)
    {
        if (LIS[m - 1] < A[i])
        {
            LIS[m] = A[i];
            D[i] = m;
            m++;
        }
        else
        {
            int s = 0;
            int e = m;
            int mid;
            while (s < e)
            {
                mid = (s + e) / 2;
                if (LIS[mid] < A[i])
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid;
                }
            }
            if (LIS[e] > A[i])
            {
                LIS[e] = A[i];
            }
            D[i] = e;
        }
    }
    cout << m - 1 << '\n';
    int k = m - 1;
    int bef = LIS[k] + 1;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] < bef && D[i] == k)
        {
            v.push_back(A[i]);
            k -= 1;
            bef = A[i];
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i] << ' ';
    }
    return 0;
}