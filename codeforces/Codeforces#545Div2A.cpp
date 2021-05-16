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
  int n;
  cin >> n;

  int cnt = 0, sum = 0;
  int input, bef;
  vi v;
  for(int i = 0; i < n; i++) {
    cin >> input;
    if(i == 0) bef = input;
    if(bef == input) {
      bef = input;
      cnt++;
    }
    else {
      v.push_back(cnt);
      sum += cnt;
      bef = input;
      cnt = 1;
    }
  }
  v.push_back(n - sum);
  int ans = 0;
  for(int i = 1; i < v.size(); i++) {
    ans = max(ans, min(v[i], v[i - 1]));
  }
  cout << ans * 2;
  return 0;
}
