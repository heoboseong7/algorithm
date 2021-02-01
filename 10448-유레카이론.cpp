#include <iostream>

using namespace std;

int t[45];
int main() {
	for (int i = 1; i < 45; i++) {
		t[i] = i * (i + 1) / 2;
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int a;
		int ans = 0;
		cin >> a;

		for (int i = 1; i < 45; i++) {
			if (t[i] >= a)
				break;
			for (int j = 1; j < 45; j++) {
				if (t[i] + t[j] >= a)
					break;
				for (int k = 1; k < 45; k++) {
					if (t[i] + t[j] + t[k] == a) {
						cout << 1 << '\n';
						ans++;
						break;
					}
					else if (t[i] + t[j] + t[k] > a)
						break;
				}
				if (ans)
					break;
			}
			if (ans)
				break;
		}
		if (!ans)
			cout << 0 << '\n';
	}

	return 0;
}
