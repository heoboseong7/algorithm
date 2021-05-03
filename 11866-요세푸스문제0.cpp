#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    queue<int> q;
    int n, k;
    int cnt = 1;
    cin >> n >> k;
    vector<int> ans;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        if (cnt++ % k == 0)
        {
            cnt = 1;
            ans.push_back(here);
        }
        else
        {
            q.push(here);
        }
    }
    cout << '<';
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i < ans.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << '>';

    return 0;
}