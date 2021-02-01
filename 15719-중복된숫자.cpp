#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  long long int n, sum = 0, temp = 0, tempsum = 0;
  cin >> n;
  sum = (n - 1) * n / 2;
  if(n == 2) {
    sum = 1;
  }
  for(int i = 0; i < n; i++) {
    cin >> temp;
    tempsum += temp;
  }
  cout << tempsum - sum;

  return 0;
}
