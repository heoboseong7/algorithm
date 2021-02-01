#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int dfs_num[100001];
int dfs_low[100001];
int parent[100001];
int V, E, dfs_cnt; 
vector<int> adj[100001];
vector<pair<int, int>> ans;
void dfs(int u) {
	dfs_low[u] = dfs_num[u] = ++dfs_cnt;
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if(dfs_num[v] == 0) {
			parent[v] = u;
			dfs(v);
			if(dfs_low[v] > dfs_num[u]) {
				int a = min(v, u);
				int b = max(v, u);
				ans.pb(make_pair(a, b));
			}
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
			dfs(i);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';
	
	return 0;
}