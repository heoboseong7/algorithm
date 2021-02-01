#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, a, b, ans = 0;
	cin >> n >> a >> b;

	while (1) {
		if (a - b == 1 && a % 2 == 0) {
			ans++;
			cout << ans;
			break;
		}
		else if (b - a == 1 && b % 2 == 0) {
			ans++;
			cout << ans;
			break;
		}
		a = a / 2 + a % 2;
		b = b / 2 + b % 2;
		ans++;
		if (pow(2, ans) > n) {
			cout << -1;
			break;
		}
	}

	return 0;
}
