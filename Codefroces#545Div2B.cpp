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
int cnt[4];
int main() {
  //ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  char cs[100001], ca[100001];
  int c[10001];
  int a[10001];
  ii p = {0, 0};
  vi v[4];
  int ans[4];
  cin >> cs >> ca;
  for(int i = 0; i < n; i++)
    if(cs[i] == '1') c[i] = 1;
    else c[i] = 0;
  for(int i = 0; i < n; i++)
    if(ca[i] == '1') a[i] = 1;
    else a[i] = 0;
  for(int i = 0; i < n; i++) {
    cnt[c[i] * 2 + a[i]]++;
    v[c[i] * 2 + a[i]].push_back(i);
  }
// 0 00 1 01 2 10 3 11
/*  for(int i = 0; i < cnt[3]; i++) {
    if(cnt[1] > cnt[2]) { cnt[2]++; p.se++; }
    else cnt[1]++;
  }
  for(int i = 0; i < cnt[0]; i++) {
    if(cnt[1] > cnt[2])  cnt[1]--;
    else { cnt[2]--; p.fi++; }
  }
  */
  while(cnt[1] && cnt[2]) {
    cnt[1]--;
    ans[2]++;
    cnt[2]--;
  }
  while(cnt[1] && cnt[3]) {
    cnt[1]--;
    cnt[3]--;
    ans[3]++;
  }
  while(cnt[2] && cnt[3]) {
    cnt[2]--;
    cnt[3]--;
  }
  while(cnt[1] && cnt[0]) {
    ans[1]++;
    cnt[1]--;
    cnt[0]--;
  }
  while(cnt[2] && cnt[0]) {
    ans[0]++;
    cnt[2]--;
    cnt[0]--;
  }
  while(cnt[0] >= 2 && cnt[0] % 2 == 0) {
    ans[0]++;
    cnt[0] -= 2;
  }
  while(cnt[3] >= 2 && cnt[0] % 2 == 0) {
    ans[3]++;
    cnt[3] -= 2;
  }
  if(cnt[0] || cnt[1] || cnt[2] || cnt[3]) {
    cout << cnt[0] << cnt[1] << cnt[2] << cnt[3];
    cout << -1;
    return 0;
  }

  for(int i = 0; i < ans[0]; i++)
    cout << v[0][i] + 1 << ' ';
  for(int i = 0 ; i < ans[3]; i++)
    cout << v[3][i] + 1 << ' ';
  for(int i = 0; i < ans[2]; i++)
    cout << v[2][i] + 1 << ' ';
  for(int i = 0; i < ans[1]; i++)
    cout << v[1][i] + 1 << ' ';
  return 0;
}
