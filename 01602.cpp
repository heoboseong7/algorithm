#include <bits/stdc++.h>
#define INF 987654321
#define fi first
#define se second

using namespace std;

int N, M, Q;
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> w;
int p[501];
vector<pair<int, int>> path;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> N >> M >> Q;
	adj = vector<vector<pair<int,int>>>(N + 1, vector<pair<int,int>>(N + 1, make_pair(INF,INF))) ;
	w = vector<pair<int, int>>(N, make_pair(0, 0));
	
	for(int i = 1; i <= N; i++) {
		cin >> p[i];
		w[i - 1].fi = p[i]; w[i - 1].se = i;
	}
	sort(w.begin(), w.end());
	for(int i = 0; i < M; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adj[a][b].fi = d + max(p[a], p[b]);
		adj[a][b].se = max(p[a], p[b]); 
		adj[b][a] = adj[a][b];
	}
	
	for(int i = 0; i < Q; i++) {
		int a, b;
		cin >> a >> b;
		path.push_back(make_pair(a, b));
	}
	
	for(int i = 1; i <= N; i++) {
		adj[i][i].se = p[i];
		adj[i][i].fi = p[i];
	}

	for(int k = 1; k <= N; k++) {
		int sk = w[k - 1].se;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(adj[i][j].fi > adj[i][sk].fi + adj[sk][j].fi - min(adj[i][sk].se, adj[sk][j].se)) {
					adj[i][j].fi = adj[i][sk].fi + adj[sk][j].fi - min(adj[i][sk].se, adj[sk][j].se);
					adj[i][j].se = max(adj[i][sk].se, adj[sk][j].se);
					//adj[j][i] = adj[i][j];
				}
			}
		}
	}
	for(int i = 0; i < Q; i++) {
		int x = path[i].fi, y = path[i].se;
		if(adj[x][y].fi < INF)
			cout << adj[x][y].fi << '\n';
		else
			cout << -1 << '\n';
	}
	return 0;
}