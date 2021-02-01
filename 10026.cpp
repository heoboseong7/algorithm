#include <bits/stdc++.h>

using namespace std;

char m[101][101];
int check[101][101]; //정상인
int check2[101][101]; //적록색약
int n;
int ans1, ans2; // 정상인, 적록색약

void travel(int x, int y, int num, char clr) {
	if(x >= n || x < 0 || y >= n || y < 0) return;
	if(clr != m[x][y]) return;
	if(check[x][y] != 0) return;
	
	check[x][y] = num;
	
	travel(x, y + 1, num, clr);
	travel(x + 1, y, num, clr);
	travel(x - 1, y, num, clr);
	travel(x, y - 1, num, clr);
}

void travel2(int x, int y, int num, char clr) {
	if(x >= n || x < 0 || y >= n || y < 0) return;
	if(clr != m[x][y]) return;
	if(check2[x][y] != 0) return;
	
	check2[x][y] = num;
	
	travel2(x, y + 1, num, clr);
	travel2(x + 1, y, num, clr);
	travel2(x - 1, y, num, clr);
	travel2(x, y - 1, num, clr);
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) 
			cin >> m[i][j];
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(check[i][j] == 0) {
				ans1++;
				travel(i, j, ans1, m[i][j]);
			}
		}
	}
	
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < n; j++) 
			if(m[i][j] == 'R') m[i][j] = 'G';
		
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(check2[i][j] == 0) {
				ans2++;
				travel2(i, j, ans2, m[i][j]);
			}
		}
	}	
	
	cout << ans1 << ' ' << ans2;
	
	return 0;
}