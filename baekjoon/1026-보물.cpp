#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, temp, sum = 0;
vector<int> a, b;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
	}
	for (int i = 0; i < n; i++) {
		cin >> temp;
		b.push_back(temp);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[i];
	}

	cout << sum;

	return 0;
}
