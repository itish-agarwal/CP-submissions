#include <bits/stdc++.h>
 
using namespace std;
 
class dsu {
public:
  vector<int> p, rank;
  dsu(int _n) {
    p.resize(_n);
    rank.resize(_n);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(x != y) {
      if(rank[x] < rank[y]) {
        p[x] = y;
      } else if(rank[y] < rank[x]) {
        p[y] = x;
      } else {
        p[y] = x;
        rank[x]++;
      }
    }
  }
  inline bool belong(int x, int y) {
    return get(x) == get(y);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  dsu d1(n), d2(n);
  for(int i = 0; i < m1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    d1.unite(a, b);
  }
  for(int i = 0; i < m2; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    d2.unite(a, b);
  }
  vector<pair<int, int>> ans;
  for(int i = 0; i < n; ++i) {
    for(int j = i + 1; j < n; ++j) {
      if(!d1.belong(i, j) && !d2.belong(i, j)) {
        ans.emplace_back(i, j);
        d1.unite(i, j);
        d2.unite(i, j);
      }
    }
  }
  cout << (int) ans.size() << '\n';
  for(auto it : ans) {
    cout << ++it.first << " " << ++it.second << '\n';
  }
} 