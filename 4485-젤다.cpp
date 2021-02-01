#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int n, pn = 1;
int map[125][125] = { 0, };
int dist[125][125] = { 0, };
int main() {
	cin >> n;
	while (n != 0) {
		int check = 1;
		pair<int, int> min = { 0, 0 };
		for (int i = 0; i < 125; i++)
			for (int j = 0; j < 125; j++)
				dist[i][j] = -1;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		dist[0][0] = map[0][0];
		while (dist[n - 1][n - 1] == -1) {
			pair<int, int> temp = { 0 , 0 };
			if (min.first + 1 < n && dist[min.first + 1][min.second] == -1) {
				dist[min.first + 1][min.second] = dist[min.first][min.second] + map[min.first + 1][min.second];
				if (temp.first == 0 && temp.second == 0) {
					temp.first = min.first + 1; temp.second = min.second;
				}
				else
					if (dist[temp.first][temp.second] > dist[min.first + 1][min.second]) {
						temp.first = min.first + 1; temp.second = min.second;
					}
			}
			if (min.first - 1 > -1 && dist[min.first - 1][min.second] == -1) {
				dist[min.first - 1][min.second] = dist[min.first][min.second] + map[min.first - 1][min.second];
				if (temp.first == 0 && temp.second == 0) {
					temp.first = min.first - 1; temp.second = min.second;
				}
				else
					if (dist[temp.first][temp.second] > dist[min.first - 1][min.second]) {
						temp.first = min.first - 1; temp.second = min.second;
					}
			}
			if (min.second + 1 < n && dist[min.first][min.second + 1] == -1) {
				dist[min.first][min.second + 1] = dist[min.first][min.second] + map[min.first][min.second + 1];
				if (temp.first == 0 && temp.second == 0) {
					temp.first = min.first; temp.second = min.second + 1;
				}
				else {
					if (dist[temp.first][temp.second] > dist[min.first][min.second + 1]) {
						temp.first = min.first; temp.second = min.second + 1;
					}
				}
			}
			if (min.second - 1 < -1 && dist[min.first][min.second - 1] == -1) {
				dist[min.first][min.second - 1] = dist[min.first][min.second] + map[min.first][min.second - 1];
				if (temp.first == 0 && temp.second == 0) {
					temp.first = min.first; temp.second = min.second - 1;
				}
				else
					if (dist[temp.first][temp.second] > dist[min.first][min.second - 1]) {
						temp.first = min.first; temp.second = min.second - 1;
					}
			}
			min.first = temp.first; min.second = temp.second;
		}
		printf("Problem %d: %d\n", pn++, dist[n - 1][n - 1]);
		cin >> n;
	}

	return 0;
}
