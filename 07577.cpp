#include <bits/stdc++.h>
#define INF 987654321
// unsolved
using namespace std;

int K, N;
vector<vector<int>> adj;
int ans[41];

int main() {
	ios_base::sync_with_stdio(false); cin.tie();
	cin >> K >> N;
	adj = vector<vector<int>>(K + 1, vector<int>(K + 1, INF));
	
	for(int i = 0; i < N; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		adj[x][y] = r;
		adj[y][x] = r;
	}
	
	for(int k = 1; k <= K; k++)
		for(int i = 1; i <= K; i++)
			for(int j = i; j <= K; j++) {
				if(adj[i][j] == INF && adj[i][k] < INF && adj[k][j] < INF) {
					if(i <= k && k <= j) adj[i][j] = adj[i][k] + adj[k][j];
					else adj[i][j] = abs(adj[i][k] - adj[k][j]);
				}
			}
	
	for(int i = 1; i <= K; i++)
		cout << adj[i][i] << ' ';
	return 0;
}