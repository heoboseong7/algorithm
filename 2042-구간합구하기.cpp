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
typedef vector<ll> vll;

class SegmentTree { // the OOP Segment Tree implementation, like Heap array
private:
  vll st, A; // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return  p<<1; }      // same as binary heap operations
  int right(int p) { return (p<<1) + 1; }

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R)                            // as L == R, either one is fine
      st[p] = A[L];                                         // store the index
    else {                                // recursively compute the values
      build(left(p) , L          , (L+R)/2);
      build(right(p), (L+R)/2 + 1, R      );
      ll p1 = st[left(p)], p2 = st[right(p)];
      st[p] = p1 + p2;
  } }

  ll sum(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return -1; // current segment outside query range
    if (L >= i && R <= j) return st[p];               // inside query range
     // compute the min position in the left and right part of the interval
    ll p1 = sum(left(p) , L        , (L+R)/2, i, j);
    ll p2 = sum(right(p), (L+R)/2+1, R      , i, j);
    if (p1 == -1) return p2;   // if we try to access segment outside query
    if (p2 == -1) return p1;                               // same as above
    return p1 + p2;
  }          // as as in build routine

  ll update(int p, int L, int R, int idx, int new_value) {
    int i = idx, j = idx;                   // for point update i = j = idx
         // if the current interval does not intersect the update interval,
    if (i > R || j < L) return st[p];         // return this st node value!
    // if the current interval is included in the update range,
    if (L == i && R == j) {
      A[i] = new_value;                      // update the underlying array
      return st[p] = A[L];                                       // this index
    }
     // compute the minimum position in the left/right part of the interval
    ll p1, p2;
    p1 = update(left(p) , L        , (L+R)/2, idx, new_value);
    p2 = update(right(p), (L+R)/2+1, R      , idx, new_value);
    // return the position where the overall minimum is
    return st[p] = p1 + p2;
  }

public:
  SegmentTree(const vll &_A) {
    A = _A; n = (int)A.size();              // copy content for local usage
    st.assign(4*n, 0);              // create large enough vector of zeroes
    build(1, 0, n-1);                                    // recursive build
  }
  ll sum(int i, int j) { return sum(1, 0, n-1, i, j); }     // overloading
  ll update(int i, int v) {                                // point update
    return update(1, 0, n-1, i, v); }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vll v;
  v.assign(n, 0);
  for(int i = 0; i < n; i++)
    cin >> v[i];
  SegmentTree st(v);
  for(int i = 0; i < m + k; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == 1) {
      st.update(b - 1, c);
    }
    else {
      cout << st.sum(b - 1, c - 1) << '\n';
    }
  }
  return 0;
}
