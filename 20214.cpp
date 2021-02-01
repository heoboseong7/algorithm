#include <bits/stdc++.h>

using namespace std;

int N, maxA;
string ans = "zzzzzzzzzzzz";

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a; string s;
        cin >> s >> a;
        if(maxA < a) {
            maxA = a;
            ans = s;
        }
        else if(maxA == a && ans.compare(s) > 0) {
            ans = s;
        } 
    }

    cout << ans;

    return 0;
}