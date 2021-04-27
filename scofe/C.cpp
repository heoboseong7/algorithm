#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for (int var = start; var < to; var++)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
#define ABS(a) ((a < 0) ? -a : a)
#define fi first
#define se second
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n;
string room[51];
int ans[51];
int total;
void test(int _size, int x, int y)
{
    for (int i = x; i < x + _size; i++)
    {
        for (int j = y; j < y + _size; j++)
        {
            if (room[i][j] == '0')
                return;
        }
    }
    ans[_size]++;
    total++;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> room[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (room[j][k] == '1')
                {
                    if (j + i < n && k + i < n)
                    {
                        test(i + 1, j, k);
                    }
                }
            }
        }
    }
    cout << "total: " << total << '\n';
    for (int i = 0; i < n; i++)
    {
        if (ans[i + 1] > 0)
            cout << "size[" << i + 1 << "]: " << ans[i + 1] << '\n';
    }
    return 0;
}
