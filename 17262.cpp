#include <bits/stdc++.h>

using namespace std;
int s, e, ts, te;
int main() {

  int n;
  scanf("%d", &n);
  while(n--) {
    scanf("%d %d", &ts, &te);
    s = max(s, ts);
    if(!e)
      e = te;
    else {
      e = min(e, te);
    }
  }
  if(s - e > 0)
    printf("%d", s - e);
  else
    printf("0");

  return 0;
}
