#include <bits/stdc++.h>

using namespace std;
#define int long long

class dsu {
public:
  vector<int> p, sz;
  dsu(int _n) {
    p.resize(_n);
    sz.assign(_n, 1);
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }
  inline void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(x != y) {
      if(sz[x] < sz[y]) {
        p[x] = y;
        sz[y] += sz[x];
      } else {
        p[y] = x;
        sz[x] += sz[y];
      }
    }
  }
  inline bool belong(int x, int y) {
    return get(x) == get(y);
  }
  inline int get_size(int x) {
    return sz[get(x)];
  }
};
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<tuple<int, int, int>> edges;
  for(int i = 0; i < n - 1; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    edges.emplace_back(w, a, b);
  }
  sort(edges.begin(), edges.end());
  dsu d(n);
  int ans = 0;
  for(auto it : edges) {
    int a = get<1>(it), b = get<2>(it), w = get<0>(it);
    int sz0 = d.get_size(a), sz1 = d.get_size(b);
    ans += sz0 * sz1 * w;
    d.unite(a, b);
  }
  cout << ans << '\n';
}