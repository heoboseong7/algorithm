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

int ans = INF;
void func(int a, int b, int n) {
  if(a == b) {
    ans = MIN(ans, n);
  }
  else {
    if(a + a <= b + 3) {
      func(a + a, b + 3, n + 1);
    }
    if(a + 1 <= b) {
      func(a + 1, b, n + 1);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int c;
  cin >> c;
  while(c--) {
    int s, t;
    cin >> s >> t;
    ans = INF;
    func(s, t, 0);
    cout << ans << '\n';
  }
  return 0;
}
