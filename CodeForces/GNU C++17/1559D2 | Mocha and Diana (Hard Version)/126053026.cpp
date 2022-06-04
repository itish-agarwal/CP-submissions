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
  for(int i = 1; i < n; ++i) {
    if(!d1.belong(0, i) && !d2.belong(0, i)) {
      ans.emplace_back(0, i);
      d1.unite(0, i);
      d2.unite(0, i);
    }
  }
  vector<int> x, y;
  for(int i = 0; i < n; ++i) {
    if(!d1.belong(0, i)) {
      x.emplace_back(i);
    }
    if(!d2.belong(0, i)) {
      y.emplace_back(i);
    }
  }
  while(!x.empty() && !y.empty()) {
    int a = x.back(), b = y.back();
    if(d1.belong(0, a)) {
      x.pop_back();
      continue;
    }
    if(d2.belong(0, b)) {
      y.pop_back();
      continue;
    }
    x.pop_back();
    y.pop_back();
    if(!d1.belong(a, b) && !d2.belong(a, b)) {
      ans.emplace_back(a, b);
      d1.unite(a, b);
      d2.unite(a, b);
    }
  }
  cout << (int) ans.size() << '\n';
  for(auto it : ans) {
    cout << ++it.first << " " << ++it.second << '\n';
  }
}