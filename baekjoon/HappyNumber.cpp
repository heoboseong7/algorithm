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
  int n;
  cin >> n;
  int n2 = n;
  while(1) {
    int temp = n2, i = 1;
    int f = 0;
    while(temp) {
      f += pow(temp % 10, 2);
      temp /= 10;
    }
  //  cout << f << '\n';
    if(f == 1) {
      cout << "HAPPY";
      break;
    }
    if(f == 4) {
      cout << "UNHAPPY";
      break;
    }
    n2 = f;
  }
  return 0;
}
