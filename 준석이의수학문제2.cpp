#include <bits/stdc++.h>

using namespace std;

int T, n;

int sum(int i) {
  return i * (n / i) * (n / i + 1) / 2;
}

string filename = "max_data";

int main() {
  int x = 10;
  ofstream input(filename + ".in");
  ofstream output(filename + ".out");
  scanf("%d", &T);
  input << T << '\n';
  while(T--) {
    n = 80000;
    //if(x > 80000) x--;
    //scanf("%d", &n);
    /*
    for(int i = 3; i <= n; i += 3)
      ans += i;
    for(int i = 7; i <= n; i += 7)
      if(i % 3 != 0) ans += i;
    printf("%d\n", ans);
    */
    printf("%d\n", sum(3) - sum(21) + sum(7) );
    input << n;
    if(T) input << ' ';
    output << sum(3) + sum(7) - sum(21) <<'\n';
  }
  input << '\n';
  return 0;
}
