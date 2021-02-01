#include <bits/stdc++.h>

using namespace std;

int main() {
  //ios_base::sync_with_stdio(false); cin.tie(0);
  int n1, n2, n3, minset;
  int before = 0, disc = 0;
  vector<int> va, vb ,vc;
  cin >> n1 >> n2 >> n3;

  minset = min(n1, min(n2, n3));

  int temp;
  for(int i = 0; i < n1; i++) {
    cin >> temp;
    before += temp;
    va.push_back(temp);
  }
  sort(va.begin(), va.end(), greater<int>());

  for(int i = 0; i < n2; i++) {
    cin >> temp;
    before += temp;
    vb.push_back(temp);
  }
  sort(vb.begin(), vb.end(), greater<int>());

  for(int i = 0; i < n3; i++) {
    cin >> temp;
    before += temp;
    vc.push_back(temp);
  }
  sort(vc.begin(), vc.end(), greater<int>());

  for(int i = 0; i < minset; i++) {
    disc += va[i] + vb[i] + vc[i];
  }
  cout << before << endl;
  cout << (int)(before - (disc * 0.1)) << endl;

  return 0;
}
