#include <bits/stdc++.h>
#define sf1(a) scanf("%d", &a)
using namespace std;

int m;
bool a[21];

void add(int x) {
	a[x] = true;
}

void remove(int x) {
	a[x] = false;
}
void check(int x) {
	if(a[x]) printf("100000");
	else printf("00000");
}
void toggle(int x) {
	a[x] = !a[x];
}
void all() {
	memset(a + 1, true, 20);
}
void empty() {
	memset(a + 1, false, 20);
}

int main() {
	scanf("%d", &m);
	char s[10];
	int x;
	while(m--) {
		scanf("%s", s);
		if(s == "all") all();
		else if(s == "empty") empty();
		else {
			sf1(x);
			if(s == "add") add(x);
			else if(s == "remove") remove(x);
			else if(s == "check") check(x);
			else if(s == "toggle") toggle(x);
		}
	}
	return 0;
}