#include <bits/stdc++.h>

using namespace std;

bool matrix[50][50];
int n, m;

void flip(int x, int y)
{
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            matrix[i][j] = !matrix[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<string> vs1;
    vector<string> vs2;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        string ts;
        cin >> ts;
        vs1.push_back(ts);
    }
    for (int i = 0; i < n; i++)
    {
        string ts;
        cin >> ts;
        vs2.push_back(ts);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vs1[i][j] != vs2[i][j])
            {
                matrix[i][j] = true;
            }
        }
    }

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == n - 3 && j > m - 3)
                continue;
            if (matrix[i][j])
            {
                flip(i, j);
                ans++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j])
            {
                ans = -1;
            }
        }
    }
    cout << ans;
    return 0;
}