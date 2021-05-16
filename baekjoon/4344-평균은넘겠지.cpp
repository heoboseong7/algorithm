#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, count = 0;
    double sum = 0;
    vector<int> v;
    scanf("%d", &n);
    v.assign(n, 0);
    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
      sum += v[i];
    }
    for(int i = 0; i < n; i++) {
      if(v[i] > sum / n)
        count++;
    }
    printf("%.3lf%%\n", round(((double)count / n) * 100 * 1000) / 1000);
  }
  return 0;
}
