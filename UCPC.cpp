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

char a[1001];
bool check[4];

int main() {
  gets(a);

  for(int i = 0; i < strlen(a); i++) {
    if(a[i] == 'U') check[0] = true;
    if(a[i] == 'C' && check[0]) check[1] = true;
    if(a[i] == 'P' && check[1]) check[2] = true;
    if(a[i] == 'C' && check[2]) check[3] = true;
  }
  if(check[0] && check[1] && check[2] && check[3])
    cout << "I love UCPC";
  else
    cout << "I hate UCPC";
  return 0;
}
