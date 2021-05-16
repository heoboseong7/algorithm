#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
vector<int> lotto;

void rec(int idx, int cnt) {
    if(cnt == 6) {
        for(int i=0; i<6; i++) {
            cout << v[lotto[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    if(idx == n) return;
    
    lotto.push_back(idx);
    rec(idx+1, cnt+1);
    lotto.pop_back();
    rec(idx+1, cnt);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    while(n!=0) {
        for(int i=0; i<n; i++) {
            int input;
            cin >> input;
            v.push_back(input);
        }
        rec(0, 0);
        cout << '\n';
        v.clear();
        cin >> n;
    }

    return 0;
}