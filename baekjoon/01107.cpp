#include <bits/stdc++.h>

using namespace std;

int n, m, ans = 55555555;
bool check[11];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	
	cin >> n >> m;
	while(m--) {
		int i;
		cin >> i;
		check[i] = true;
	}
	
	for(int i = 0; i < 1000001; i++) {
		int test = i, ans2 = 0;
		bool jump = false;

		while(1) {
			ans2++;
			if(check[test % 10]) {
				jump = true;
				break;
			}	
			if(test > 9) test /= 10;
			else break;
			
		}
		if(jump) continue;
		
		ans = min(ans, ans2 + abs(i - n));
	}
	ans = min(ans, abs(100 - n));
	cout << ans;
	return 0;
}