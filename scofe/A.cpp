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

vii s, e; // 시간:분

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        scanf("%d:%d ~ %d:%d", &a, &b, &c, &d);
        s.push_back(make_pair(a, b));
        e.push_back(make_pair(c, d));
    }

    sort(s.begin(), s.end());
    sort(e.begin(), e.end());

    //cout << s.back().first << ':' << s.back().second << " ~ " << e[0].first << ':' << e[0].second;
    if (s.back().first > e[0].first)
    {
        printf("-1");
    }
    else if (s.back().first == e[0].first && s.back().second > e[0].second)
    {
        printf("-1");
    }
    else
    {
        printf("%02d:%02d ~ %02d:%02d", s.back().first, s.back().second, e[0].first, e[0].second);
    }

    return 0;
}
