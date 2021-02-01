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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s1, s2;
  cin >> s1;
  cin >> s2;
  int a, b, ans;
  a = ((int)s1[0] - 48) * 600 + ((int)s1[1] - 48) * 60 + ((int)s1[3] - 48) * 10 + ((int)s1[4] - 48);
  b = ((int)s2[0] - 48) * 600 + ((int)s2[1] - 48) * 60 + ((int)s2[3] - 48) * 10 + ((int)s2[4] - 48);
  ans = (a + b) / 2;

  cout << ans / 600;
  ans %= 600;
  cout << ans / 60;
  ans %= 60;
  cout << ':';
  if(ans < 10)
    cout << 0 << ans;
  else
    cout << ans;
  return 0;
}
