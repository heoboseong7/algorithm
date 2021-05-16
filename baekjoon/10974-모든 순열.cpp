#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int n;
	cin >> n;

	do {
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
		printf("\n");
	} while (next_permutation(a, a + n));

	return 0;
}
