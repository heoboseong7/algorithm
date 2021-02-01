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

int top[10001];
int n, m, k, ans = 0;
int p[10001];
int s[10001];
int c[10001];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m >> k;
  for(int i = 1; i <= n; i++)
    cin >> p[i];
  for(int i = 1; i <= n; i++) {
    cin >> s[i];
    top[s[i]] = MAX(top[s[i]], p[i]);
  }
  for(int i = 1; i <= k; i++) {
    cin >> c[i];
    if(top[s[c[i]]] != p[c[i]])
      ans++;
  }
  cout << ans;
  return 0;
}
