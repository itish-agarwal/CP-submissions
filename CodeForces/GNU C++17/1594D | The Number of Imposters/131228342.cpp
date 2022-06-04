#include <bits/stdc++.h>
 
using namespace std;
using namespace chrono;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }
 
template <class T, class V> void pr(const pair<T, V> &x);
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
template <class T> void pr(const set<T>& pq);
 
template <class T, class V> void pr(const pair<T, V>& x) {
  cout << "{"; pr(x.first); cout << ", "; pr(x.second); cout << "}";
}
template <class T, class V> void pr(const map<T, V>& mp) {
  for(auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins
 
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
 
void test_case() {
  int N, M;
  cin >> N >> M;
 
  DSU d(N);
 
  vector<pair<int, int>> c_edges, i_edges;
  for(int i = 0; i < M; ++i) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    --a, --b;
 
    if(s == "crewmate") {
      d.unite(a, b);
      c_edges.emplace_back(a, b);
    }
 
    else {
      i_edges.emplace_back(a, b);
    }
  }
 
  vector<int> roots(N), sz(N);
  iota(roots.begin(), roots.end(), 0);
  
  for(int i = 0; i < N; ++i) {
    roots[i] = d.get(i);
    sz[d.get(i)]++;
  }
 
  vector<vector<int>> edges(N); 
  for(auto [a, b] : i_edges) {
    a = roots[a], b = roots[b];
    if(a == b) {
      cout << -1 << '\n';
      return;
    }
 
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
 
  int ans = 0;
 
  vector<int> color(N, -1);
  vector<int> c0, c1;
  bool ok = true;
 
  function<void(int)> Dfs = [&](int a) {
    if(color[a] == 0) c0.push_back(a);
    else c1.push_back(a);
 
    for(int b : edges[a]) {
      if(color[b] > -1) {
        if(color[b] == color[a]) {
          ok = false;
          return;
        }
      }
      else {
        color[b] = color[a] ^ 1;
        Dfs(b);
      }
    }
  };
 
  for(int i = 0; i < N; ++i) {
    if(color[i] == -1) {
      c0.clear();
      c1.clear();
      color[i] = 0;
      Dfs(i);
 
      if(ok == false) {
        cout << -1 << '\n';
        return;
      }
      int s0 = 0, s1 = 0;
      for(int r : c0) s0 += sz[r];
      for(int r : c1) s1 += sz[r];
 
      ans += max(s0, s1);
    }
  }
 
  cout << ans << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  cin >> tests;
 
  while(tests--) 
    test_case();
}