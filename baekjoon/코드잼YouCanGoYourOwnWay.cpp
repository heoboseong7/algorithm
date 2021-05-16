#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
#define ABS(a) ((a < 0) ? -a : a)
#define fi first
#define se second
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  for(int i = 0; i < T; i++) {
    int n;
    cin >> n;
    char p[100001];
    memset(p, '\0', 100001);
    //getchar();
    cin >> p;
    cout << "Case #" << i + 1 << ": ";
    for(int j = 0; j < strlen(p); j++) {
      if(p[j] == 'S') cout << 'E';
      else cout << 'S';
    }
    cout << '\n';
  }

  return 0;
}
