#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
#define ABS(a) a < 0 ? -a : a
#define fi first
#define se second
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int gcd(int a, int b)
{
  int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
    return a;
}

vi a, b;
vii d;
int input, ans, zerocnt;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    a.push_back(input);
  }
  for(int i = 0; i < n; i++) {
    cin >> input;
    b.push_back(input);
  }
  for(int i = 0; i < n; i++) {
    if(a[i] != 0 && b[i] != 0) {
    int tempgcd = gcd(a[i], b[i]);
    d.push_back(make_pair(a[i] / tempgcd, b[i] / tempgcd));
    }
    else if(a[i] != 0 && b[i] == 0)
      d.push_back(make_pair(0,0));
    else if(a[i] == 0 && b[i] == 0)
      zerocnt++;
  }
  if(d.empty()) {
    cout << zerocnt;
    return 0;
  }
  sort(d.begin(), d.end());
  ii temp = d[0]; int tempans = 0;

  for(int i = 0; i < d.size(); i++) {
    if(d[i] == temp)
      tempans++;
    else {
      temp = d[i];
      tempans = 1;
    }
    ans = MAX(tempans, ans);
  }
  cout << ans + zerocnt;
  return 0;
}
