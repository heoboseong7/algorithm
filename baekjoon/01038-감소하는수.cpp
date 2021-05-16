#include <bits/stdc++.h>

using namespace std;

vector<long long int> v;
int n, cnt = 0;
string ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n > 1022)
    {
        cout << -1;
        return 0;
    }
    else
    {
        for (int i = 1; i < 1024; i++)
        {
            string t = "";
            for (int j = 9; j >= 0; j--)
            {
                if (i & (1 << j))
                {
                    t += (char)(j + 48);
                }
            }
            v.push_back(strtoll(t.c_str(), NULL, 10));
        }
    }
    sort(v.begin(), v.end());
    cout << v[n];
    return 0;
}