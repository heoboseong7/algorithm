#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, m;
set<char> l;
set<char> r;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
   string s[3];
   cin >> s[0] >> s[1] >> s[2];
// cout << s[0] << s[1] << s[2] << '\n';
   l.insert(s[0][0]); r.insert(s[2][0]);
  }
  cin >> m;
  for(int i = 0; i < m; i++) {
    string s[3];
    cin >> s[0] >> s[1] >> s[2];
    if(l.find(s[0][0]) != l.end() && r.find(s[2][0]) != r.end()) {
      cout << 'T' << '\n';
    }
    else
      cout << 'F' << '\n';
  }
  return 0;
}
