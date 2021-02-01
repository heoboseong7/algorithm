#include <bits/stdc++.h>
using namespace std;
#define FOR(var, start, to) for(int var = start; var < to; var++)
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
// 세그먼트 트리 구간의 최대값 저장 예제
int n;
vi st;
vi arr;

int left(int p) {  return p << 1;  } // 2 * p
int right(int p) {  return (p << 1) + 1;  } // 2 * p + 1

int build(int p, int L, int R) {
  if(L == R) {
    //세그먼트 트리의 leaf값
    return st[p] = L;
  }
  else {
    build(left(p), 0, (L + R) / 2);
    build(right(p), (L + R) / 2 + 1, R);
    int p1 = st[left(p)], p2 = st[right(p)];
    //최대값 저장부분. 최소, 합 등의 다른값으로 수정
    return st[p] = max(p1, p2);
  }
}

int find(int p, int L, int R, int i, int j) {
  if(i > R || j < L) return st[0];
  if(L >= i && j <= R) return st[p];

  int p1 = find(left(p), L, (L + R) / 2, i, j);
  int p2 = find(right(p), (L + R) / 2 + 1, R, i, j);

  return max(p1, p2);
}
//전체범위에 대해 구간을 탐색하는 함수
int find(int i, int j) {  return find(1, 0, n - 1, i, j);  }


int main() {
  //충분한 메모리 할당, 0은 쓰지 않으므로 -1로 오류를 나타냄
  st.assign(4 * n, 0);
  st[0] = -1;
  return 0;
}
