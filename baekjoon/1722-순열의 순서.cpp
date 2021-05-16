#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int lld;
int main() {
	int n, pn;
	int a[20];
	cin >> n >> pn;
	for (int i = 0; i < n; i++)
		a[i] = i + 1;

	if (pn == 1) {
		lld fact[20];
		int cnt[20];
		int check = 0;

		for (int i = 0; i < n; i++)
			cnt[i] = i;

		fact[0] = 1; fact[1] = 1;

		for (int i = 2; i < n; i++)
			fact[i] = fact[i - 1] * i;

		lld k;
		cin >> k;
		for (int i = 1; i <= n; i++) {
			int temp = cnt[i - 1] / fact[i];
			if (temp > 0) {
				while (1) {
					if (check ^ (1 << temp)) {
						check |= (1 << temp);
						cnt[i - 1] = temp;
						break;
					}
					else
						temp++;
				}
			}
		}
		for (int i = 0; i < n; i++)
			printf("%d ", a[cnt[i]]);
	}
	else {
		int count = 1;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		while (prev_permutation(a, a + n))
			count++;
		printf("%d", count);
	}

	return 0;
}
