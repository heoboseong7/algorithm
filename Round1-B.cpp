#include <bits/stdc++.h>

using namespace std;

char ans[501];
char C[256][501];
bool check[256];
int A;
int maxlen = 0;

char winner(bool R, bool P, bool S) {
  if(!R && !P && !S) return '1';
  if(R && P && S) return '\0';
  else if(R) {
    if(P) return 'P';
    if(S) return 'R';
    return 'P';
  }
  else if(P) {
    if(S) return 'S';
    return 'S';
  }
  return 'R';
}
int main() {
  int T;
  scanf("%d", &T);
  for(int t = 1; t <= T; t++) {
    bool R = false, P = false, S = false;
    scanf("%d", &A);
    for(int i = 0; i < A; i++) {
      scanf("%s", C[i]);
    }
    bool isEnd = false;
    for(int i = 0; i < A; i++)
      maxlen = max((int)strlen(C[i]) , maxlen);

    for(int i = 0; i < 501; i++) {
      R = P = S = false;
      for(int j = 0; j < A; j++) {
        if(!check[j] && C[j][i % strlen(C[j])] == 'R') R = true;
        else if(!check[j] && C[j][i % strlen(C[j])] == 'P') P = true;
        else if(!check[j] && C[j][i % strlen(C[j])] == 'S') S = true;
      }
      ans[i] = winner(R, P, S);
      if(ans[i] == '\0') {
        printf("Case #%d: IMPOSSIBLE\n", t);
        isEnd = true;
        break;
      }
      else if(ans[i] == '1') {
        ans[i] = '\0';
        break;
      }
      else {
        for(int j = 0; j < A; j++) {
          if(ans[i] != C[j][i % strlen(C[j])])
            check[j] = true;
        }
      }
    }
    for(int i = 0; i < 256; i++)
      memset(C[i], '\0', 501);
    memset(check, false, 256);
    if(isEnd) {
      memset(ans, '\0', 501);
      continue;
    }
    else
      printf("Case #%d: %s\n", t, ans);
    memset(ans, '\0', 501);

  }
}
