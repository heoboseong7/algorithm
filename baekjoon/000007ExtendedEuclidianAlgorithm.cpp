#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
//as + bt = gcd(a, b)
//find s and t
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

int xgcd(int a, int b) {
  vi s, t, r, q;
  s = {1, 0}; t = {0, 1}; r = {a, b};
  while(r.back() != 0) {
    q.push_back(r[r.size() - 2] / r[r.size() - 1]);
    r.push_back(r[r.size() - 2] % r[r.size() - 1]);
    s.push_back(s[s.size() - 2] - s.back() * q.back());
    t.push_back(t[t.size() - 2] - t.back() * q.back());
  }
  return t.back();
}
