#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, s;
    cin >> n >> s;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int left = 0, right = 0;
    int sum = v[0], ans = INF;
    while (left != n - 1)
    {
        if (left == right)
        {
            right++;
            sum += v[right];
        }
        else if (right == n - 1)
        {
            sum -= v[left];
            left++;
        }
        else if (sum < s)
        {
            right++;
            sum += v[right];
        }
        else if (sum >= s)
        {
            sum -= v[left];
            left++;
        }

        if (sum >= s)
        {
            ans = min(ans, right - left + 1);
        }
    }
    if (ans != INF)
        cout << ans;
    else
        cout << 0;
    return 0;
}