#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, m;
vector<int> v1, v2, ans;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	int input;
	for(int i = 0; i < n; i++) {
		cin >> input;
		v1.pb(input);
	}
	for(int i = 0; i < m; i++) {
		cin >> input;
		v2.pb(input);
	}
	
	int a = 0, b = 0;
	for(int i = 0; i < n + m; i++) {
		if(b < m && a < n) {
			if(v1[a] > v2[b]) 
				ans.pb(v2[b++]);
			else
				ans.pb(v1[a++]);
		}
		else if(a == n) ans.pb(v2[b++]);
		else if(b == m) ans.pb(v1[a++]);
	}
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}
	
	return 0;
}