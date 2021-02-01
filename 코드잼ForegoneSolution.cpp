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
  int T, t = 1;
  char S[1001], A[1001], B[1001];
  cin >> T;
  while(T--) {
    memset(S, '\0', 1001);
    memset(A, '\0', 1001);
    memset(B, '\0', 1001);
    cin >> S;
    int j = 0;
    for(int i = 0; i < strlen(S); i++) {
      if(S[i] == '4') {
        A[i] = '2';
        B[j++] = '2';
      }
      else {
        A[i] = S[i];
        if(j > 0) B[j++] = '0';
      }
    }
    cout << "Case #" << t++ << ": " << A << ' ' << B << '\n';
  }

  return 0;
}
