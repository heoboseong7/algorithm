#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
#define FOR(var, start, to) for(int var = start; i < to; i++)
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool fuckyou[2001][2001];
bool side[2001];
int s[2001];
int temps[2001];
int ds[2001];

int main() {
	int n, m, minimum = 99999999, maximum = 0, minIndex = 0;

	char temp;

	cin >> n >> m;
	getchar();
	for (int i = 0; i < n; i++) {

		scanf("%c", &temp);

		if (temp == 'L')
			side[i] = true;

		getchar();

		for (int j = 0; j < m; j++) {
			scanf("%c", &temp);
			if (temp == '1')
				fuckyou[i][j] = true;
			if (side[i]) {
				if (fuckyou[i][j])
					s[j]--;
			}
			else {
				if (fuckyou[i][j])
					s[j]++;
			}
		}
		while (getchar() != '\n');
	}

	FOR(i, 1, m) {
		s[i] = s[i] + s[i - 1];
	}

	for (int i = 0; i < n; i++) {
		copy(s, s + m, temps);
		int change = 0;
		maximum = 0;
		for (int j = 0; j < m; j++) {
			if (side[i]) {
				if (fuckyou[i][j]) {
					change++;
				}
			}
			else {
				if (fuckyou[i][j])
					change--;
			}
			temps[j] += change;
		}
		for (int j = 0; j < m; j++) {
			if (maximum < abs(temps[j]))
				maximum = abs(temps[j]);
		}
		if (minimum > maximum) {
			minimum = maximum;
			minIndex = i;
		}
	}
	cout << minIndex + 1 << '\n' << minimum;
	return 0;
}
