#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <utility>
#include <cmath>
#include <cassert>
#include <functional>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<pair<int,int> > vii;
typedef vector<pair<ll,int> > vli;
typedef vector<pair<ll,ll> > vll;
typedef vector<pair<db,db> > vdd;

#define mp make_pair
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const db PI = acos(-1);

int main(){

    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);

    vector<pair<int,int> > shit(n);
    vector<int> ss(n+1);
    // dist, max;
    vector<vector<int> > adj(n+1,vector<int>(n+1,1e9));
    vector<vector<int> > adj_stopped(n+1,vector<int>(n+1,0));

    for(int i=1,t;i<=n;i++){
        scanf("%d",&ss[i]);
        shit[i-1]=mp(ss[i],i);
    }

    int a,b,c;
    while(m--){
        scanf("%d %d %d",&a,&b,&c);
        adj[a][b]=adj[b][a]=c;
    }

    for(int i=1;i<=n;i++) adj[i][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) adj_stopped[i][j]=0;
            else adj_stopped[i][j]=adj[i][j]+max(shit[i-1].first,shit[j-1].first);
        }
    }

    sort(shit.begin(),shit.end());
    for(int k=0;k<n;k++){
        int w = shit[k].second;
        int tt = shit[k].first;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adj[i][j] = min(adj[i][j],adj[i][w]+adj[w][j]);
                adj_stopped[i][j] = max(adj[i][j]+max(ss[i],ss[j]),min(adj_stopped[i][j],adj[i][w]+tt+adj[w][j]));
            }
        }
    }

    while(q--){
        scanf("%d %d",&a,&b);
        printf("%d\n", adj_stopped[a][b]>=1e9?-1:adj_stopped[a][b]);
    }

    return 0;
}