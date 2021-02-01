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
  int t;
  cin >> t;

  while(t--) {
    long long int a, n, ans = 1;
    vector<ll> v;
    cin >> a >> n;

    ll M = 1;
    while(1) {
      if(M > a) break;
      else M *= n;
    }
    M /= n;
    for(; M > 0; M /= n) {
      v.push_back(a / M);
      a %= M;
    }
    for(int i = 0; i < v.size() / 2; i++) {
      if(v[i] != v[v.size() - 1 - i]) {
        ans = 0;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
