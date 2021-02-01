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

long long int combination(int n, int r) {
  long long int comret[100][100];
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= i; j++) {
      if(!i || !j) comret[i][j]  = 1;
      else comret[i][j] = comret[i - 1][j - 1] + comret[i - 1][j];
    }
  }
  return comret[n][r];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, w, e;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> w >> e;
    cout << combination(e, w) << '\n';
  }
  return 0;
}
