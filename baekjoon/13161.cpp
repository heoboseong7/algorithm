#include <bits/stdc++.h>
#define INF 987654321
#define MAX 505
#define pb push_back

using namespace std;
const int src = 0, sink = 501;

int N;
int team[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
int level[MAX];
int work[MAX];
int w[MAX][MAX];
vector<int> adj[MAX];
bool check[501];

int res(int a, int b) {
	return c[a][b] - f[a][b];
}

void bfs2() {
	queue<int> q;
	q.push(src);
	check[src] = true;
	while(!q.empty()) {
		int here = q.front(); q.pop();
		for(int i = 0; i < adj[here].size(); i++) {
			int next = adj[here][i];
			if(level[next] > -1 && !check[next]) {
				check[next] = true;
				q.push(next);
			}
		}
	}
}

bool bfs() {
	fill(level, level + MAX, -1);
	queue<int> q;
	q.push(src);
	level[src] = 0;
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
		int r = res(here, next);
		if(level[here] + 1 == level[next] && r > 0) {
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
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> team[i];
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++)
			cin >> w[i][j];
	
	for(int i = 1; i <= N; i++) {
		if(team[i] == 1) {
			c[src][i] = INF;
			adj[src].pb(i);
			adj[i].pb(src);
		}
		if(team[i] == 2) {
			c[i][sink] = INF;
			adj[i].pb(sink);
			adj[sink].pb(i);
		}
	}
	for(int i = 1; i <= N; i++) {
		for(int j = i + 1; j <= N; j++) {
			c[i][j] = w[i][j];
			c[j][i] = w[i][j];
			adj[i].pb(j);
			adj[j].pb(i);
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
	bfs2();
	cout << ans << '\n';
	for(int i = 1; i <= N; i++) {
		if(check[i]) cout << i << ' ';
	}
	cout << '\n';
	for(int i = 1; i <= N; i++) {
		if(!check[i]) cout << i << ' ';
	}
	cout << '\n';
	return 0;
}