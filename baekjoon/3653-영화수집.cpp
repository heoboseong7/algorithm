// 이진 인덱스 트리
// "동적"인 누적 빈도수 테이블 구현에 쓰임.
#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & -(S)) //켜져있는 가장 오른쪽 비트

typedef vector<int> vi;

void update(vi &ft, int idx, int v) {
  for(; idx < ft.size(); idx += LSOne(idx)) {
    ft[idx] += v;
  }
}

int query(vi &ft, int i) {
  int ans = 0;
  for(; i > 0; i -= LSOne(i)) ans += ft[i];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    vi ft(200001), f(200001);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
      f[i] = n - i + 1;
      update(ft, i, 1);
    }
    int next = n + 1;
    while(m--) {
      int num;
      cin >> num;
      cout << query(ft, 200001) - query(ft, f[num]) << ' ';
      update(ft, f[num], -1);
      f[num] = next++;
      update(ft, f[num], 1);
    }
    cout << '\n';
  }
  return 0;
}
