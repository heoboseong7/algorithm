#include <bits/stdc++.h>

using namespace std;

int dir[10];
int len[10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k;
    cin >> k;
    for(int i = 0; i < 6; i++) {
        cin >> dir[i] >> len[i];
    }
    int width = 7, height = 7;
    for(int i = 0; i < 6; i++) {
        if(dir[i] < 3) width = len[width] < len[i] ? i : width;
        else height = len[height] < len[i] ? i : height;
    }
    int ans = len[width] * len[height];
    int temp = 1;
    for(int i = 0; i < 6; i++) {
        if(abs(width - i) < 2 || abs(height - i) < 2 || abs(width - i) == 5 || abs(height - i) == 5) continue;
        else temp *= len[i];
    }
    cout << (ans - temp) * k;

    return 0;
}