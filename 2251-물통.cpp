#include <bits/stdc++.h>

using namespace std;

int A, B, C;
bool check[201][201][201];
bool ans[201];
void bfs(int a, int b, int c)
{
    queue<int> aq, bq, cq;
    aq.push(a);
    bq.push(b);
    cq.push(c);
    while (!aq.empty())
    {

        a = aq.front();
        b = bq.front();
        c = cq.front();
        aq.pop();
        bq.pop();
        cq.pop();
        if (check[a][b][c])
            continue;
        check[a][b][c] = true;
        if (a == 0)
            ans[c] = true;
        aq.push(a + c > A ? A : a + c);
        bq.push(b);
        cq.push(a + c > A ? c - A + a : 0);

        aq.push(a);
        bq.push(b + c > B ? B : b + c);
        cq.push(b + c > B ? c - B + b : 0);

        aq.push(a + b > A ? A : b + a);
        bq.push(b + a > A ? b - A + a : 0);
        cq.push(c);

        aq.push(a);
        bq.push(b + c > C ? b - C + c : 0);
        cq.push(b + c > C ? C : b + c);

        aq.push(a + b > B ? a - B + b : 0);
        bq.push(a + b > B ? B : a + b);
        cq.push(c);

        aq.push(c + a > C ? a - C + c : 0);
        bq.push(b);
        cq.push(c + a > C ? C : c + a);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> B >> C;
    bfs(0, 0, C);
    for (int i = 0; i <= C; i++)
    {
        if (ans[i])
            cout << i << ' ';
    }

    return 0;
}