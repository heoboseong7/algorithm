#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, a = 5;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		a = (a + 3 * i + 1) % 45678; 
	}
	printf("%d", a);
	
	return 0;
}