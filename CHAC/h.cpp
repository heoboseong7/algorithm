#include <bits/stdc++.h>
#define MAX 987654321

using namespace std;

int n, m;
queue<int> q;
set<int> isRemoved[300001];
int ans[300001];
set<int> validNodes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        isRemoved[a].insert(b);
        isRemoved[b].insert(a);
    }

    for (int i = 2; i <= n; i++)
    {
        ans[i] = MAX;
        validNodes.insert(i);
    }
    q.push(1);
    ans[1] = 0;
    int count = 0;
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        validNodes.erase(here);

        vector<int> eraseList;
        for(auto next : validNodes) {
            if(isRemoved[here].find(next) != isRemoved[here].end())
                continue;
            
            if (ans[next] > ans[here] + 1)
            {
                q.push(next);
                eraseList.push_back(next);
                ans[next] = ans[here] + 1;
            }
        }
        for(int i = 0; i < eraseList.size(); i++) {
            validNodes.erase(eraseList[i]);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == MAX)
            cout << -1 << '\n';
        else
            cout << ans[i] << '\n';
    }
    return 0;
}