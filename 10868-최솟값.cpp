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

vi st;
vi a;
int arr[100001];
int n, m;

int left(int p) { return  p << 1; }
int right(int p) { return (p << 1) + 1; }

void build(int p, int L, int R) {
  if(L == R)
    st[p] = L;
  else {
    build(left(p), L, (L + R) / 2);
    build(right(p), (L + R) / 2 + 1, R);
    int p1 = st[left(p)], p2 = st[right(p)];
    st[p] = a[p1] < a[p2] ? p1 : p2;
  }
}

int rmq(int p, int L, int R, int i, int j) {
  if(i > R || j < L)
    return -1;
  if(i <= L && j >= R)
    return st[p];
  int p1 = rmq(left(p), L, (L + R) / 2, i, j);
  int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
  if(p1 == -1) return p2;
  if(p2 == -1) return p1;
  return a[p1] < a[p2] ? p1 : p2;
}

int rmq(int i, int j) { return rmq(1, 0, n - 1, i, j); }

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n >> m;
  st.assign(4 * n, 0);
  st[0] = -1;
  a.assign(n, 0);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  build(1, 0, n -1);
  while(m--) {
    int from, to;
    cin >> from >> to;
    cout << a[rmq(from - 1, to - 1)] << '\n';
  }
  return 0;
}
