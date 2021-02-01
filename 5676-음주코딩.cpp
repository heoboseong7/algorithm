#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S)) //켜져있는 가장 오른쪽 비트
#define minus first
#define zero second

typedef vector<int> vi;
int n, k;
int trans(int v) {
  if(v > 0) return 1;
  else if(v < 0) return -1;
  else return 0;
}

void update(vector<pair<int, int>> &ft, int idx, pair<int, int> v) {
  printf("%d", ft.size());
  for(; idx < n + 1; idx += LSOne(idx)) {
    ft[idx].minus += v.minus;
    ft[idx].zero += v.zero;
  }
}

pair<int, int> query(vector<pair<int, int>> &ft, int idx) {
  pair<int, int> ans = {0, 0};
  for(; idx > 0; idx -= LSOne(idx)) {
    ans.minus += ft[idx].minus;
    ans.zero += ft[idx].zero;
  }
  return ans;
}

char query(vector<pair<int, int>> &ft, int i, int j) {
  pair<int, int> a = query(ft, i - 1), b = query(ft, j);
  if(b.zero - a.zero > 0) return '0';
  else if(((b.minus - a.minus) % 2) == 1) return '-';
  else return '+';
}
int main() {

  while(scanf("%d %d", &n ,&k) != EOF) {
    vi v(200001);
    vector<pair<int, int>> ft;
    ft.assign(200001, make_pair(0, 0));
    for(int i = 1; i <= n; i++) {
      scanf("%d", &v[i]);
      v[i] = trans(v[i]);
      if(v[i] == 0) update(ft, i, make_pair(0, 1));
      else if(v[i] < 0) update(ft, i, make_pair(1, 0));
    }
    while(k--) {
      char c;
      int a, b;
      getchar();
      scanf("%c %d %d", &c, &a, &b);
      if(c == 'C') {
        if(v[a] > 0 && b < 0) {
          update(ft, a, make_pair(1, 0));
        }
        if(v[a] < 0 && b > 0) {
          update(ft, a, make_pair(-1, 0));
        }
        if(v[a] > 0 && b == 0) {
          update(ft, a, make_pair(0, 1));
        }
        if(v[a] < 0 && b == 0) {
          update(ft, a, make_pair(-1, 1));
        }
        if(v[a] == 0 && b > 0) {
          update(ft, a, make_pair(0, -1));
        }
        if(v[a] == 0 && b < 0) {
          update(ft, a, make_pair(1, -1));
        }

        v[a] = trans(b);
      }
      else {
        printf("%c", query(ft, a, b));
      }
    }
    printf("\n");
  }
  return 0;
}
