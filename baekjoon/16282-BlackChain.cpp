#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
#define ll long long;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

long long int maxchain(int k) {
  long long int ret = k + k + 1;
  for(int i = 0; i < k; i++) {
    ret += ret + 1;
  }
  return ret;
}
int main() {
  long long int n;
  cin >> n;

  long long int i = 1;
  while(1) {
    if(maxchain(i) >= n) break;
    else i++;
  }
  cout << i;
  return 0;
}
