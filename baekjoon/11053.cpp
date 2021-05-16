#include <bits/stdc++.h>

using namespace std;

int a[10001];
int cnt[10001];
int n;
int ans = -987654321;

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
		scanf("%d", a + i);
	
	for(int i = 1; i < n; i++)
		for(int j = 0; j < i; j++) {
			if(a[i] > a[j] && cnt[i] <= cnt[j])
				cnt[i] = cnt[j] + 1;
		}
	
	for(int i = 0; i < n; i++) {
		ans = max(ans, cnt[i] + 1);
	}
	printf("%d", ans);
	
	return 0;
}