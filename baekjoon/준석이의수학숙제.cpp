#include <bits/stdc++.h>

using namespace std;

long long int T, n;

long long int sum(int i) {
  return i * (n / i) * (n / i + 1) / 2;
}

long long int ans[10000001];

int main() {
  //int x = 9999001;
  //ofstream input("large.in");
  //ofstream output("small.out");
  scanf("%d", &T);
  //input << T << '\n';
  //clock_t t = clock();
  //printf("%d", sizeof(ans));
  for(int i = 1; i <= 10000000; i++)
    if(i % 3 == 0 || i % 7 == 0)
      ans[i] = ans[i - 1] + i;
    else
      ans[i] = ans[i - 1];
  while(T--) {
    //n = x++;
    scanf("%d", &n);
    //printf("%d\n", x--);
    /*
    for(int i = 3; i <= n; i += 3)
      ans += i;
    for(int i = 7; i <= n; i += 7)
      if(i % 3 != 0) ans += i;
    printf("%lld\n", ans);
    */
    printf("%lld\n", ans[n]);
    //printf("%lld %lld %lld %lld\n", sum(3) , sum(7) , sum(21), sum(3) + sum(7) - sum(21));
    //input << n << '\n';
    //output << sum(3) + sum(7) - sum(21) <<'\n';
  }
  //t = clock() - t;
  //printf("%f\n", (float)t / CLOCKS_PER_SEC);
  return 0;
}
