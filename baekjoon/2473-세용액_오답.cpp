#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

vector<ll> values;

ll binarySearch(int start, int end, ll val)
{
    bool find = false;
    ll result;
    int originStart = start;
    int originEnd = end;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        //cout << start << ' ' << end << '\n';
        if (val > values[mid])
        {
            start = mid + 1;
        }
        else if (val < values[mid])
        {
            end = mid - 1;
        }
        else
        {
            result = values[mid];
            find = true;
            break;
        }
    }

    if (!find)
    {
        //cout << start << ' ' << end << '\n';
        int lowIdx = start > originEnd ? start - 1 : start;
        int highIdx = end < originStart ? end + 1 : end;
        ll low = abs(values[lowIdx] - val);
        ll high = abs(values[highIdx] - val);
        result = low < high ? values[lowIdx] : values[highIdx];
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        values.push_back(a);
    }

    sort(values.begin(), values.end());
    ll sum = 4000000000;
    ll ans[3];
    int head = 0;
    int tail = n - 1;

    while (tail - head > 1)
    {
        ll currentValue = values[head] + values[tail];
        ll mid = binarySearch(head + 1, tail - 1, -currentValue);
        currentValue += mid;
        //cout << values[head] << ' ' << mid << ' ' << values[tail] << '\n';
        if (abs(currentValue) < abs(sum))
        {
            //cout << currentValue << '\n';
            sum = currentValue;
            ans[0] = values[head];
            ans[1] = mid;
            ans[2] = values[tail];
        }

        if (sum > 0)
        {
            tail--;
        }
        else if (sum < 0)
        {
            head++;
        }
        else
        {
            break;
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
    return 0;
}