#include <bits/stdc++.h>
#define INF 1000000000
#define fi first
#define se second

using namespace std;

int AdjMat[101][101]; // 그룹, 가중치
int N, M;
int g[101];
vector<int> v[101]; // 연결된 컴포넌트들
vector<int> ans;
int cnt;

void dfs(int u, int group) {
	if(g[u] != 0) return;
	g[u] = group;
	v[group].push_back(u);
	for(int i = 1; i <= N; i++) {
		if(AdjMat[i][u] == 1) dfs(i, group);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++) {
			AdjMat[i + 1][j + 1] = INF;
		}
	
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		AdjMat[a][b] = AdjMat[b][a] = 1;
	}
	
	for(int i = 1; i <= N; i++) 
		if(g[i] == 0) dfs(i, ++cnt);
	
	for(int k = 1; k <= N; k++) {
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
			}
		}
	}

	
	for(int i = 1; i <= cnt; i++) {
		int maxtime = INF;
		int si = v[i][0];
		for(int j = 0; j < v[i].size(); j++) {
			int s = 0;
			for(int k = 0; k < v[i].size(); k++) {
				if(j != k) s = max(s, AdjMat[v[i][j]][v[i][k]]);
			}
			if(maxtime > s) {
				si = v[i][j];
				maxtime = s;
			}
		}
		ans.push_back(si);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	return 0;
}