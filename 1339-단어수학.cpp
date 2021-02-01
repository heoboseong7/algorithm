#include <bits/stdc++.h>

using namespace std;

int n, ans;
vector<string> s;
map<char, int> idx;
int mapsize = 0;
int cnt[10][10];
int pow_10[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie();
    cin >> n;
    for(int i=0; i<n; i++) {
        string st;
        cin >> st;
        s.push_back(st);
    }
    //맵으로 각 문자에 대한 고유한 인덱스 부여
    for(int i=0; i<s.size(); i++) {
        for(int j=0; j<s[i].size(); j++) {
            if(idx.find(s[i][j]) == idx.end()) {
                idx[s[i][j]] = mapsize++;
            }
            cnt[idx[s[i][j]]][s[i].size() - j - 1]++;
        }
    }

    for(int i=0; i<idx.size(); i++) {
        int sum = 0;
       for(int j=0; j<8; j++) {
           sum += cnt[i][j] * pow_10[j];
       }
       v.push_back(sum);
    }

    sort(v.begin(), v.end(), greater<int>());
    
    int t=9;
    for(int i=0; i<(int)v.size(); i++) {
        ans += v[i]*t;
        t--;
    }
    cout << ans;

    return 0;
}