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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k, p, n;
    ll ans;
    cin >> k >> p >> n;
    ans = k;
    for (int i = 0; i < n; i++)
    {
        ans = ans * p;
        ans %= 1000000007;
    }
    cout << ans;
    return 0;
}
