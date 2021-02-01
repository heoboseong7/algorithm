#include <bits/stdc++.h>

using namespace std;

long long int p[10001];
int input;
int T;

int main() {
	scanf("%d", &T);
	p[0] = p[1] = p[2] = 1;
	for(int i = 3; i < 101; i++)
		p[i] = p[i - 2] + p[i - 3];
	
	while(T--) {
		scanf("%d", &input);
		
		printf("%lld\n", p[input - 1]);
	}
	
	return 0;
}