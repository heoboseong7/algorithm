#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int T, m, n;
	cin >> T;
	while (T--) {
		cin >> m >> n;
		printf("1\n");
		if (n % 2 == 0) {
			for (int i = 0; i < n; i++) {
				if (i % 2 == 0) {
					for (int j = 0; j < m; j++) {
						printf("(%d,%d)\n", j, i);
					}
				}
				else {
					for (int j = m - 1; j >= 0; j--) {
						printf("(%d,%d)\n", j, i);
					}
				}
			}
		}
		else if (m % 2 == 0) {
			for (int i = 0; i < m; i++) {
				if (i % 2 == 0) {
					for (int j = 0; j < n; j++) {
						printf("(%d,%d)\n", i, j);
					}
				}
				else {
					for (int j = n - 1; j >= 0; j--) {
						printf("(%d,%d)\n", i, j);
					}
				}
			}
		}
		else {
			for (int i = 0; i < m; i++) {
				if (i % 2 == 0) {
					for (int j = 0; j < n - 1; j++) {
						printf("(%d,%d)\n", i, j);
					}
				}
				else {
					for (int j = n - 2; j >= 0; j--) {
						printf("(%d,%d)\n", i, j);
					}
				}
			}
			for (int i = 0; i < m; i++) {
				printf("(%d,%d)\n", m - 1 - i, n - 1);
			}
		}
	}

	return 0;
}
