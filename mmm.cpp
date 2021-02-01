#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const long long MAX_N = 1e3 + 3;
long long n, ans;
long long Arr[MAX_N];
long long cnt[MAX_N];
long long table[MAX_N][MAX_N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> Arr[i];
		cnt[Arr[i]]++;
	}

	if (n % 2 == 0) {
		int ind = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!table[i][j]) {
					while (ind < MAX_N && cnt[ind] < 4)
						ind++;

					if (ind == MAX_N) {
						cout << "NO\n";
						return 0;
					}

					cnt[ind] -= 4;
					table[i][j] = table[n - 1 - i][j] = table[i][n - 1 - j] = table[n - 1 - i][n - 1 - j] = ind;
				}

		cout << "YES\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << table[i][j] << " ";
			cout << "\n";
		}

		return 0;
	}

	int ind = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!table[i][j] && i != n / 2 && j != n / 2) {
				while (ind < MAX_N && cnt[ind] < 4)
					ind++;

				if (ind == MAX_N) {
					cout << "NO\n";
					return 0;
				}

				cnt[ind] -= 4;
				table[i][j] = table[n - 1 - i][j] = table[i][n - 1 - j] = table[n - 1 - i][n - 1 - j] = ind;
			}

	ind = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!table[i][j] && (i != n / 2 || j != n / 2)) {
				while (ind < MAX_N && cnt[ind] < 2)
					ind++;

				if (ind == MAX_N) {
					cout << "NO\n";
					return 0;
				}

				cnt[ind] -= 2;
				if (i == n / 2)
					table[i][j] = table[i][n - 1 - j] = ind;
				else
					table[i][j] = table[n - 1 - i][j] = ind;
			}

	ind = 1;
	while (ind < MAX_N && cnt[ind] < 1)
		ind++;

	if (ind == MAX_N) {
		cout << "NO\n";
		return 0;
	}

	table[n / 2][n / 2] = ind;

	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << table[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
