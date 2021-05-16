#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check[102][102] = { false, };
int m, n, k;
pair<int, int> pos1, pos2;
vector<int> area;

void find(int i, int j);

int main() {
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> pos1.first >> pos1.second >> pos2.first >> pos2.second;
		for (int a = pos1.second; a < pos2.second; a++)
			for (int b = pos1.first; b < pos2.first; b++) {
				check[a][b] = true;
			}
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				area.push_back(0);
				find(i, j);
			}
		}

	sort(area.begin(), area.end());

	cout << area.size() << '\n';
	for (int i = 0; i < area.size(); i++) {
		cout << area[i] << ' ';
	}

	return 0;
}

void find(int i, int j) {
	check[i][j] = true;
	area[area.size() - 1]++;
	if (i + 1 < m && !check[i + 1][j])
		find(i + 1, j);
	if (j + 1 < n && !check[i][j + 1])
		find(i, j + 1);
	if (i - 1 > -1 && !check[i - 1][j])
		find(i - 1, j);
	if (j - 1 > -1 && !check[i][j - 1])
		find(i, j - 1);
}
