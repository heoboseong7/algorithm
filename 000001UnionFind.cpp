#include <bits/stdc++.h>
/*
#include <iostream>
#include <vector>
#include <algorithm>
*/
using namespace std;
#define FOR(var, start, to) for(int var = start; i < to; i++)
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

/*
class UnionFind {
  private:
     vi p, rank;
  public:
    UnionFind(int N) {
      rank.assign(N, 0);
      p.assign(N, 0);
      for(int i = 0; i < N; i++) {
        p[i] = i;
      }
    }
    int findSet(int i) {
      return (p[i] == i ? i : p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j) {
      if(!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
          p[y] = x;
        }
        else {
          p[x] = y;
          if (rank[x] == rank[y])
            rank[y]++;
        }
      }
    }
    int numDisjointSets() {
      int DisjoinSetCount = 0;
      for(int i = 0; i < (int)p.size(); i++) {
        if(p[i] == i) {
          DisjoinSetCount++;
        }
      }
      return DisjoinSetCount;
    }
    int sizeOfSet(int i) {
      int parent = findSet(i);
      int sizeofset = 0;
      for(int i = 0; i < (int)p.size(); i++) {
        if(parent == findSet(i)) {
          sizeofset++;
        }
      }
      return sizeofset;
    }
};
*/
class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1);
    numSets = N; rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++)
      p[i] = i;
  }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i]));
  }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j);
  }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
      int x = findSet(i), y = findSet(j);
      // rank is used to keep the tree short
      if (rank[x] > rank[y]) {
        p[y] = x; setSize[x] += setSize[y];
      }
      else {
        p[x] = y; setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
  int numDisjointSets() {
    return numSets;
  }
  int sizeOfSet(int i) {
    return setSize[findSet(i)];
  }
};
