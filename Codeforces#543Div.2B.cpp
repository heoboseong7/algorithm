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

int cnt[300100];
int ans;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  int a[10001];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];

  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++) {
      cnt[a[i] + a[j]]++;
    }
  for(int i = 0; i < 300000; i++)
    ans = MAX(ans, cnt[i]);

  cout << ans;
  return 0;
}
