#include <bits/stdc++.h>

using namespace std;

long long int combination(int n, int r) {
  long long int comret[100][100];
  for(int i = 0; i <= n; i++) {
    for(int j = 0; j <= i; j++) {
      if(!i || !j) comret[i][j]  = 1;
      else comret[i][j] = comret[i - 1][j - 1] + comret[i - 1][j];
    }
  }
  return comret[n][r];
}
