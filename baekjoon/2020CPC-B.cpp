#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    ll x, y, c;
    pair<ll, ll> p1, p2;
    cin >> x >> y >> c;
    cin >> p1.first >> p2.first >> p1.second >> p2.second;

    ll a = x * p1.first + y * p1.second + c;
    ll b = x * p2.first + y * p2.second + c;
    ll a2 = x * p1.first + y * p2.second + c;
    ll b2 = x * p2.first + y * p1.second + c;

    if((a > 0 && b < 0) || (b > 0 && a < 0) || (a2 > 0 && b2 < 0) || (b2 > 0 && a2 < 0))
        cout << "Poor";
    else
        cout << "Lucky";
    

    return 0;
}