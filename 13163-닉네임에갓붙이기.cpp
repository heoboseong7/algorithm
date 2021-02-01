#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  getchar();
  for(int i = 0; i < n; i++) {
    char name[10001];
      int j = 0; bool check = false; int s;
    while(1) {
      scanf("%c", name + j);

      if(name[j] == '\n') {
        break;
      }
      else if(name[j] == ' ' && !check) {
        check = true;
        s = j;
      }
      j++;
    }
    printf("god");
    for(; s < j; s++) {
      if(name[s] != ' ')
        printf("%c", name[s]);
    }
    printf("\n");
  }

  return 0;
}
