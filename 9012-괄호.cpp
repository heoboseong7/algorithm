#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		stack<int> st;
		string a;
		cin >> a;
		for (int j = 0; j < a.length(); j++) {
			if (a[j] == ')')
				if (st.empty()) {
					cout << "NO" << '\n';
					st.push(-1);
					break;
				}
				else {
					st.pop();
				}
			else
				st.push(1);
		}
		if (st.empty())
			cout << "YES" << '\n';
		else if(st.top() != -1)
			cout << "NO" << '\n';
	}

	return 0;
}
