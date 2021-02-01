#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define MIN(a, b) ((a < b) ? a : b)

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ll> vll;

int board[200][200];
int n, r1, r2, c1, c2;
// r과 s는 현재 말이 있는 좌표
void move(int r, int c, int cnt) {
	if(board[r][c] != -1 && board[r][c] <= cnt + 1)
		return;
	if(r > n - 1 || r < 0 || c > n - 1 || c < 0)
		return;
	board[r][c] = cnt + 1;
	move(r - 2, c - 1, board[r][c]);
	move(r - 2, c + 1, board[r][c]);
	move(r, c - 2, board[r][c]);
	move(r, c + 2, board[r][c]);
	move(r + 2, c - 1, board[r][c]);
	move(r + 2, c + 1, board[r][c]);
}
int main() {
	scanf("%d", &n);
	memset(board, -1, sizeof(board));
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	move(r1, c1, -1);
	
	printf("%d", board[r2][c2]);
	return 0;
}
