#include <bits/stdc++.h>
#define INF 987654321
#define MAX 502
#define pb push_back

using namespace std;

const int src = 0, sink = 501, food = 300;
int N, K, D;
int c[MAX][MAX];
int f[MAX][MAX];
int work[MAX];
int level[MAX];
vector<int> adj[MAX];
//1 ~ 200은 사람 301 ~ 400까지는 음식

int res(int a, int b) {
	return c[a][b] - f[a][b];
}

bool bfs() {
	fill(level, level + MAX, -1);
	queue<int> q;
	level[src] = 0;
	q.push(src);
	while(!q.empty()) {
		int here = q.front();
		q.pop();
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
		int r = res(here, next);
		if(r > 0 && level[next] == level[here] + 1) {
			int cap = dfs(next, min(crtcap, r));
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
	
	cin >> N >> K >> D;
	
	for(int i = 0; i < D; i++) {
		int a;
		cin >> a;
		adj[food + i + 1].pb(sink);
		adj[sink].pb(food + i + 1);
		c[food + i + 1][sink] = a;
	}
	
	for(int i = 1; i <= N; i++) {
		int z;
		cin >> z;
		adj[src].pb(i);
		adj[i].pb(src);
		c[src][i] = K;
		for(int j = 0; j < z; j++) {
			int a;
			cin >> a;
			adj[i].pb(food + a);
			adj[food + a].pb(i);
			c[i][food + a] = 1;
		}
	}
	int ans = 0;
	
	while(bfs()) {
		fill(work, work + MAX, 0);
		while(1) {
			int flow = dfs(src, INF);
			if(flow == 0) break;
			ans += flow;
		}
	}
	cout << ans;
	return 0;
}