#include <iostream>

using namespace std;

int main() {
	int T;
	int left, right;
	cin >> T;

	int x, y;
	int k;

	for (int i = 0; i < T; i++) {
		int cnt = 0;
		left = 5;
		right = 6;
		k = 2;
		cin >> x >> y;
		if (y - x < 3)
			cout << y - x << '\n';
		else if (y - x == 3 || y - x == 4)
			cout << 3 << '\n';
		else
		{
			while(1) {
				if (y - x >= left && y - x <= right) {
					cout << cnt + 4 << '\n';
					break;
				}
				else {
					cnt += 1;
					if (cnt % 2) {
						left = right + 1;
						right += ++k;
					}
					else {
						left = right + 1;
						right += k;
					}
			}
			}

		}
	}

}
