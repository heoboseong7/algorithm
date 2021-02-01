#include <iostream>

using namespace std;

int main() {
	int n;
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		bool door[101] = { false, };
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j += i)
				door[j] = !door[j];

		for (int i = 1; i <= n; i++)
			if (door[i])
				ans++;

		cout << ans << endl;
	}
	return 0;
}
