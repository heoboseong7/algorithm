#include <stdio.h>
#define MAX_SIZE 80000

int T, n;

int ans[MAX_SIZE + 1];

int main() {
  scanf("%d", &T);
  for(int i = 1; i <= MAX_SIZE; i++)
    if(i % 3 == 0 || i % 7 == 0)
      ans[i] = ans[i - 1] + i;
    else
      ans[i] = ans[i - 1];
  while(T--) {
    scanf("%d", &n);
    printf("%d\n", ans[n]);
  }
  return 0;
}
