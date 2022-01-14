#include <bits/stdc++.h>

using namespace std;

int dpForward[1001];
int dpBackward[1001];
int n;
int arr[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        dpBackward[i] = 1;
        dpForward[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
                dpForward[i] = max(dpForward[i], dpForward[j] + 1);
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                dpBackward[i] = max(dpBackward[i], dpBackward[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dpForward[i] + dpBackward[i] - 1);
    }

    cout << ans << '\n';
    return 0;
}