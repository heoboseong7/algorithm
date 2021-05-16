#include <bits/stdc++.h>

using namespace std;

vector<int> prog;
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
    if (here <= n)
    {
        prog.push_back(here);
        rec(here + 1);
        prog.pop_back();
        rec(here + 1);
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