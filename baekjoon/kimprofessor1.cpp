#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, temp;
    cin >> n;
    vector<int> v;

    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }
    return 0;
}