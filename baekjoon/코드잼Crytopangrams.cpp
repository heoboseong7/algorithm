#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
#define ABS(a) ((a < 0) ? -a : a)
#define fi first
#define se second
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T;
  cin >> T;
  for(int t = 0; t < T; t++) {
    vi v, v2;
    set<int> s;
    map<int, char> m;
    int n, l;
    cin >> n >> l;
    while(l--) {
      int temp;
      v.pb(temp);
    }
    int prime = gcd(v[0], v[1]);
    s.insert(prime); s.insert(v[0] / prime);
    v[0] = v[0] / prime;
    v2.pb(v[0]); v2.pb(prime);
    for(int i = 1; i < v.size(); i++) {
      s.insert(v[i] / prime);
      prime = v[i] / prime;
      v2.pb(prime);
    }
    //sort(v2.begin(), v2.end());
    for(int i = 0; i < s.size(); i++) {
      m.insert(make_pair(, (char)(65 + i)));
    }
    for(int i = 0; i < )
  }
  return 0;
}
