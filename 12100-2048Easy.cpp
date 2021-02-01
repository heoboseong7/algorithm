#include <bits/stdc++.h>

using namespace std;

int n;
int cnt;

vector<int> gen(int k)
{
    vector<int> ret(5);
    for (int i = 0; i < 5; i++)
    {
        ret[i] = (k & 3);
        k >>= 2;
    }
    return ret;
}

int check(vector<vector<int>> &a, vector<int> &dir)
{
    vector<vector<pair<int, bool>>> d(n, vector<pair<int, bool>>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j].first = a[i][j];
            d[i][j].second = false;
        }
    }
    // 0: down 1: up 2: left 3: right
    for (int i = 0; i < dir.size(); i++)
    {
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                d[j][k].second = false;
        bool moved = false;
        while (1)
        {
            moved = false;
            if (dir[i] == 0)
            {
                for (int j = n - 2; j >= 0; j--)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (d[j][k].first == 0)
                            continue;
                        if (d[j + 1][k].first == 0)
                        {
                            d[j + 1][k].first = d[j][k].first;
                            d[j][k].first = 0;
                            d[j + 1][k].second = d[j][k].second;
                            moved = true;
                        }
                        else if (d[j + 1][k].first == d[j][k].first)
                        {
                            if (!d[j + 1][k].second && !d[j][k].second)
                            {
                                d[j + 1][k].first *= 2;
                                d[j + 1][k].second = true;
                                d[j][k].first = 0;
                                moved = true;
                            }
                        }
                    }
                }
            }
            else if (dir[i] == 1)
            {
                for (int j = 1; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (d[j][k].first == 0)
                            continue;
                        if (d[j - 1][k].first == 0)
                        {
                            d[j - 1][k].first = d[j][k].first;
                            d[j][k].first = 0;
                            d[j - 1][k].second = d[j][k].second;
                            moved = true;
                        }
                        else if (d[j - 1][k].first == d[j][k].first)
                        {
                            if (!d[j - 1][k].second && !d[j][k].second)
                            {
                                d[j - 1][k].first *= 2;
                                d[j - 1][k].second = true;
                                d[j][k].first = 0;
                                moved = true;
                            }
                        }
                    }
                }
            }
            else if (dir[i] == 2)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = 1; k < n; k++)
                    {
                        if (d[j][k].first == 0)
                            continue;
                        if (d[j][k - 1].first == 0)
                        {
                            d[j][k - 1].first = d[j][k].first;
                            d[j][k].first = 0;
                            d[j][k - 1].second = d[j][k].second;
                            moved = true;
                        }
                        else if (d[j][k - 1].first == d[j][k].first)
                        {
                            if (!d[j][k - 1].second && !d[j][k].second)
                            {
                                d[j][k - 1].first *= 2;
                                d[j][k - 1].second = true;
                                d[j][k].first = 0;
                                moved = true;
                            }
                        }
                    }
                }
            }
            else if (dir[i] == 3)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = n - 2; k >= 0; k--)
                    {
                        if (d[j][k].first == 0)
                            continue;
                        if (d[j][k + 1].first == 0)
                        {
                            d[j][k + 1].first = d[j][k].first;
                            d[j][k].first = 0;
                            d[j][k + 1].second = d[j][k].second;
                            moved = true;
                        }
                        else if (d[j][k + 1].first == d[j][k].first)
                        {
                            if (!d[j][k + 1].second && !d[j][k].second)
                            {
                                d[j][k + 1].first *= 2;
                                d[j][k + 1].second = true;
                                d[j][k].first = 0;
                                moved = true;
                            }
                        }
                    }
                }
            }
            if (!moved)
                break;
        }
    }
    int ret = -123;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ret = max(ret, d[i][j].first);
        }
    }
    return ret;
}
int main()
{
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < (1 << 10); i++)
    {
        vector<int> dir = gen(i);
        ans = max(ans, check(v, dir));
    }
    cout << ans;
    return 0;
}