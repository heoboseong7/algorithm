#include <bits/stdc++.h>
#define SIZE 100001

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
    {
        int n, ans = 0;
        cin >> n;

        vector<bool> visit(n + 1);
        fill(visit.begin(), visit.end(), false);
        vector<int> s(n + 1);

        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (!visit[i])
            {
                stack<int> st;
                st.push(i);
                while (!st.empty())
                {
                    int here = st.top();
                    // st.pop();
                    if (visit[here])
                    {
                        st.pop();
                        int cnt = 0;
                        bool found = false;
                        while (!st.empty() && !found)
                        {
                            if (st.top() == here)
                            {
                                found = true;
                                cnt++;
                            }
                            else
                            {
                                cnt++;
                                st.pop();
                            }
                        }
                        if (found)
                            ans += cnt;
                    }
                    else
                    {
                        st.push(s[here]);
                        visit[here] = true;
                    }
                }
            }
        }
        cout << n - ans << '\n';
    }

    return 0;
}