#include <bits/stdc++.h>
using namespace std;
#define FOR(var, start, to) for(int var = start; i < (int) to; i++)
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n;
bool check[100001];
vi adj[100001];
vi length[100001];
vi path;
int robot1, robot2;
int sum, maximum;
void bfs(int start, int end) {
  check[start] = true;
  FOR(i, 0, (int) adj[start].size()) {
    if (adj[start][i] == end) {
      path.push_back(length[start][i]);
      return;
    }
    else if (!check[adj[start][i]]) {
    path.push_back(length[start][i]);
    bfs(adj[start][i], end);
    }
  }
  path.pop_back();
}
main() {
  cin >> n >> robot1 >> robot2;
  int a, b, c;
  FOR(i, 0, n - 1) {
    scanf("%d%d%d", &a, &b, &c);
    adj[a].push_back(b);
    adj[b].push_back(a);
    length[a].push_back(c);
    length[b].push_back(c);
  }

  bfs(a, b);

  FOR(i, 0, path.size()) {
    sum += path[i];
    maximum = max(path[i], maximum);
  }

  cout << sum - maximum;

  return 0;
}
