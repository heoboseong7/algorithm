#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
int op[4];
int m = 987654321, M = -m;
vector<int> v;

int calc() {
    int ret = a[0];
    for(int i=0; i<n-1; i++) {
        if(v[i] == 0) ret += a[i+1];
        else if(v[i] == 1) ret -= a[i+1];
        else if(v[i] == 2) ret *= a[i+1];
        else if(v[i] == 3) ret /= a[i+1];
    }
    return ret;
}

void f() {
    if(v.size() >= n) return;
    for(int i=0; i<4; i++) {
        if(op[i] > 0) {
            op[i]--;
            v.push_back(i);
            f();
            op[i]++;
            v.pop_back();
        }
    }
    if(v.size() == n-1) {
        int result = calc();
        m = min(m, result);
        M = max(M, result);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();

    cin >> n;
    for(int i=0; i<n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    cin >> op[0] >> op[1] >> op[2] >> op[3];

    f();
    cout << M << '\n' << m;
    return 0;
}