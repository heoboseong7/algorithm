#include <bits/stdc++.h>

using namespace std;

int k;
bool check[10];
string mans = "9876543210", Mans = "0";
string s;

void f(string n) {
    for(int i = 0; i < 10; i++) {
        if(!check[i]) {
            check[i] = true;
            f(n + (char)(i + 48));
            check[i] = false;
        }
        
        if(n.size() == k+1) {
            for(int i=0; i<k; i++) {
                if(s[i] == '<') {
                    if(n[i] > n[i+1]) break;  
                }
                else {
                    if(n[i] < n[i+1]) break;
                }
                if(i == k-1) {
                    if(mans > n) mans = n;
                    if(Mans < n) Mans = n;
                }
            }
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> k;

    for(int i=0; i<k; i++) {
        char c;
        cin >> c;
        s = s+c;
    }

    string n = "";
    f(n);
    cout << Mans << '\n' << mans;
    return 0;
}