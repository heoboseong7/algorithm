#include <iostream>

using namespace std;

int a[1001];
int n;
long long int sum = 0;
long long int temp = 0;
int main() {
	for (int i = 0; i < 1001; i++)
		a[i] = i;

	cin >> n;
	temp = n * (n + 1) / 2;
	for (int i = 0; i <= n; i++) {
		sum += (n - i + 1) * i + temp;
		temp -= i;
	}

	cout << sum;

	return 0;
}
