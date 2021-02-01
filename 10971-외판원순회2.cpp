#include <bits/stdc++.h>

using namespace std;

int n;
int w[11][11];
bool check[11];
int ans = 987654321;
vector<int> path;

void f() {
    for(int i=0; i<n; i++) {
        if(!check[i]) {
            path.push_back(i);
            check[i]=true;
            f();
            path.pop_back();
            check[i]=false;
        }
    }
    if(path.size() == n) {
        int cost=0;
        for(int i=1; i<n; i++) {
            if(w[path[i-1]][path[i]] == 0) return;
            cost += w[path[i-1]][path[i]];
        }
        if(w[path[n-1]][path[0]] == 0) return;
        cost += w[path[n-1]][path[0]];
        ans = min(ans, cost);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> w[i][j];
        }
    }
    f();
    cout << ans;

    return 0;
}