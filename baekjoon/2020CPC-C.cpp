#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int day[444];
int N, S, E;
int ans, cnt, h;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> S >> E;
        for(int j = S; j <= E; j++)
            day[j]++;
    }

    for(int i = 1; i <= 366; i++) {
        if(day[i] > 0) {
            cnt++;
            h = max(h, day[i]);
        }
        else {
            ans += h * cnt;
            cnt = 0; h = 0;
        }
    }
    cout << ans;
    return 0;
}