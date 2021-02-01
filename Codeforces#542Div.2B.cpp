#include <bits/stdc++.h>

using namespace std;

int shop[101000][2];
bool check[101000][2];
long long int ans = 0;
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, input;
  cin >> n;
  for(int i = 0; i < 2 * n; i++) {
      cin >> input;
      if(shop[input][0] == 0) shop[input][0] = i;
      else shop[input][1] = i;
  }

  int now[2] = {shop[1][0], shop[1][1]};
  int tier = 1;
  ans += shop[1][0] + shop[1][1];

  while(tier < n) {
    if(abs(shop[tier + 1][0] - now[0]) + abs(shop[tier + 1][1] - now[1]) >=
       abs(shop[tier + 1][1] - now[0]) + abs(shop[tier + 1][0] - now[1])) {
      ans += abs(shop[tier + 1][1] - now[0]) + abs(shop[tier + 1][0] - now[1]);
      now[0] = shop[tier + 1][1]; now[1] = shop[tier + 1][0];
    }
    else {
      ans += abs(shop[tier + 1][0] - now[0]) + abs(shop[tier + 1][1] - now[1]);
      now[0] = shop[tier + 1][0]; now[1] = shop[tier + 1][1];
    }
    tier++;
  }

  cout << ans;

  return 0;
}
