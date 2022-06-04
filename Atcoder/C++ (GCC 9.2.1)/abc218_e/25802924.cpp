#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> p, r;
  int components;
  DSU(int n) {
    p.resize(n);
    r.resize(n);
    components = n;
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return x == p[x] ? x : p[x] = get(p[x]);
  }
  void unite(int x, int y) {
    x = get(x), y = get(y);
    if(x != y) {
      if(r[y] > r[x]) 
        swap(x, y);
      if(r[x] == r[y])
        r[x]++;
      components--;
      p[y] = x;
    }
  }
  inline bool belong(int x, int y) {
    return get(x) == get(y);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;

  long long ans = 0;
  vector<tuple<int, int, int>> edges;

  for(int i = 0; i < M; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    edges.emplace_back(w, a, b);
    ans += max(0, w); 
  }

  DSU d(N);

  sort(edges.begin(), edges.end());

  for(auto [w, a, b] : edges) {
    if(w <= 0) {
      d.unite(a, b);
    }

    else {
      if(!d.belong(a, b)) {
        d.unite(a, b);
        ans -= w;
      }
    }
    // if(!d.belong(a, b)) {
    //   ans -= w;
    //   d.unite(a, b);
    // }
  }

  cout << ans << '\n';
}