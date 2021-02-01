#include <bits/stdc++.h>

using namespace std;

int n;
int _map[101][101];
bool isvisit[101][101];

void move(int i, int j) {
  isvisit[i][j] = true;
  if(_map[i][j] == -1) {
    return;
  }
  if(i + _map[i][j] < n && !isvisit[i + _map[i][j]][j]) {
    move(i + _map[i][j], j);
  }
  if(j + _map[i][j] < n && !isvisit[i][j + _map[i][j]]) {
    move(i, j + _map[i][j]);
  }
}

int main() {
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> _map[i][j];
    }
  }

  move(0, 0);

  if(isvisit[n - 1][n - 1]) {
    cout << "HaruHaru";
  }
  else {
    cout << "Hing";
  }
  return 0;
}
