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
  int n, m;
  int a, b;
  int cnt[1001];
  bool check[1001];
  vii v;
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> a >> b;
    v.push_back(make_pair(a, b));
  }
  for(int i = 0; i < 1001; i++) {
    cnt[i] = 1;
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < m; i++) {
      cnt[v[i].second] = MAX(cnt[v[i].second], cnt[v[i].first] + 1);
  }
  for(int i = 1; i <= n; i++) {
    cout << cnt[i] << ' ';
  }
  return 0;
}
