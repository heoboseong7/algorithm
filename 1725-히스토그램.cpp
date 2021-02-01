#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
	int n;
	stack<int> st;
	int ans = 0;
	int h[100001] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		while (!st.empty() && h[st.top()] > h[i]) { // st가 비어있지 않고 현재 top보다 i가 더 작을 때
			int temp = st.top();
			st.pop();
			int m = i;
			if (!st.empty()) // st에 값이 있으면
				m -= st.top() + 1; // 너비 : 현재 i에서 top + 1을 빼준 값
			ans = max(h[temp] * m, ans); // 방금 구한 넓이와 그 전 넓이의 최대값 비교
		}
		st.push(i);
	}
	// 스택에 남아있는 h들은 아직 계산되지 않았으므로 나머지 처리
	while (!st.empty()) {
		int temp = st.top();
		st.pop();
		int m = n;
		if (!st.empty())
			m -= st.top() + 1;
		ans = max(h[temp] * m, ans);
	}
	cout << ans;
	return 0;
}
