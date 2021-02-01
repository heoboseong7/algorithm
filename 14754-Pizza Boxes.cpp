#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define FOR(X,to) for(int i = X; i < to; i++)
#define DFOR(X, Y) for(int i = 0; i < X; i++) for(int j = 0; j < Y; j++)
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;




long long int arr[1001][1001];
bool check[1001][1001];
long long int sum;

int main() {
	int m, n;

	cin >> m >> n;
	DFOR(m, n) {
		scanf("%d", &arr[i][j]);
		sum += arr[i][j];
	}

	for (int i = 0; i < m; i++) {
		ii temp = { i, 0 };
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > arr[temp.first][temp.second]) {
				temp.first = i; temp.second = j;
			}
		}
		check[temp.first][temp.second] = true;
	}

	for (int i = 0; i < n; i++) {
		ii temp = { 0, i };
		for (int j = 0; j < m; j++) {
			if (arr[j][i] > arr[temp.first][temp.second]) {
				temp.first = j; temp.second = i;
			}
		}
		check[temp.first][temp.second] = true;
	}

	DFOR(m, n) {
		sum -= check[i][j] ? arr[i][j] : 0;
	}

	printf("%lld", sum);

	return 0;
}
