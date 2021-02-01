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

class UnionFind {
  private:
     vi p, rank;
  public:
    UnionFind(int N) {
      rank.assign(N, 0);
      p.assign(N, 0);
      for(int i = 0; i < N; i++) {
        p[i] = i;
      }
    }
    int findSet(int i) {
      return (p[i] == i ? i : p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
      if(!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
          p[y] = x;
        }
        else {
          p[x] = y;
          if (rank[x] == rank[y])
            rank[y]++;
        }
      }
    }
};

vector<pair<int, ii>> v;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int m, n, BW, CW;
  int start, end, width;
  cin >> m >> n >> BW >> CW;
  for(int i = 0; i < n; i++) {
    cin >> start >> end >> width;
    v.push_back(make_pair(width, make_pair(start, end)));
  }
  sort(v.begin(), v.end(), greater<pair<int, ii>>());

  int i = 0;

  UnionFind UF(m);
  while(!UF.isSameSet(BW, CW)) {
    UF.unionSet(v[i].se.fi, v[i].se.se);
    i++;
  }
  cout << v[i - 1].fi;
  return 0;
}
