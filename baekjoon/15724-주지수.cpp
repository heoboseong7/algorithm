#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int p[1050][1050];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m;
  cin >> n >> m;

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      cin >> p[i][j];
    }
  }

  return 0;
}
