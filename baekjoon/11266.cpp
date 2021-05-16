#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int dfs_num[10001];
int dfs_low[10001];
int parent[10001];
int V, E, rootChild, dfsRoot, dfs_cnt; 
vector<int> adj[10001];
bool check[10001];

void dfs(int u) {
	dfs_low[u] = dfs_num[u] = ++dfs_cnt;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(dfs_num[v] == 0) {
			parent[v] = u;
			if(u == dfsRoot) rootChild++;
			dfs(v);
			if(u != dfsRoot && dfs_low[v] >= dfs_num[u]) check[u] = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if(v != parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> V >> E;
	int a, b;
	for(int i = 0; i < E; i++) {
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	for(int i = 1; i <= V; i++) {
		if(dfs_num[i] == 0) {
			rootChild = 0; dfsRoot = i; dfs(i);
			if(rootChild > 1) check[dfsRoot] = true;
		}
	}

	vector<int> ans;
	for(int i = 1; i <= V; i++)
		if(check[i]) 
			ans.pb(i);
	
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	
	return 0;
}