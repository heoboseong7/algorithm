#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> v1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    sort(v1.begin(), v1.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int a;
        cin >> a;
        cout << upper_bound(v1.begin(), v1.end(), a) - lower_bound(v1.begin(), v1.end(), a) << ' ';
    }
    return 0;
}