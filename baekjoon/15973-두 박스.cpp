#include <vector>
#include <iostream>

using namespace std;
#define FOR(var, start, to) for(int var = start; i < to; i++)
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	int x1[4], x2[4], y1[4], y2[4];

	cin >> x1[0] >> y1[0] >> x1[1] >> y1[1];
	cin >> x2[0] >> y2[0] >> x2[1] >> y2[1];

	x1[2] = x1[0]; y1[2] = y1[1];
	x1[3] = x1[1]; y1[3] = y1[0];
	x2[2] = x2[0]; y2[2] = y2[1];
	x2[3] = x2[1]; y2[3] = y2[0];

	if ((x1[1] == x2[0] && y1[1] == y2[0]) || (x1[0] == x2[1] && y1[0] == y2[1]) ||
		(x1[2] == x2[3] && y1[2] == y2[3]) || (x1[3] == x2[2] && y1[3] == y2[2])) {
		cout << "POINT";
	}
	else if (x1[0] > x2[1] || y1[1] < y2[0] || x1[1] < x2[0] || y1[0] > y2[1]) {
		cout << "NULL";
	}
	else if (x1[0] == x2[1] || y1[1] == y2[0] || x1[1] == x2[0] || y1[0] == y2[1]) {
		cout << "LINE";
	}
	else {
		cout << "FACE";
	}
	return 0;
}
