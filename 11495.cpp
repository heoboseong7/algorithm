#include <bits/stdc++.h>
#define INF 987654321
#define MAX 2502
#define pb push_back

using namespace std;
const int src = 0, sink = 2501;
int T, N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int c[MAX][MAX];
int f[MAX][MAX];
int level[MAX];
int work[MAX];
vector<int> adj[MAX];

int res(int a, int b) {
	return c[a][b] - f[a][b];
}

void reset() {
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for(int i = 0; i < MAX; i++)
		adj[i].clear();
}

bool bfs() {
	fill(level, level + MAX, -1);
	queue<int> q;
	level[src] = 0;
	q.push(src);
	while(!q.empty()) {
		int here = q.front(); q.pop();
		for(int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			if(level[next] == -1 && res(here, next) > 0) {
				level[next] = level[here] + 1;
				q.push(next);
			}
		}
	}
	return level[sink] > 0;
}

int dfs(int here, int crtcap) {
	if(here == sink) return crtcap;
	for(int &i = work[here]; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if(level[here] + 1 == level[next] && res(here, next) > 0) {
			int cap = dfs(next, min(crtcap, res(here, next)));
			if(cap > 0) {
				f[here][next] += cap;
				f[next][here] -= cap;
				return cap;
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		memset(c, 0, sizeof(c));
		memset(f, 0, sizeof(f));
		cin >> N >> M;
		int S = 0;
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				int val;
				cin >> val;
				S += val;
				int idx = i * M + j + 1;
				if((i + j) % 2 == 0) { // src와 연결
					adj[src].pb(idx);
					adj[idx].pb(src);
					c[src][idx] = val;
					for(int d = 0; d < 4; d++) {
						int x = i + dx[d], y = j + dy[d];
						int next = x * M + y + 1;
						if(x < 0 || y < 0 || x >= N || y >= M) continue;
						adj[idx].pb(next);
						adj[next].pb(idx);
						c[idx][next] = INF;
					}
				}
				else { // sink와 연결
					adj[idx].pb(sink);
					adj[sink].pb(idx);
					c[idx][sink] = val;
				}
			}
		}
		int F = 0;
		while(bfs()) {
			fill(work, work + MAX, 0);
			while(1) {
				int flow = dfs(src, INF);
				if(flow == 0) break;
				F += flow;
			}
		}
		cout << S - F << '\n';
	}
	
	
	
	return 0;
}