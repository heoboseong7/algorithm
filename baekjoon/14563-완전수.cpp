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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n / 2; i++) {
      if(n % i == 0) sum += i;
    }
    if(n == sum) cout << "Perfect" << '\n';
    else if(n > sum) cout << "Deficient" << '\n';
    else cout << "Abundant" << '\n';
  }
  return 0;
}
