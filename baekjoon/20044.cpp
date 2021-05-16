#include <bits/stdc++.h>

using namespace std;

int n, ans = 987654321;
vector<int> v;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < 2 * n; i++) {
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	
	for(int i = 0; i < n; i++) {
		ans = min(ans, v[i] + v[2 * n - i - 1]);
	}
	
	cout << ans;
	
	return 0;
}