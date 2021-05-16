#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool *prime;

int main() {
	vector<int> v;
	int n;
	prime = new bool[1000001];

	for (int i = 0; i < 1000001; i++) {
		prime[i] = true;
	}

	for (int i = 2; i < 1001; i++) {
		if (prime[i]) {
			for (int j = i * 2; j < 1000001; j += i) {
				prime[j] = false;
			}
		}
	}

	for (int i = 3; i < 1000001; i++) {
		if (prime[i])
			v.push_back(i);
	}

	scanf("%d", &n);
	while (n != 0) {
		int i = 0;
		bool check = false;
		while (v[i] <= n / 2) {
			if (prime[n - v[i]]) {
				printf("%d = %d + %d\n", n, v[i], n - v[i]);
				check = true;
				break;
			}
			i++;
		}
		if (check == false)
			printf("Goldbach's conjecture is wrong.\n");

		scanf("%d", &n);
	}
	//cout << v.size();
	/*int input;
	cin >> input;
	while (input == 0) {

		cin >> input;
	}
	*/

	return 0;
}
