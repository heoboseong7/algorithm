#include <bits/stdc++.h>

using namespace std;

string s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	
	for(int i = 0; i < s.size(); ) {
		string sub2 = s.substr(i, 2);
		string sub3 = s.substr(i, 3);
		if(sub2.compare("pi") == 0 || sub2.compare("ka") == 0)
			i += 2;
		else if(sub3.compare("chu") == 0)
			i += 3;
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}