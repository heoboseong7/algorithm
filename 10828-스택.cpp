#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	int n;
	int a;
	char order[100];
	stack<int> st;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> order;
		if (strcmp(order, "push") == 0) {
			cin >> a;
			st.push(a);
		}
		else if(strcmp(order, "pop") == 0) {
			st.pop();
		}
		else if (strcmp(order, "size") == 0) {
			cout << st.size() << '\n';
		}
		else if (strcmp(order, "empty") == 0) {
			if (st.size() == 0)
				cout << 1 << '\n';
			else
				cout << 0;
		}
		else if (strcmp(order, "top") == 0) {
			if (st.empty())
				cout << -1 << '\n';
			else
				cout << st.top();
		}
	}

	return 0;
}
