#include <bits/stdc++.h>

using namespace std;

int s[21][21];
int n, ans = 987654321;
bool check[21];
vector<int> start;

void team(int last) {
    if(start.size() > n/2) return;
    for(int i=last+1; i<=n; i++) {
        start.push_back(i);
        check[i] = true;
        team(i);
        start.pop_back();
        check[i] = false;
    }

    if(start.size() == n/2) {
        vector<int> link;
        for(int i=1; i<=n; i++) {
            if(!check[i])  {
                link.push_back(i);
            }
        }
        int linksum = 0, startsum = 0;
        for(int i=0; i<link.size(); i++) {
            for(int j=0; j<link.size(); j++) {
                if(i == j) continue;
                linksum += s[link[i]][link[j]];
            }
        }

        for(int i=0; i<start.size(); i++) {
            for(int j=0; j<start.size(); j++) {
                if(i == j) continue;
                startsum += s[start[i]][start[j]];
            }
        }
        ans = min(ans, abs(startsum - linksum));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) 
            cin >> s[i + 1][j + 1];
    team(0);
    cout << ans;
    return 0;
}