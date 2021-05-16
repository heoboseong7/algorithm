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
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;
int main() {
  bool check[1000001];
  vll prime;
  int n;
  ll input;
  memset(check, true, 1000001);
  for(int i = 2; i < 1000001; i++)
    for(int j = i * 2; j < 1000001; j += i)
      check[j] = false;
  for(int i = 2; i < 1000001; i++)
    if(check[i]) {
      prime.pb(i);
    }

  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    bool isNO = false;
    scanf("%lld", &input);
    for(int j = 0; j < prime.size(); j++) {
      if(input % prime[j] == 0) {
        printf("NO\n", prime[j]);
        isNO = true;
        break;
      }
    }
    if(!isNO)
      printf("YES\n");
  }

  return 0;
}
