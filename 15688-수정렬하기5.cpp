#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int cnt[2000001];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, input;
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> input;
    cnt[input + 1000000]++;
  }
  for(int i = 0; i < 2000001; i++)
    for(int j = 0; j < cnt[i]; j++)
      cout << i - 1000000 << '\n';  
  return 0;
}
