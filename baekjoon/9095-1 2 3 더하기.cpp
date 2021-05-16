#include <iostream>

using namespace std;

int ans = 0;
int n, T;

void rec(int a) {
	if (a == n)
		ans++;
	else if (a < n) {
		rec(a + 1); rec(a + 2); rec(a + 3);
	}
}
int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		rec(1); rec(2); rec(3);

		cout << ans << '\n';
		ans = 0;
	}
	return 0;
}
