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
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) {
    int n;
    int ans = 0;
    cin >> n;
    string s[1001], s2[1001];
    bool check[1001], check2[1001];
    for(int i = 0; i < n; i++) {
      cin >> s[i];
      check[i] = false;
      check2[i] = false;
    }
    for(int i = 0; i < n; i++) {
      for(int j = 1; j <= 50; j++) {
        if(j <= s[i].size())
          s2[j - 1] += s[i][s[i].size() - j];
        else
          s2[j - 1] += ' ';
      }
    }
  //  for(int i = 0; i < 50; i++)
  //    cout << s2[i] << '\n';
    for(int i = 50; i >= 0; i--) {
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
          if(j == k) continue;
          if(s2[i][j] == s2[i][k] && s2[i][j] != ' ' && !check[i] && !check2[j] && !check2[k]) {
            for(int a = i; a >= 0; a--) {
              if(s2[a][j] != s2[a][k]) break;
              else if(a == 0) {
                check[i] = true;
                check2[j] = true; check2[k] = true;
                ans += 2;
              }
            }
          }
        }
      }
    }
    cout << "Case" << ' ' << "#" << t << ": " << ans << '\n';
  }

  return 0;
}
