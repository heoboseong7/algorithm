#include <bits/stdc++.h>
#define MAX 10001
#define UNVISITED 987654321
using namespace std;

int V, E; 
int dfs_num[MAX], dfs_low[MAX];
int dfs_cnt;
bool visited[MAX];
vector<int> adj[MAX];
vector<vector<int>> SCC;
vector<int> S;

void tarjan(int u) {
	dfs_low[u] = dfs_num[u] = ++dfs_cnt;
	S.push_back(u);
	visited[u] = true;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(dfs_num[v] == 0) 
			tarjan(v);
		if(visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if(dfs_low[u] == dfs_num[u]) {
		vector<int> scc;
		while(1) {
			int v = S.back();
			scc.push_back(v);
			visited[v] = false;
			S.pop_back();
			if(v == u) break;
		}
		SCC.push_back(scc);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> V >> E;
	//memset(dfs_num, UNVISITED, MAX);
	int a, b;
	for(int i = 0; i < E; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	
	for(int i = 1; i <= V; i++)
		if(dfs_num[i] == 0) tarjan(i);
	
	cout << SCC.size() << '\n';
	for(int i = 0; i < SCC.size(); i++)
		sort(SCC[i].begin(), SCC[i].end());
	sort(SCC.begin(), SCC.end());
	for(int i = 0; i < SCC.size(); i++) {
		for(int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << ' ';
		}
		cout << -1 << '\n';
	}
	
	return 0;
}