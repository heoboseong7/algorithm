#include <bits/stdc++.h>
#define MAX 401
#define INF 987654321
using namespace std;

int S = 1, E = 2;
int N, P;
vector<int> adj[MAX];
int work[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
int level[MAX];

bool bfs() {
	fill(level, level + MAX, -1);
	level[S] = 0;
	queue<int> q;
	q.push(S);
	while(!q.empty()) {
		int here = q.front(); q.pop();
		for(int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			int res = c[here][next] - f[here][next];
			if(level[next] == -1 && res > 0) {
				q.push(next);
				level[next] = level[here] + 1;
			}
		}
	}
	return level[E] > 0;
}

int dfs(int here, int crtcap) {
	if(here == E) return crtcap;
	for(int &i = work[here]; i < adj[here].size(); i++) {
		int next = adj[here][i];
		int res = c[here][next] - f[here][next];
		if(level[next] == level[here] + 1 && res > 0) {
			int cap = dfs(next, min(crtcap, res));
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
	
	cin >> N >> P; // 단방향
	for(int i = 0; i < P; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		c[a][b] = 1;
	}
	int ans = 0;
	while(bfs()) {
		fill(work, work + MAX, 0);
		while(1) {
			int flow = dfs(S, INF);
			if(flow == 0) break;
			ans += flow;
		}
	}
	cout << ans;
	
	return 0;
}