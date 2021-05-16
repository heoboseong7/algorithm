#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n;
int x, y;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;

  int cnt = 0, cmp = 0;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
      if(cnt % 4 == 0)  y++;
      else if(cnt % 4 == 1) x++;
      else if(cnt % 4 == 2) y--;
      else x--;
      cmp++;
      if(cmp == n) {
        cout << x << ' ' << y;
        return 0;
      }
    }
    cnt++;
    for(int j = 0; j < i; j++) {
      if(cnt % 4 == 0)  y++;
      else if(cnt % 4 == 1) x++;
      else if(cnt % 4 == 2) y--;
      else x--;
      cmp++;
      if(cmp == n) {
        cout << x << ' ' << y;
        return 0;
      }
    }
    cnt++;
  }

  return 0;
}
