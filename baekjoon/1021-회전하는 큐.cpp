#include <iostream>

using namespace std;

int m, n;
int a[51];
int x;
int sum = 0;
int temp;
int subn;

int main() {
	cin >> n >> m;
	subn = n;
	for (int i = 0; i < n; i++)
		a[i + 1] = i + 1;
	for (int i = 0; i < m; i++) {
		cin >> x;

		if (a[x] > (subn / 2 + 1)) {
			sum += subn - a[x] + 1;
			temp = a[x];
			for (int i = 1; i <= n; i++) {
				if (a[i] != 0) {
					a[i] = a[i] + subn - temp + 1 <= subn ? a[i] + subn - temp + 1 : a[i] - temp + 1;
					a[i]--;
				}
			}
		}
		else {
			sum += a[x] - 1;
			temp = a[x];
			for (int i = 1; i <= n; i++) {
				if (a[i] != 0) {
					a[i] = a[i] - temp + 1 > 0 ? a[i] - temp + 1 : a[i] - temp + subn + 1;
					a[i]--;
				}
			}
		}
		subn--;
		a[x] = 0;
	}

	cout << sum;

	return 0;
}
