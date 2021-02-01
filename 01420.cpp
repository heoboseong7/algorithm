#include <bits/stdc++.h>
#define INF 987654321
#define MAX 20002
#define pb push_back
//1 ~ 10000 in 10001 ~ 20000 out 
using namespace std;

const int out = 10000;
int dx[4] = {1, 0, -1 ,0};
int dy[4] = {0, 1, 0, -1};
pair<int, int> src, sink;
int N, M;
map<pair<int, int>, int> c;
map<pair<int, int>, int> f;
int level[MAX];
int work[MAX];
char grid[101][101];
vector<int> adj[MAX];

int res(int a, int b) {
	return c[make_pair(a, b)] - f[make_pair(a, b)];
}

bool bfs() {
	fill(level, level + MAX, -1);
	queue<int> q;
	level[src.first * M + src.second + 1] = 0;
	q.push(src.first * M + src.second + 1);
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
	return level[sink.first * M + sink.second + 1] > 0;
}

int dfs(int here, int crtcap) {
	if(here == sink.first * M + sink.second + 1) return crtcap;
	for(int &i = work[here]; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if(level[here] + 1 == level[next] && res(here, next) > 0) {
			int cap = dfs(next, min(crtcap, res(here, next)));
			if(cap > 0) {
				f[make_pair(here, next)] += cap;
				f[make_pair(next, here)] -= cap;
				return cap;
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			cin >> grid[i][j];
			if(grid[i][j] == 'K') src = make_pair(i, j);
			if(grid[i][j] == 'H') sink = make_pair(i, j);
		}
	}
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int idx = i * M + j + 1;
			adj[idx].pb(idx + out);
			adj[idx + out].pb(idx);
			c[make_pair(idx, idx + out)] = 1;
			c[make_pair(idx + out, idx)] = 0;
			if(grid[i][j] == '#') continue;
			if(i + 1 < N && grid[i + 1][j] != '#') {
				int next = (i + 1) * M + j + 1;
				c[{idx + out, next}] = INF;
				c[{next, idx + out}] = 0;
				
				c[{next + out, idx}] = INF;
				c[{idx, next + out}] = 0;
				
				adj[idx + out].pb(next);
				adj[next].pb(idx + out);
				
				adj[next + out].pb(idx);
				adj[idx].pb(next + out);
			}
			if(j + 1 < M && grid[i][j + 1] != '#') {
				int next = i * M + j + 2;
				c[{idx + out, next}] = INF;
				c[{next, idx + out}] = 0;
				
				c[{next + out, idx}] = INF;
				c[{idx, next + out}] = 0;
				
				adj[idx + out].pb(next);
				adj[next].pb(idx + out);
				
				adj[next + out].pb(idx);
				adj[idx].pb(next + out);
			}
		}
	}
	// 정점을 분할했을 때에는 out정점이 시작정점이다.
	int ans = 0;
	while(bfs()) {
		fill(work, work + MAX, 0);
		while(1) {
			int flow = dfs(src.first * M + src.second + 1 + out, INF);
			if(flow == 0) break;
			ans += flow;
		}
	}
	for(int d = 0; d < 4; d++) {
		int x = src.first + dx[d], y = src.second + dy[d];
		if(x < 0 || y < 0 || x >= N || y >= M) continue;
		if(x == sink.first && y == sink.second) ans = -1;
	}
	cout << ans;
	return 0;
}