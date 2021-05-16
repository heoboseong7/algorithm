#include <bits/stdc++.h>
using namespace std;
#define FOR(var, start, to) for(int var = start; var < to; var++)
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n;

int main() {
  cin >> n;
  cout << n - 1;
  FOR(i, 1, n) {
    printf("\n");
    printf("%d", n - 1);
    FOR(j, 0, n) {
      if (i != j)
        printf(" %d", j + 1);
    }

  }
  return 0;
}
