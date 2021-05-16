#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int T, h, w, n;
	cin >> T;

	while (T--) {
		cin >> h >> w >> n;

		//cout << (n % h) + 1 << n / h + 1;
		printf("%d%02d\n", (n % h)  == 0 ? h : (n % h), n % h == 0 ? n / h : n / h + 1);
	}

	return 0;
}
