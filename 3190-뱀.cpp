#include <bits/stdc++.h>

using namespace std;
// 0 none 1 apple
int board[100][100];
vector<pair<int, int> > apple;
int dirr, dirc;
queue<pair<int, int> > snake;
vector<int> change;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, l;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        board[a - 1][b - 1] = 1;
    }

    for (int i = 0; i < l; i++)
    {
        int a;
        char b;
        cin >> a >> b;
        change.push_back(a);
        //vcd
    }

    return 0;
}