#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string n;
	char cmp[20];
	int temp;
	cin >> n;
	n.copy(cmp, n.size(), 0);
	cmp[n.size()] = '\0';

	if (next_permutation(cmp, cmp + n.size()))
		cout << cmp;
	else
		cout << 0;

	return 0;
}
