#include <iostream>

using namespace std;

int main() {
	int a[7];
	int sum = 0;
	int min = 999;
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		cin >> a[i];
		if (a[i] % 2) {
			cnt++;
			sum += a[i];
			if (a[i] < min)
				min = a[i];
		}

	}

	if (cnt != 0)
		cout << sum << '\n' << min;
	else
		cout << -1;

	return 0;
}
