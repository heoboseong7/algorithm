#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
const int t = 5;
int main() {
  char a[10];
  while(1) {
    printf("input : ");
    scanf("%s", a);
    if(atoi(a) > 0 && atoi(a) < 10) {
      printf("A\n");
    }
    else {
      printf("B\n");
    }
 }

  return 0;
}
