#include <bits/stdc++.h>
#include <utility>
#define fi first
#define se second
#define pb push_back

using namespace std;

int n;
pair<vector<int>, string> p[100001];

bool cmp(const pair<vector<int>, string> &a, const pair<vector<int>, string> &b) {
	if(a.fi[0] > b.fi[0]) return true; // 국어감소 영어증가 수학감소
	else if(a.fi[0] < b.fi[0]) return false;
	else if(a.fi[1] < b.fi[1]) return true;
	else if(a.fi[1] > b.fi[1]) return false;
	else if(a.fi[2] > b.fi[2]) return true;
	else if(a.fi[2] < b.fi[2]) return false;
	else {
		if(a.se <= b.se) return true;
		else return false;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	
	string s;
	int a, b, c;
	
	for(int i = 0; i < n; i++) {
		cin >> s >> a >> b >> c;
		p[i].se = s;
		p[i].fi.pb(a);
		p[i].fi.pb(b);
		p[i].fi.pb(c);
	}
	
	sort(p, p + n, cmp);
	for(int i = 0; i < n; i++) {
		cout << p[i].se << '\n';
	}
	return 0;
}