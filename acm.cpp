#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int ary[101];
int line[101];
pair<int, int> set[101];
int setcnt = 0;
int cnt = 0;
int j = 0;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", ary + i);
	}
	for (int i = 0; i < n; i++) {
		set[j].first = ary[i];
		set[j].second = ary[i];
		setcnt++;
		while (1) {
			if (ary[i + 1] > ary[i]) {
				set[j].second = ary[i];
				i++;
			}
			else {
				j++;
				break;
			}
		}
	}
  for(int i = 0; i < setcnt; i++) {
    bool check = false;
    for(int m = 0; m < k; m++) {
      if(line[m] < set[i].first) {
        line[m] = set[i].second;
        check = true;
        break;
      }
    }
    if(!check) {
      cout <<"NO";
      return 0;
    }
  }
	cout << "YES";
	return 0;

}
