#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct element {
   int val;
   int a;
   int b;
};

element ary[50001];
int parent[1001], treeRank[1001];

bool sortF(element t, element u) {
   return t.val > u.val;
}

int find(int p) {
  if(parent[p] == p)
    return p;
  else
    return parent[p] = find(parent[p]);
}

void init() {
  for (int i = 0; i < 1000; i++)
    parent[i] = i, treeRank[i] = 0;
}

void uni(int p, int q) {
  p = find(p);
  q = find(q);
  if (treeRank[p] < treeRank[q])
    parent[p] = q, treeRank[q] += treeRank[p];
  else
    parent[q] = p, treeRank[p] += treeRank[q];
  if(treeRank[p] == treeRank[q])
    treeRank[p]++;
}


int main(void) {
  int start, end, numOfNode, numOfRoad, index = 0;
  cin >> numOfNode >> numOfRoad;
  cin >> start >> end;
  init();
  for (int i = 0; i < numOfRoad; i++)
    scanf("%d %d %d", &ary[i].a, &ary[i].b, &ary[i].val);
  sort(ary, ary + numOfRoad, sortF);
  while(find(start) != find(end)) {
    uni(ary[index].a, ary[index].b);
    index++;
  }
  cout << ary[index - 1].val;
}
