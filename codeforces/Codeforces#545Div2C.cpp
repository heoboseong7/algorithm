#include <bits/stdc++.h>
using namespace std;
#define INF 987654321
#define FOR(var, start, to) for(int var = start; var < to; var++)
#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b
#define MAX3(a, b, c) MAX(a, MAX(b, c))
#define MIN3(a, b, c) MIN(a, MIN(b, c))
#define ABS(a) a < 0 ? -a : a
#define fi first
#define se second
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int easx[1001];
int soux[1001];
int citye[1001][1001];
int citys[1001][1001];
int ans[1001][1001];
int city[1001][1001];
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m;

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> city[i][j];

  for(int i = 0; i < n; i++) {
    int tempmin = 0;
    for(int j = 1; j < m; j++) {
      if(city[i][j - 1] < city[i][j])
        citye[i][j] = citye[i][j - 1] + 1;
      else if(city[i][j - 1] > city[i][j])
        citye[i][j] = citye[i][j - 1] - 1;
      else
        citye[i][j] = citye[i][j - 1];
      tempmin = min(citye[i][j], tempmin);
    }
    for(int j = 0; j < m; j++) {
      citye[i][j] += abs(tempmin) + 1;
      easx[i] = max(easx[i], citye[i][j]);
    }
  }
  for(int i = 0; i < m; i++) {
    int tempmin = 0;
    for(int j = 1; j < n; j++) {
      if(city[j - 1][i] < city[j][i])
        citys[j][i] = citys[j - 1][i] + 1;
      else if(city[j - 1][i] > city[j][i])
        citys[j][i] = citys[j - 1][i] - 1;
      else
        citys[j][i] = citys[j - 1][i];
      tempmin = min(citys[j][i], tempmin);
    //  cout << citys[j - 1][i] << ' ' << citys[j][i];
    }
    for(int j = 0; j < n; j++) {
      citys[j][i] += abs(tempmin) + 1;
      soux[i] = max(soux[i], citys[j][i]);
    //  cout << citys[j][i];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(citye[i][j] > citys[i][j])
        cout << max(citye[i][j] - citys[i][j] + soux[j], easx[i]) << ' ';
      else
        cout << max(citys[i][j] - citye[i][j] + easx[i], soux[j]) << ' ';
    }
    cout << '\n';
  }
  //cout << soux[0] << ' ' << citys[0][0] << ' ' << citys[1][0];
  return 0;
}
