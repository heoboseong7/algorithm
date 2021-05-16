#include <bits/stdc++.h>
#define MAX 801
#define MAX2 400
#define INF 987654321
using namespace std;

int S = 1, E = 2;
int N, P;
vector<int> adj[MAX];
int work[MAX];
int c[MAX][MAX];
int f[MAX][MAX];
int level[MAX];;

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
	if(here == E ) return crtcap;
	for(int &i = work[here]; i < adj[here].size(); i++) {
		int next = adj[here][i];
		int res = c[here][next] - f[here][next];
	//	cout << here << ' ' << next << ' ' << res << '\n';
		if(level[next] == level[here] + 1 && res > 0) {
			int cap = dfs(next, min(crtcap, res));
			if(cap > 0) {
				f[here][next] += 1;
				f[next][here] -= 1;
				return 1;
			}
		}
	}
	return 0;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> N >> P;
	for(int i = 0; i < P; i++) {
		int a, b;
		cin >> a >> b;
		// S E가 아닌 정점은 3이상이다.
		int temp = max(a, b);
		a = min(a, b);
		b = temp;
		adj[a + MAX2].push_back(b); // 2개 분할 시 out에서 in으로, 그리고 역순이 2개가 생긴다..
		adj[b + MAX2].push_back(a);
		adj[b].push_back(a + MAX2);
		adj[a].push_back(b + MAX2);
		c[a + MAX2][b] = 1;
		c[b + MAX2][a] = 1;
	}
	/*for(int i = 1; i < MAX; i++)
		for(int j = 1; j < MAX; j++) {
			c[i][j] = 1;
		}
		*/
	for(int i = 1; i < MAX2 + 1; i++) {
		adj[i].push_back(i + MAX2);
		adj[i + MAX2].push_back(i);
		c[i][i + MAX2] = 1;
		c[i + MAX2][i] = 0;
	}
	
	c[1][1 + MAX2] = INF;
	c[1 + MAX2][1] = 0;
	c[2][2 + MAX2] = INF;
	c[2 + MAX2][2] = 0;
	
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