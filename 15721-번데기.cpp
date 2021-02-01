#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int a, t, input, ans;
int p[202000];
int cnt;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> a >> t >> input;
  int n = 0;
  for(int i = 2; n < 3 * t; i++) {
    p[n] = 1; p[n + 1] = 2; p[n + 2] = 1; p[n + 3] = 2;
    n += 4;
    for(int j = 0; j < i; j++) {
      p[n + j] = 1;
    }
    n += i;
    for(int j = 0; j < i; j++) {
      p[n + j] = 2;
    }
    n += i;
  }

  for(int i = 0; i < 3 * t; i++) {
    if(p[i] == input + 1) cnt++;
    if(cnt == t) {
      ans = i % a;
      break;
    }
  }
  cout << ans;
  return 0;
}
