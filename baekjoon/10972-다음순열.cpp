#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int a[10001];
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	if (next_permutation(a, a + n))
		for (int i = 0; i < n; i++)
			printf("%d ", a[i]);
	else
		printf("-1");

	return 0;
}
