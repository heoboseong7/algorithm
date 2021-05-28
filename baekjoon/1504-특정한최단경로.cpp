#include <bits/stdc++.h>

using namespace std;

vector<int> adj[801];
int dist[801][801];
int dijk[2][801];
bool check[2][801];
int main()
{
    int n, e;
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        dist[a][b] = c;
        dist[b][a] = c;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    pq.push(make_pair(0, v1));
    while (!pq.empty())
    {
        int here = pq.top().second;
        pq.pop();
        check[0][here] = true;
        for (int i = 0; i < adj[here].size(); i++)
        {
            int next = adj[here][i];
            int cost = dist[here][next];
            if ((dijk[0][next] == 0 || dijk[0][next] > dijk[0][here] + cost) && next != v1)
            {
                dijk[0][next] = dijk[0][here] + cost;
                pq.push(make_pair(dijk[0][next], next));
            }
        }
    }

    pq.push(make_pair(0, v2));
    while (!pq.empty())
    {
        int here = pq.top().second;
        pq.pop();
        check[1][here] = true;
        for (int i = 0; i < adj[here].size(); i++)
        {
            int next = adj[here][i];
            int cost = dist[here][next];
            if ((dijk[1][next] == 0 || dijk[1][next] > dijk[1][here] + cost) && next != v2)
            {
                dijk[1][next] = dijk[1][here] + cost;
                pq.push(make_pair(dijk[1][next], next));
            }
        }
    }
    int ans1 = 987654321, ans2 = 987654321;
    // v2 = n v1 = 1
    if (check[0][1] && check[0][v2] && check[1][n])
        ans1 = dijk[0][1] + dijk[0][v2] + dijk[1][n];
    if (check[1][1] && check[1][v1] && check[0][n])
        ans2 = dijk[1][1] + dijk[1][v1] + dijk[0][n];

    if (min(ans1, ans2) == 987654321)
        printf("-1");
    else
        printf("%d", min(ans1, ans2));
    return 0;
}