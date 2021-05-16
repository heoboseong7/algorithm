#include <bits/stdc++.h>

using namespace std;

int N, M, H;
int m[11][11];
vector<pair<int, int>> mint;
bool check[11][11]; // 방문 여부 확인
pair<int, int> home;
int ans = 0;
int adj[11][11]; //10 home

void travel(pair<int, int> p, int hp) {
    int x = p.first, y = p.second;

}

int toHome(int x, int y) {
    int ret = abs(x - home.first) + abs(y - home.second);

    return ret;
}

int dist(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M >> H;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> m[i][j];
            if(m[i][j] == 1) 
                home = make_pair(i, j);
            else if(m[i][j] == 2) 
                mint.push_back(make_pair(i, j));
        }
    }


    cout << ans;
        
    return 0;
}