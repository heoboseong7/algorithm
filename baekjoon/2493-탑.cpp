
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	int h[500001] = { 0, };
	stack<int> st;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> h[i];
		while (!st.empty()) {
			if (h[st.top()] > h[i]) {
				printf("%d ", st.top() + 1);
				break;
			}
			else {
				st.pop();
			}
		}
		if (st.empty())
			printf("0 ");
		st.push(i);
	}

	return 0;
}
