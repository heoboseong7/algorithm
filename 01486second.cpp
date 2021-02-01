#include <iostream>
#include <vector>
using namespace std;
 
#define INF 200000000
 
int N, M, T, D;
vector<vector<int>> adj, arr;
int xarr[4] = {1, -1, 0, 0};
int yarr[4] = {0, 0, 1, -1};
 
void init()
{
    cin >> N >> M >> T >> D;
    arr = vector<vector<int>>(N, vector<int>(M));
    adj = vector<vector<int>>(N*M, vector<int>(N*M, INF));
    char c;
    for(int i = 0; i<N; ++i)
        for(int j = 0; j<M; ++j)
        {
            cin >> c;
            if(c > 90)
                c -= 6;
            arr[i][j] = c - 'A';
        }
 
    for(int i = 0; i<N; ++i)
        for(int j = 0; j<M; ++j)
        {
            int here = i*M+j;
            for(int k = 0; k<4; ++k)
                if(i+xarr[k] >= 0 && i+xarr[k] <N && j+yarr[k] >=0 && j+yarr[k] < M)
                {
                    int u = arr[i][j];
                    int v = arr[i+xarr[k]][j+yarr[k]];
                    int there = M*(i+xarr[k]) + j+yarr[k];
                    if(u - v > T || v - u > T)
                        adj[here][there] = INF;
                    else if(u < v)
                        adj[here][there] = (v-u)*(v-u);
                    else
                        adj[here][there] = 1;
                }
        }
 
    for(int k = 0; k<N*M; ++k)
        for(int i = 0; i<N*M; ++i)
            for(int j = 0; j<N*M; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    int ans = arr[0][0];
    for(int i = 1; i<N*M; ++i) {
        if(adj[0][i] + adj[i][0] <= D)
            ans = max(ans, arr[i/M][i%M]);
		cout << i << ' ' << adj[i][i] << '\n';
	}
    cout << ans << "\n";
}
