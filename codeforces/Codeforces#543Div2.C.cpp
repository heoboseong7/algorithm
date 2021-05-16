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

int check[151];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, k, m = 0, ans = 0;

  bool flag = false;
  vi v, a;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    int input;
    cin >> input; v.push_back(input); a.push_back(input);
  }
  while(!v.empty()) {
    for(int i = 0; i < min(n - m, k); i++) {
      v[i]--;
      if(v[i] <= 0) {
        m++;
        v.erase(v.begin() + i);
        a.erase(a.begin() + i);

        flag = true;
      }
    }
    if(flag) {
      for(int i = 0; i < min(n - m, k); i++) {
        if(a[i] - v[i] < (100 * m / n) + 1)
          ans++;
      }
      flag = false;
    }
  }
  cout << ans;
  return 0;
}
