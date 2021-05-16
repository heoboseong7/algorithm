#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
#define ll long long;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int a, b, n, w, cnt = 0;
  vii ans;
  cin >> a >> b >> n >> w;

  for(int i = 1; i < n; i++) {
    if(a * i + b * (n - i) == w) {
      cnt++;
      ans.push_back(make_pair(i, n - i));
    }
  }

  if(ans.size() == 1) cout << ans[0].first << ' ' << ans[0].second;
  else cout << -1;
  return 0;
}
