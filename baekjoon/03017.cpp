// 갖다 버림
#include <bits/stdc++.h>

using namespace std;

string a, b;
string ansb, anss; // big, small
int cnt[2][10];

bool check(int x) { //x보다 크거나 같은 b의 수가 있는지 확인
	cnt[0][x]--;
	for(int i = x; i < 10; i++) {
		if(cnt[0][i] > 0) {
			return true;
		}
	}
	cnt[0][x]++;
	return false;
}

bool check2(int x) { //x보다 작거나 같은 b의 수가 있는지 확인
	cnt[1][x]--;
	for(int i = x; i > -1; i--) {
		if(cnt[1][i] > 0) {
			return true;
		}
	}
	cnt[1][x]++;
	return false;
}
int bigger(int x) {
	for(int i = x; i < 10; i++) {
		if(cnt[0][i] > 0) return i;
	}
	return -1;
}
int smaller(int x) {
	for(int i = x; i > -1; i--) {
		if(cnt[1][i] > 0) return i;
	}
	return -1;
}

bool swap() {
	for(int j = 0; j < a.size(); j++) {
		char temp = anss[a.size() - j - 1];
		for(int i = a.size() - j - 1; i > -1; i--) {
			if(temp < anss[i]) {
				if(i == 0 && temp == '0') continue;
				anss[a.size() - j - 1] = anss[i];
				anss[i] = temp;
				return true;
			}
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> a >> b;
	
	for(int i = 0; i < b.size(); i++) {
		cnt[0][(int)b[i] - 48]++;
		cnt[1][(int)b[i] - 48]++;
	}
	/*
	for(int i = 0; i < b.size(); i++) {
		cnt[1][(int)a[i] - 48]++;
	}
	*/
	for(int i = 0; i < a.size(); i++) {
		int ia = (int)a[i] - 48;
		if(cnt[0][ia] > 0 && check(ia)) {
			ansb += char(ia + 48);
		}
		else if(bigger(ia) != -1) {
			ansb += (char)(bigger(ia) + 48);
			cnt[0][bigger(ia)]--;
			char t = '0';
			while((int)t - 48 < 10) {
				if(cnt[0][(int)t - 48] > 0) {
					ansb += t;
					cnt[0][(int)t - 48]--;
				}
				else (int)t++;
			}
			break;
		}
		else {
			ansb = '0';
			break;
		}
	}
	
	for(int i = 0; i < a.size(); i++) {
		int ia = (int)a[i] - 48;
		if(cnt[1][ia] > 0 && check2(ia)) {
			anss += char(ia + 48);
		}
		else if(smaller(ia) > 0 || (!anss.empty() && smaller(ia) == '0')) {
			anss += (char)(smaller(ia) + 48);
			cnt[1][smaller(ia)]--;
			char t = '9';
			while((int)t - 48 > -1) {
				if(cnt[1][(int)t - 48] > 0) {
					anss += t;
					cnt[1][(int)t - 48]--;
				}
				else (int)t--;
			}
			break;
		}
		else {
			anss = '0';
			break;
		}
	}
	cout << ansb << '\n';
	if(anss.compare(a) == 0) {
		if(swap()) cout << anss;
		else cout << 0;
	}
	else cout << anss;
	
	return 0;
}