#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<int> st;
	int ans = 0;
	string a;
	cin >> a;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '(')
			st.push(i);
		else
			if (i - st.top() == 1) {
				st.pop();
				ans += st.size();
			}
			else {
				st.pop();
				ans++;
			}
	}

	cout << ans;

	return 0;
}
