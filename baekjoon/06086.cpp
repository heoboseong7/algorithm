#include <bits/stdc++.h>
#define MAX 52
#define INF 987654321

using namespace std;

int N, S, T, ans;
int c[MAX][MAX];
int f[MAX][MAX];
int work[MAX];
int level[MAX];
vector<int> adj[MAX];

int trans(char a) {
	if('A' <= a && a <= 'Z') return a - 'A';
	else return a - 'a' + 26;
}

int res(int a, int b) {
	return c[a][b] - f[a][b];
}
bool bfs() {
	fill(level, level + MAX, -1);
	queue<int> q;
	level[S] = 0;
	q.push(S);
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
	return level[T] > 0;
}

int dfs(int here, int crtcap) {
	if(here == T) return crtcap;
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
	for(int i = 0; i < N; i++) {
		char x, y;
		int z;
		cin >> x >> y >> z;
		int here = trans(x), next = trans(y);
		adj[here].push_back(next);
		adj[next].push_back(here);
		c[here][next] += z;
		c[next][here] += z;
		// 자신과 자신을 연결하는 파이프가 있을 수도 있다.
		// 정점 a와 b를 연결하는 파이프가 2개 이상일 수도 있다...
	}
	
	S = 0; T = 25;
	
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