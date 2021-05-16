#include <bits/stdc++.h>
#define INF 987654321
#define pb push_back
#define fi first
#define se second
using namespace std;

int N, M;
int MAP[1001][1001];
vector<vector<int>> adj;
vector<int> dist;
vector<pair<int, int>> e[1000001]; // 가중치, 연결된 정점
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> N >> M;
	dist = vector<int>(N * M, INF);
	adj = vector<vector<int>>(N, vector<int>(M, INF));
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int u = i * M + j;
			if(MAP[i][j] == -1) continue;
			if(i + 1 < N && MAP[i + 1][j] != -1) e[u].pb(make_pair(MAP[i + 1][j], u + M));
			if(j + 1 < M && MAP[i][j + 1] != -1) e[u].pb(make_pair(MAP[i][j + 1], u + 1));
			if(i > 0 && MAP[i - 1][j] != -1) e[u].pb(make_pair(MAP[i - 1][j], u - M));
			if(j > 0 && MAP[i][j - 1] != -1) e[u].pb(make_pair(MAP[i][j - 1], u - 1));
		}
	}
	if(MAP[0][0] == -1 && MAP[N - 1][M - 1] == -1) {
		cout << -1;
		return 0;
	}
	dist[0] = MAP[0][0];
	pq.push(make_pair(dist[0], 0));
	while(!pq.empty()) {
		int distance = pq.top().fi;
		int here = pq.top().se;
		pq.pop();
		if(dist[here] < distance) continue;
		for(int i = 0; i < e[here].size(); i++) {
			int next = e[here][i].se;
			int weight = e[here][i].fi;
			if(dist[next] > weight + distance) {
				dist[next] = weight + distance;
				pq.push(make_pair(weight + distance, next));
			}
		}
	}
	if(dist[N * M -1] < INF) cout << dist[N * M - 1];
	else cout << -1;
	return 0;
}