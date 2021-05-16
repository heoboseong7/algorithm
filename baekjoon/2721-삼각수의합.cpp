#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
#define ABS(a) a < 0 ? -a : a
#define fi first
#define se second
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

ll T(int n) {
  return n * (n + 1) / 2;
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, input, ans;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    ans = 0;
    for(int j = 1; j <= input; j++)
      ans += T(j + 1) * j;
    cout << ans << '\n';
  }
  return 0;
}
