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

int cnt[200100];
int ans;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, k, input;
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> input;
    cnt[input % k]++;
  }
  ans += cnt[0] / 2;
  for(int i = 1; i <= k / 2; i++) {
    if(i != k - i) {
      ans += MIN(cnt[i], cnt[k - i]);
      int temp;
    }
    else
      ans += cnt[i] / 2;
  }
  cout << ans * 2;
  return 0;
}
