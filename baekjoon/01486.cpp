/*
N * M 크기의 인접행렬의
N[i] 의 아래 원소는 N[i + M] 이다
이거로 시간 다 날려먹었다.
*/
#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int N, M, T, D;
int MAP[26][26];
int AdjMat[626][626];
int nodeNum;

int eval(int a, int b) {
	if(a >= b && a - b <= T) return 1;
	else if(a < b && b - a <= T) return (b - a) * (b - a);
	else return INF;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> N >> M >> T >> D;
	nodeNum = N * M;
	
	for(int i = 0; i < nodeNum; i++) 
		for(int j = 0; j < nodeNum; j++) 
			AdjMat[i][j] = INF;
	
	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++) {
			char c;
			cin >> c;
			if((int)c > 96) MAP[i][j] = (int)c - 71;
			else MAP[i][j] = (int)c - 65;
		}

	for(int i = 0; i < N; i++) 
		for(int j = 0; j < M; j++) {
			int now = M * i + j;
			AdjMat[now][now] = 0;
			if(i + 1 < N) AdjMat[now][now + M] = eval(MAP[i][j], MAP[i + 1][j]);
			if(j + 1 < M) AdjMat[now][now + 1] = eval(MAP[i][j], MAP[i][j + 1]);
			if(i > 0) AdjMat[now][now - M] = eval(MAP[i][j], MAP[i - 1][j]);
			if(j > 0) AdjMat[now][now - 1] = eval(MAP[i][j], MAP[i][j - 1]);
		}
	
	for(int k = 0; k < nodeNum; k++)
		for(int i = 0; i < nodeNum; i++)
			for(int j = 0; j < nodeNum; j++) {
				AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
			}
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			int now = M * i + j;
			//cout << now << ' ' << AdjMat[now][now] << '\n';
			if(AdjMat[0][now] + AdjMat[now][0] <= D) ans = max(ans, MAP[i][j]);
		}
	}
	cout << ans;
	return 0;
}