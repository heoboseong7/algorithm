#include <bits/stdc++.h>

using namespace std;
/*
이미 계산한지 여부를 확인하고 계산해놓은 값이면 그 값을 활용하기 위해 map이용.
-> 배열로 표현하기에는 숫자가 너무 크기때문에.
*/
map<long long int, long long int> dp;
long long int n, p, q;
long long int func(long long int i) {
  if(i == 0) {
    return 1;
  }
  else if(dp[i]) {
    return dp[i];
  }
  else {
    return dp[i] = func(i / p) + func(i / q);
  }
}

int main() {
  scanf("%lld %lld %lld", &n, &p, &q);
  printf("%lld", func(n));
  return 0;
}
