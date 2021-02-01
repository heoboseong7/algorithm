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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  vector<ll> v;
  ll n, input, dis = INF, cnt = 0;
  cin >> n;
  FOR(i, 0, n) {
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end());
  for(int i = 1; i < n; i++) {
    if(dis == v[i] - v[i - 1]) {
      cnt++;
    }
    else if(dis > v[i] - v[i - 1]) {
      cnt = 1;
      dis = v[i] - v[i - 1];
    }
  }

  cout << dis << ' ' << cnt;
  return 0;
}
