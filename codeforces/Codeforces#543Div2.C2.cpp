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

pair<ii, bool> a[100001];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, k, m = 0, ans = 0;

  bool check[100001];
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> a[i].fi.fi;
    a[i].fi.se = a[i].fi.fi;
  }
  int i = 0;
  while(i != n) {
    int temp = min(k, n - m);
    sort(a + i, a + i + temp);
    int cnt = 0, save = a[i].fi.fi;
    //cout << temp << ' ' << i <<'\n';
    if(temp == 0) break;
    for(int j = i; j < i + temp; j++) {
      a[j].fi.fi -= save;

      if(a[j].fi.fi <= 0) {
        cnt++; m++;
      }
    }
  //  cout << '\n';
    i += cnt;
    sort(a + i, a + i + min(k, n - m));
  //  cout << round(100 * m / n) << ' ' << a[i].fi << '\n';
    for(int j = i; j < i + min(n - m, k); j++) {
    //  cout <<  a[j].se - a[j].fi << ' ';
      if(a[j].fi.se - a[j].fi.fi < round(100 * double(m) / double(n)) && a[j].fi.se - a[j].fi.fi + a[i].fi.fi >= round(100 * double(m) / double(n)))
        a[j].se = true;
    }
  }
  for(int i = 0; i < n; i++)
    if(a[i].se){
      ans++;
    }
  cout << ans;
  return 0;
}
