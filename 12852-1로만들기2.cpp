#include <bits/stdc++.h>

using namespace std;

pair<int, int> dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fill(dp, dp + 1000001, make_pair(987654, 0));
    int x;
    cin >> x;
    dp[x].first = 0;
    dp[x].second = 1;
    for (int i = x; i > 1; i--)
    {
        if (dp[i].second != 0)
        {
            int here = dp[i].first;
            if (dp[i - 1].first > here + 1)
            {
                dp[i - 1].second = 1;
                dp[i - 1].first = here + 1;
            }
            if (i % 2 == 0)
            {
                if (dp[i / 2].first > here + 1)
                {
                    dp[i / 2].second = 2;
                    dp[i / 2].first = here + 1;
                }
            }
            if (i % 3 == 0)
            {
                if (dp[i / 3].first > here + 1)
                {
                    dp[i / 3].second = 3;
                    dp[i / 3].first = here + 1;
                }
            }
        }
    }
    cout << dp[1].first << '\n';
    stack<int> st;
    st.push(1);
    while (st.top() != x)
    {
        int next = dp[st.top()].second == 1 ? st.top() + 1 : st.top() * dp[st.top()].second;
        st.push(next);
    }
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        cout << top << ' ';
    }
    return 0;
}