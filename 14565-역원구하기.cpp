#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
#define ABS(a) a < 0 ? -a : a
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

ll gcd(ll a, ll b)
{
  ll c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
    return a;
}

ll xgcd(ll a, ll b) {
  vector<ll> s, t, r, q;
  s = {1, 0}; t = {0, 1}; r = {a, b};
  while(1) {
    q.push_back(r[r.size() - 2] / r[r.size() - 1]);
    r.push_back(r[r.size() - 2] % r[r.size() - 1]);
    if(r.back() == 0) break;
    s.push_back(s[s.size() - 2] - s.back() * q.back());
    t.push_back(t[t.size() - 2] - t.back() * q.back());
  }
  return t.back();
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n, a, XGCD;
  cin >> n >> a;
  cout << n - a << ' ';
  if(gcd(n, a) == 1) {
    XGCD = xgcd(n, a);
    XGCD = XGCD < 0 ? XGCD + n : XGCD;
    cout << XGCD;
  }
  else
    cout << -1;
  return 0;
}
