#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int cnt[10001];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, input;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    cnt[input]++;
  }

  for(int i = 1; i < 10001; i++) {
    for(int j = 0; j < cnt[i]; j++)
      cout << i << '\n';
  }
  return 0;
}
