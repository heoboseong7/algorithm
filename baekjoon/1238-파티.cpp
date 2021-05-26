#include <bits/stdc++.h>

using namespace std;

int v, e, x;
vector<pair<int, int>> adj[20001];
int dist[20001];
int main()
{
    scanf("%d %d %d", &v, &e, &x);
    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        scanf("%d %d", &a, &b);
        scanf("%d", &c);
        adj[a].push_back(make_pair(c, b));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, x));
    while (!pq.empty())
    {
        int here = pq.top().second;
        //int cost = pq.top().first;
        pq.pop();
        for (int i = 0; i < adj[here].size(); i++)
        {
            int next = adj[here][i].second;
            int cost = adj[here][i].first;
            if ((dist[next] == 0 && next != x) || dist[next] > dist[here] + cost)
            {
                dist[next] = dist[here] + cost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] != 0 || i == x)
            printf("%d\n", dist[i]);
        else
            printf("INF\n");
    }

    return 0;
}