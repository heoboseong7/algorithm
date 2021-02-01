#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b) {
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    long long int n, ans = 1;
    cin >> n;

    for(long long int i=1; i<=n; i++) {
        if(ans % i != 0) {
            ans *= (i / gcd(max(ans, i), min(ans, i)));    
        }
        ans = ans % 987654321;
    }
    cout << ans;

    return 0;
}