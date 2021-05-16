#include <bits/stdc++.h>

using namespace std;

int n, K;
int m[101][101];
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> K;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
        }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < K; j++) {
            for(int k = 0; k < n; k++) 
                for(int l = 0; l < K; l++) 
                    cout << m[i][k] << ' ';
            cout << '\n';
        }
    }

    return 0;
}