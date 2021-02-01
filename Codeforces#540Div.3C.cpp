#include <bits/stdc++.h>

using namespace std;

int n;
int input;
int matrix[30][30];
int center = 0, mul2 = 0;
vector<int> v1, v2;
bool exist[10001];
int cnt[10001];
bool ans = true;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> input;
      exist[input] = true;
      cnt[input]++;
    }
  }
  if(n % 2 == 0) {
    for(int i = 0; i < 1001; i++) {
      if(exist[i] && cnt[i] % 4 != 0) {
        ans = false; break;
      }
    }
  }
  else {
    for(int i = 1; i < 1001; i++) {
      if(exist[i] && cnt[i] % 4 != 0) {
        if(cnt[i] % 2 == 0) {
          mul2++;
          if(mul2 >= n) {
            ans = false; break;
          }
        }
        else {
          if(center == 0) {
            center = i;
            i--;
            cnt[i]--;
          }
          else {
            ans = false; break;
          }
        }
      }
    }
  }

  if(ans || n == 1) {
    cout << "YES\n";
    if(n % 2 == 0) {
    vector<int> v;
    for(int i = 1; i < 1001; i++) {
      if(cnt[i] > 0) {
        for(int j = 0; j < cnt[i] / 4; j++) {
          v.push_back(i);
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(matrix[i][j] == 0) {
          matrix[i][j] = v.back();
          matrix[n - 1 - i][j] = v.back();
          matrix[i][n - 1 - j] = v.back();
          matrix[n - 1 - i][n - 1 - j] = v.back();
          v.pop_back();
        }
      }
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        cout << matrix[i][j] << ' ';
      }
      cout << '\n';
    }
  }
  else {

  }
  }
  else {
    cout <<"NO\n";
  }
  return 0;
}
