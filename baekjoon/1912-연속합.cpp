#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001];
int dp[100001];
int MAX = -1000000000;
vector<int> v;
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", arr+ i);
  }
  int temp = arr[0];
  for(int i = 1; i < n; i++) {
    if(arr[i] >= 0 && arr[i - 1] >= 0) {
      temp += arr[i];
    }
    else if (arr[i] < 0 && arr[i - 1] < 0) {
      temp += arr[i];
    }
    else {
      v.push_back(temp);
      temp = arr[i];
    }
    if(i == n - 1) {
      v.push_back(temp);
    }
  }

  while(v.size() > 1) {
    vector<int> v2;
    for(int i = 0; i < v.size(); i++) {
      MAX = v[i] > MAX ? v[i] : MAX;
      v2.push_back(v[i]);
    }
    v.clear();
    temp = v2[0];
    for(int i = 1; i < v2.size(); i++) {
      if(v2.size() == 2) {
        v.push_back(v2[0] + v2[1]);
        MAX = v[0] > MAX ? v[0] : MAX;
        break;
      }
      if(v2[i] >= 0 && v2[i - 1] >= 0){
        temp += v2[i];
      }
      else if (v2[i] < 0 && v2[i - 1] < 0) {
        temp += v2[i];
      }
      else {
        v.push_back(temp);
        temp = v2[i];
      }
      if(i == v2.size() - 1) {
        v.push_back(temp);
      }
    }
  }
  /*for(int i = 0; i < v.size(); i++)
    cout << v[i] << '\n';*/
  /*for(int i = 1; i <= v.size(); i++) {
     tempmax += arr[v[i - 1]];
     MAX = tempmax > MAX ? tempmax : MAX;
     if(v[i - 1] + 1 != v[i]) {
       tempmax = 0;
     }
  }*/

  printf("%d", MAX);
  return 0;
}
