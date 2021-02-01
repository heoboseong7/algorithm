#include <bits/stdc++.h>

using namespace std;

int n, k;
long long int len[10001];
long long int num;
long long int ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> k >> n;
    num = k;
    long long int l = 1, r = 0, mid;
    for(int i = 0; i < k; i++) {
        cin >> len[i];
        r = max(r, len[i]);
    }
    while(l <= r) {
        mid = (l + r) / 2;
        long long int t = 0;
        for(int i = 0; i < k; i++) {
            t += len[i] / mid;
        }
        if(t >= n) {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans;
    
    return 0;
}