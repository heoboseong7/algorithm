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

char a[1001][1001];
bool check[1001][1001];

void travel(int i, int j) {
  check[i][j] = true;
  if(!check[i - 1][j] && a[i - 1][j] == '0')
    travel(i - 1, j);
  if(!check[i + 1][j] && a[i + 1][j] == '0')
    travel(i + 1, j);
  if(!check[i][j - 1] && a[i][j - 1] == '0')
    travel(i, j - 1);
  if(!check[i][j + 1] && a[i][j + 1] == '0')
    travel(i, j + 1);
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int m, n;
  cin >> m >> n;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
      cin >> a[i][j];
    }

  for(int i = 0; i < n; i++) {
    if(!check[0][i])
      travel(0, i);
  }
  for(int i = 0; i < n; i++) {
    if(check[m - 1][i]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
