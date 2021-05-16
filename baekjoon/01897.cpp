#include <bits/stdc++.h>

using namespace std;

int r, c, ans;
string s[21];

void travel(int x, int y, int z, int mask) {
	if(x >= r || x < 0 || y >= c || y < 0) return;
	if(((1 << ((int)s[x][y] - 65)) & mask) != 0) return;
	
	mask = mask | (1 << ((int)s[x][y] - 65));
	//cout << mask << '\n';
	ans = max(z + 1, ans);
	
	//cout << x << ' ' << y << '\n';
	
	travel(x, y + 1, z + 1, mask);
	travel(x + 1, y, z + 1, mask);
	travel(x - 1, y, z + 1, mask);
	travel(x, y - 1, z + 1, mask);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> r >> c;
	for(int i = 0; i < r; i++)
		cin >> s[i];
	
	travel(0, 0, 0, 0);
	cout << ans;
	
	return 0;
}