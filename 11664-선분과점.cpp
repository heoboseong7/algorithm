#include <bits/stdc++.h>

using namespace std;

int main()
{
    double x[3], y[3], z[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
    }
    double ans = 1000000000.0;
    int r = 10000000;
    //cout << ans << '\n';

    while (r--)
    {
        double mx = (x[0] + x[1]) / 2, my = (y[0] + y[1]) / 2, mz = (z[0] + z[1]) / 2;
        double t = sqrt(pow((x[2] - mx), 2) + pow((y[2] - my), 2) + pow((z[2] - mz), 2));
        if (abs(ans - t) <= 0.000000001)
            break;
        ans = min(ans, t);
        double ld = pow((x[0] - x[2]), 2) + pow((y[0] - y[2]), 2) + pow((z[0] - z[2]), 2);
        double rd = pow((x[1] - x[2]), 2) + pow((y[1] - y[2]), 2) + pow((z[1] - z[2]), 2);
        if (ld > rd)
        {
            x[0] = mx;
            y[0] = my;
            z[0] = mz;
        }
        else
        {
            x[1] = mx;
            y[1] = my;
            z[1] = mz;
        }
    }
    printf("%.7lf", ans);

    return 0;
}