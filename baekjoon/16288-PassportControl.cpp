#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
#define ll long long;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vi out;
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    int input;
    cin >> input;
    out.push_back(input);
  }

  for(int i = 1; i < n; i++) {
    if(out[i] < out[i - 1]) cnt++;
    else cnt = 0;
    if(cnt >= k) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
