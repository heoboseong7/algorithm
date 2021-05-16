#include <bits/stdc++.h>

using namespace std;

int n, ans = 987654321;
char m[100][100];
bool check[100][100];
vector<pair<int, int>> v1, v2;
void search(int r1, int c1, int r2, int c2) {
  if(m[r1][c1] == '1') return;
  check[r1][c1] = true;
  v1.push_back(make_pair(r1, c1));
  if(!check[r1 + 1][c1] && r1 < n) search(r1 + 1, c1, r2, c2);
  if(!check[r1 - 1][c1] &&r1 > 1) search(r1 - 1, c1, r2, c2);
  if(!check[r1][c1 + 1] &&c1 < n) search(r1, c1 + 1, r2, c2);
  if(!check[r1][c1 - 1] &&c1 > 1) search(r1, c1 - 1, r2, c2);
}

void search(int r, int c) {
  if(m[r][c] == '1') return;
  check[r][c] = true;
  v2.push_back(make_pair(r, c));
  if(!check[r + 1][c] && r < n) search(r + 1, c);
  if(!check[r - 1][c] && r > 1) search(r - 1, c);
  if(!check[r][c + 1] && c < n) search(r, c + 1);
  if(!check[r][c - 1] && c > 1) search(r, c - 1);
}
int main() {

  int r1, c1, r2, c2;
  cin >> n >> r1 >> c1 >> r2 >> c2;
  getchar();

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      scanf("%c", &m[i][j]);
    }
    getchar();
  }
    //printf("\n");
/*  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      printf("%c", m[i][j]);
    }
    printf("\n");
  }*/
  search(r1, c1, r2, c2);
  if(check[r2][c2]) {
    cout << 0;
    return 0;
  }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      check[i][j] = false;
    }
  }
  search(r2, c2);
  for(int i = 0; i < v1.size(); i++) {
    for(int j = 0; j < v2.size(); j++) {
      ans = min(ans, (int)pow(v1[i].first - v2[j].first, 2) + (int)pow(v1[i].second - v2[j].second, 2));
    }
  }
  /*for(int i = 0; i < v2.size(); i++) {
      cout << v2[i].first << ' ' << v2[i].second << '\n';
  }*/
  cout << ans;
  return 0;
}
