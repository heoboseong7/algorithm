#include <bits/stdc++.h>

using namespace std;

vector<int> prog;
bool check[10];
int n, m;
void rec(int here)
{
    if (prog.size() == m)
    {
        for (int i = 0; i < prog.size(); i++)
            cout << prog[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!check[i])
        {
            prog.push_back(i);
            check[i] = true;
            rec(here + 1);
            prog.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rec(1);
    return 0;
}