#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end());
    for (auto i : p)
    {
        cout << i.second << ' ' << i.first << '\n';
    }
    return 0;
}