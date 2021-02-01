#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int h, w, ans;
bool board[1001][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for(int i = 0; i < 1001; i++)
		board[i][0] = true;
	cin >> h >> w;
	int input;
	for(int i = 0; i < w; i++) {
		cin >> input;
		for(int j = 1; j <= input; j++)
			board[i][j] = true;
	}
	
	for(int i = h; i >= 1; i--) {
		vector<int> v;
		for(int j = 0; j < w; j++) {
			if(board[j][i]) v.pb(j);
		}
		if(v.size() > 1) {
			for(int j = 0; j < v.size() - 1; j++)
				ans += v[j + 1] - v[j] - 1;
		}
	}
	cout << ans;
	return 0;
}