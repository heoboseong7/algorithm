#include <bits/stdc++.h>
using namespace std;
#define MIN(a, b) ((a < b) ? a : b)
#define MIN3(a, b, c) MIN(a, MIN(b, c))

int main() {
  int a[5];
  for(int i = 0; i < 5; i++)
    cin >> a[i];

  cout << MIN3(a[0], a[1], a[2]) + MIN(a[3], a[4]) - 50;
  return 0;
}
