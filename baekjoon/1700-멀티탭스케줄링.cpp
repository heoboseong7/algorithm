#include <bits/stdc++.h>

using namespace std;

int n, k;
queue<int> q[101];
int order[101];
bool is_on[101];
vector<int> pluged;
int cnt, ans;

void unplug()
{
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        if (q[pluged[i]].empty())
        {
            ret = i;
            break;
        }
        if (q[pluged[i]].front() > q[pluged[ret]].front())
        {
            ret = i;
        }
    }
    is_on[pluged[ret]] = false;
    pluged.erase(pluged.begin() + ret);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> order[i];
        q[order[i]].push(i);
    }

    for (int i = 0; i < k; i++)
    {
        int now = order[i];
        // 현재 꽂혀있는 경우
        if (is_on[now])
        {
            q[now].pop();
        }
        // 꽂혀있지 않지만 빈칸이 있는 경우
        else if (cnt < n)
        {
            is_on[now] = true;
            cnt++;
            q[now].pop();
            pluged.push_back(now);
        }
        // 꽂혀있지 않고 빈칸이 없는 경우
        else
        {
            unplug();
            pluged.push_back(now);
            q[now].pop();
            is_on[now] = true;
            ans++;
        }
    }
    cout << ans;
    return 0;
}