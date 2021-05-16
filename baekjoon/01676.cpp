#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	long long int n, f = 1;
	long long int ans = 0;
	
	cin >> n;
	
	for(int i = 1; i < n + 1; i++) {
		f = i;
		while(f / 5 != 0 && f % 5 == 0) {
			ans++;
			f /= 5;
		}
	}
	cout << ans;
	return 0;
}