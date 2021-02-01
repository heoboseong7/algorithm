#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int glass[10001];
	int dp[10001];
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> glass[i];

	dp[0] = 0; dp[1] = glass[1]; dp[2] = glass[1] + glass[2];
	dp[3] = max(dp[1] + glass[3], glass[2] + glass[3]);
	for (int i = 4; i <= n; i++) {
		dp[i] = max(max(dp[i - 2] + glass[i], dp[i - 3] + glass[i - 1] + glass[i]), dp[i - 4] + glass[i - 1] + glass[i]);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > ans)
			ans = dp[i];
	}
	cout << ans;
	return 0;
}
