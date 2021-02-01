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
  int n, input;
  cin >> n;
  vi v;
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end());
  int index = 0, index2 = 0;
  for(int i = 0; i <= v.back(); i++) {
    while(i > v[index]) index++;
    while(i >= v[index2] && index2 < n) index2++;
    //cout << index2;
    if(n - index >= i && (n - i == index2 || n - i == index)) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
