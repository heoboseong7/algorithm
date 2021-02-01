#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

bool chain[300001]; // chain[i[는 pot[i] 와 pot[i + 1]의 연결 여부
int pot[300001][3];
int n;
bool pre[1000001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &pot[i][0], &pot[i][1], &pot[i][2]);
	}

	pre[pot[0][0]] = true; pre[pot[0][1]] = true; pre[pot[0][2]] = true;
	for (int i = 0; i < n - 1; i++) {
		if (pre[pot[i + 1][0]] || pre[pot[i + 1][1]] || pre[pot[i + 1][2]])
			chain[i] = true;

		pre[pot[i][0]] = false; pre[pot[i][1]] = false; pre[pot[i][2]] = false;
	}


}
