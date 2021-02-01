#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int N, M;
int adj[101][101];
int ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			adj[i][j] = INF;
		
		
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a][b] = 1; // a > b
		adj[b][a] = -1;
	}
	
	for(int k = 1; k <= N; k++)
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++) {
				if(adj[i][k] == 1 && adj[k][j] == 1) { // i > k > j
					adj[i][j] = 1;
					adj[j][i] = -1;
				}
			}
	
	int mid = (N - 1) / 2;
	for(int i = 1; i <= N; i++) {
		int lower = 0, higher = 0;
		for(int j = 1; j <= N; j++) {
			if(adj[i][j] == 1) higher++;
			else if(adj[i][j] == -1) lower++;
		}
		if(lower > mid || higher > mid) ans++;
	}

	cout << ans;
	
	return 0;
}