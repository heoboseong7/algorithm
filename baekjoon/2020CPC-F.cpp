#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int N;
    cin >> N;
    vector<string> s;

    while(N--) {
        string si;
        cin >> si;
        s.push_back(si);
    }
    sort(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++)
        cout << s[i] << '\n';

    return 0;
}
