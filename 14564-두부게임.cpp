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
  int n, m, now, input;
  cin >> n >> m >> now;
  cin >> input;
  while(input != m / 2 + 1) {
    if(now + input - (m / 2 + 1) < 1)
      now = now + input - (m / 2 + 1) + n;
    else if(now + input - (m / 2 + 1) > n)
      now = now + input - (m / 2 + 1) - n;
    else
      now = now + input - (m / 2 + 1);
    cout << now << '\n';
    cin >> input;
  }
  cout << 0;
  return 0;
}
