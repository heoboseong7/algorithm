#include <bits/stdc++.h>

using namespace std;

long long int A, B, C, N, sum, normalsum;
map<string, long long int> normal, special, service;
string s;
long long int price;
bool checkservice = false;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cin >> A >> B >> C;
	for(int i = 0; i < A; i++) {
		cin >> s >> price;
		normal.insert(make_pair(s, price));
	}
	for(int i = 0; i < B; i++) {
		cin >> s >> price;
		special.insert(make_pair(s, price));
	}
	for(int i = 0; i < C; i++) {
		cin >> s;
		service.insert(make_pair(s, -1));
	}
	
	cin >> N;
	while(N--) {
		cin >> s;
		if(normal.find(s) != normal.end()) {
			sum += normal.find(s)->second;
			normalsum += normal.find(s)->second;
		}
		else if(special.find(s) != special.end()) {
			sum += special.find(s)->second;
		}
		else {
			if(!checkservice) {
				checkservice = true;
			}
			else {
				printf("No");
				return 0;
			}
		}
	}
	
	if(normalsum != sum && normalsum < 20000) {
		printf("No");
		return 0;
	}
	else if(sum < 50000 && checkservice) {
		printf("No");
		return 0;
	}
	printf("Okay", normalsum, sum);
	
	return 0;
}