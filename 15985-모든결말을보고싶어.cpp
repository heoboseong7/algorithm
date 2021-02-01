#include <bits/stdc++.h>
using namespace std;
#define FOR(var, start, to) for(int var = start; i < to; i++)
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, k;
int parent[10001];
vi child[10001];
int _time[10001];
vi leaf;
int main() {
  cin >> n >> k;

  FOR(i, 0, n - 1) {
    int a, b;
    scanf("%d %d", &a, &b);
    parent[b] = a;
    child[a].push_back(b);

  }

  FOR(i, 0, n) {
    if (child[i].empty()) {
      _time[i] = 0;
      leaf.push_back(i);
    }
  }

  FOR(i, 0, leaf.size()) {
    int temp = i;
    int a = 1;
    while(parent[temp] != 0) {
      _time[parent[temp]] += a;
      temp = parent[temp];
      a++;
    }
  }

  return 0;
}
