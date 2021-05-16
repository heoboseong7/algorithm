#include <bits/stdc++.h>

using namespace std;

int n;
int w[11];
bool check[11];
bool included[11];
int ans = -987654321;
vector<int> v;

int left(int a) {
    while(check[a]) {
        a--;
    } 
    return w[a];
}

int right(int a) {
    while(check[a]) {
        a++;
    }
    return w[a];
}

int calc() {
    vector<int> t;
    int ret = 0;
    for(int i=0; i<n; i++) {
       check[i] = false;
    }
    for(int i=0; i<v.size(); i++) {
        check[v[i]] = true;
        ret += left(v[i]) * right(v[i]);
    }
    return ret;
}

void f() {
    // 순열 만드는 부분
    for(int i=1; i<n-1; i++) {
        if(!included[i]) {
            included[i]=true;
            v.push_back(i);
            f();
            included[i]=false;
            v.pop_back();
        }
    }
    
    if(v.size() == n-2) {
        ans = max(ans, calc());
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> w[i];
    }
    f();
    cout << ans;

    return 0;
}