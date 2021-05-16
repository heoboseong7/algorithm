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
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if(x1 == x2 && y1 == y2 && r1 == r2) {
      cout << -1 << '\n';
      continue;
    }
    if((int)pow(x1 - x2, 2) + (int)pow(y1 - y2, 2) < (int)pow(r1 + r2, 2) && (int)pow(x1 - x2, 2) + (int)pow(y1 - y2, 2) > pow(r1 - r2, 2)) {
      cout << 2 << '\n';
    }
    else if((int)pow(x1 - x2, 2) + (int)pow(y1 - y2, 2) == (int)pow(r1 + r2, 2) || (int)pow(x1 - x2, 2) + (int)pow(y1 - y2, 2) == (int)pow(r1 - r2, 2)) {
      cout << 1 << '\n';
    }
    else {
      cout << 0 << '\n';
    }
  }
  return 0;
}
