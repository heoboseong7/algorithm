#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n[3];
	int cnt[6] = { 0, };
	int k;
	for (int i = 0; i < 3; i++) {
		cin >> n[i];
		cnt[n[i] - 1]++;
	}
	int _case = 0;

	for (int i = 0; i < 6; i++)
		if (_case <= cnt[i])
		{
			_case = cnt[i];
			k = i;
		}

	switch (_case) {
	case 1:
		cout << (k + 1) * 100;
		break;
	case 2:
		cout << 1000 + (k + 1) * 100;
		break;
	case 3:
		cout << 10000 + (k + 1) * 1000;
		break;
	}

	return 0;

}
