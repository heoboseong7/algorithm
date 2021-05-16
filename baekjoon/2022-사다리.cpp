#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double x, y, c;
    cin >> x >> y >> c;
    double ans = 987654321;
    double l = 0, r = min(x, y);
    while (1)
    {
        if (abs(r - l) < 0.000001)
            break;
        double mid = (l + r) / 2.0;
        double h1 = sqrt(x * x - mid * mid);
        double h2 = sqrt(y * y - mid * mid);
        double t = (h1 * h2) / (h1 + h2);

        if (c > t)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
        ans = mid;
    }
    printf("%.3lf", ans);
    return 0;
}