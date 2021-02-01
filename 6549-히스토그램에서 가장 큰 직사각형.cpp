#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {

	int n;

	cin >> n;
	while (n != 0) {
		stack<int> st;
		unsigned long long int h[100001] = { 0, };
		unsigned long long int ans = 0;

		for (int i = 0; i < n; i++) {
			cin >> h[i];
			while (!st.empty() && h[st.top()] > h[i]) {
				int temp = st.top();
				st.pop();
				if (!st.empty()) //
					ans = max(ans, (i - st.top() - 1) * h[temp]);
				else
					ans = max(ans, i * h[temp]);
			}
			st.push(i);
		}

		while (!st.empty()) {
			int temp = st.top();
			st.pop();
			if(!st.empty()) //
				ans = max(ans, (n - st.top() - 1) * h[temp]);
			else
				ans = max(ans, n * h[temp]);
		}

		cout << ans << '\n';
		cin >> n;
	}
	return 0;
}
