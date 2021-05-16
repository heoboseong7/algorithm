#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
#define h first
#define p second
using namespace std;

pair<int, int> a[300001];
pair<int, int> dp[300001];
int n, s;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.h == b.h) {
		return a.p > b.p;
	}
	else {
		return a.h < b.h;
	}
}

int bsearch(int n) {
	int l = 0, r = n - 1;
	int mid = (l + r) / 2;
	while (l <= r) {
		if (a[n].h - a[mid].h >= s)
			l = mid + 1;
		else
			r = mid - 1;

		mid = (l + r) / 2;
	}

	return r;
}
int main() {

	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &a[i].h, &a[i].p);
	}

	sort(a + 1, a + n + 1, cmp);

	for (int i = 1; i <= n; i++) {
		if (a[i].h - a[i - 1].h >= s) {
			dp[i].p = dp[i - 1].p + a[i].p;
			dp[i].h = a[i].h;
		}
		else {
			int prev = bsearch(i);
			dp[i].p = max(dp[i - 1].p, dp[prev].p + a[i].p);
			dp[i].h = dp[i - 1].p > dp[prev].p + a[i].p ? dp[i - 1].h : a[i].h;
		}
	}

	cout << dp[n].p;
	return 0;
}
