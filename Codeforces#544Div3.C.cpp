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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  vi v;
  vi v2;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int input;
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end());

  for(int i = 1; i < v.size(); i++)
    v2.push_back(v[i] - v[i - 1]);

  int fr = 0, ed = 0, cnt = 0, sum = 0;
  int fri = 0;
  for(int i = 0; i < v2.size(); i++) {
    sum += v2[i];
    if(sum > 5) {
      sum -= v2[fr];
      fr++;
      ed = i;
    }
    else {
      cnt++;
      ed = i;
    }
  }
  cout << cnt + 1;
  return 0;
}
