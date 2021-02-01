#include <bits/stdc++.h>

using namespace std;


bool *primearray;
void setprimearray(int N) {
  delete primearray;
  primearray = new bool[N + 1];
  for(int i = 2; i <= N; i++)
    primearray[i] = true;
}

void Eratos(int n) {
  for(int i = 2; i <= n; i++) {
    if(primearray[i]) {
      for(int j = i * 2; j <= n; j += i) {
        primearray[j] = false;
      }
    }
  }
}
int main() {
  int n = 100;
  setprimearray(n);
  Eratos(n);
  for(int i = 2; i <= n; i++) {
    if(primearray[i]) {
      printf("%d ", i);
    }
  }
  delete primearray;
  return 0;
}
