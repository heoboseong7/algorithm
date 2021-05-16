#include <bits/stdc++.h>
#define MAX 100001
#define pb push_back

using namespace std;

int T, N, M;
int dfs_cnt;
int dfs_num[MAX], dfs_low[MAX];
vector<int> adj[MAX];
vector<int> S;
vector<vector<int>> SCC;
bool visited[MAX];

void reset() {
	dfs_cnt = 0;
	memset(dfs_num, 0, MAX);
	memset(dfs_low, 0, MAX);
	memset(visited, false, MAX);
	S.clear();
	SCC.clear();
	for(int i = 0; i < MAX; i++) adj[i].clear();
}
void tarjan(int u) {
	dfs_low[u] = dfs_num[u] = ++dfs_cnt;
	S.pb(u);
	visited[u] = true;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(dfs_num[v] == 0) tarjan(v);
		if(visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]) {
		vector<int> scc;
		while(1) {
			int v = S.back();
			scc.pb(v);
			S.pop_back();
			visited[v] = false;
			if(u == v) break;
		}
		SCC.pb(scc);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while(T--) {
		cin >> N >> M;
		int a, b;
		for(int i = 0; i < M; i++) {
			cin >> a >> b;
			adj[a].pb(b);
		}
		for(int i = 1; i <= N; i++)
			if(dfs_num[i] == 0) tarjan(i);
		
		cout << SCC.size() << '\n';
		reset();
	}
	return 0;	
}