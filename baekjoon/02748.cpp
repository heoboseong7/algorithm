#include <bits/stdc++.h>

using namespace std;

long long int a[100];
int n;

int main() {
	scanf("%d", &n);\
	a[1] = 1;
	for(int i = 2; i < 90; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}
	
	cout << a[n];
}