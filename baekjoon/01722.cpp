#include <bits/stdc++.h>

using namespace std;
bool check[1001];
int N, m;
long long k;
long long int fac[21];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	fac[0] = 1;
	for(int i = 1; i < 21; i++)
		fac[i] = fac[i - 1] * i;
	
	cin >> N >> m;\
	
	if(m == 1) {
		vector<int> ans(N);
		long long input;
		cin >> input;
		
		input -= 1;
		for(int i = 0; i < N; i++) {
			for(int j = 1; j <= N; j++) {
				if(!check[j]) {
					if(input >= fac[N - i - 1]) 
						input -= fac[N - i - 1];
					else {
						check[j] = true;
						ans[i] = j;
						break;
					}
				}
				else
					continue;
				
			}
		}
		for(int i = 0; i < N; i++) {
			cout << ans[i];
			if(i < N - 1)
				cout << ' ';
		}
	}
	else if(m == 2) {
		vector<int> input(21);
		for(int i = 0; i < N; i++)
			cin >> input[i];
		long long ans = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 1; j < input[i]; j++) {
				if(!check[j]) {
					ans += fac[N - i - 1];
				}
			}
			check[input[i]] = true;
		}
		cout << ans + 1;
	}
	return 0;	
}