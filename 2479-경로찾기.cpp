#include <bits/stdc++.h>

using namespace std;

int N, K;
bool check[1001];
string s[1001];
queue<int> q;
vector<int> ans;
vector<int> adj[1001];
int parent[1001];

bool hamming(int a, int b) {
    int cnt = 0;
    for(int i = 0; i < K; i++) {
        if(s[a][i] != s[b][i]) {
            cnt++;
            if(cnt > 1) return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> K;

    for(int i = 1; i <= N; i++)
        cin >> s[i];

    int A, B;
    cin >> A >> B;

    for(int i = 1; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            if(hamming(i, j)) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    q.push(A);
    while(!q.empty()) {
        int here = q.front(); q.pop();
        check[here] = true;

        for(int i = 0; i < adj[here].size(); i++) {
            if(!check[adj[here][i]]) {
                parent[adj[here][i]] = here;
                q.push(adj[here][i]);
            }
            if(adj[here][i] == B) {
                break;
            }
            
        }
    }
    if(parent[B] == 0) cout << -1;
    else {
        stack<int> st;
        int i = B;
        st.push(B);
        while(st.top() != A) {
            st.push(parent[st.top()]);
        }
        while(!st.empty()) {
            cout << st.top() << ' '; st.pop();
        }
    }
    return 0;
}