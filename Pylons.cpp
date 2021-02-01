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

bool check[21][21];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {

    int R, C;
    cin >> R >> C;
    bool ended = false;
    for(int r = 1; r <= R; r++) {
      for(int c = 1; c <= C; c++) {
        for(int i = 0; i < 21; i++) {
          for(int j = 0; j < 21; j++) {
            check[i][j] = false;
          }
        }
        int cnt = 1;
        check[r][c] = true;
        vii move;
        move.push_back(make_pair(r, c));
        bool moved = false;
        while(1) {
          moved = false;
            for(int i = 1; i <= R; i++) {
                for(int j = 1; j <= C; j++) {
                    if(i != r && j != c && r - c != i - j && i + j != r + c && !check[i][j]) {
                        move.push_back(make_pair(i, j));
                        cnt++;
                        check[i][j] = true;
                        r = i; c = j;
                        moved = true;
                        break;
                      }
                    }
                    if(moved) break;
                  }
                  if(!moved || cnt == R * C) break;
                }
                if(cnt == R * C) {
                  cout << "Case" << ' ' << "#" << t + 1 << ": " << "POSSIBLE" << '\n';
                  for(int i = 0; i < move.size(); i++)
                  cout << move[i].fi << ' ' << move[i].se << '\n';
                  ended = true;
                  break;
                }
                else if(!ended && r == R && c == C)
                  cout << "Case" << ' ' << "#" << t + 1 << ": " << "IMPOSSIBLE" << '\n';
              }
              if(ended) break;
            }
          }
  return 0;
}
