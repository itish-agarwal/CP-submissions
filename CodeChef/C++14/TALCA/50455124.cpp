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
  for(auto it = mp.begin(); it != mp.end(); ++it) {
    pr(*it); auto copy = it;
    if(++copy != mp.end()) 
      cout << " ";
  }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values;
  for(auto& value : pq) 
    values.push_back(value);

  pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) {
    pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : "");
  }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values;
  for(auto value : pq)
    values.push_back(value);

  pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins

template <class T>
struct SparseTable {
public:
  int N;
  vector<int> compute;
  vector<vector<T>> tab;
  vector<T> values, comparator;

  T merge(const T& a, const T& b) {
    return (comparator[a] < comparator[b] ? a : b);
  }

  SparseTable(const vector<T>& _values = {}, const vector<T>& depths = {}) {
    if(!_values.empty()) 
      build(_values, depths);
  }

  void build(const vector<T>& _values, const vector<T>& depths) {
    values = _values;
    comparator = depths;
    N = _values.size();
    compute.resize(N + 1);
    for(int i = 2; i <= N; ++i)
      compute[i] = compute[i/2] + 1;

    const int log = 32 - __builtin_clz(N);
    tab.resize(log);

    tab[0] = values;
    for(int j = 1; j < log; ++j) {
      tab[j].resize(N - (1 << j) + 1);
      for(int i = 0; i <= N - (1 << j); ++i)
        tab[j][i] = merge(tab[j-1][i], tab[j-1][i + (1 << (j-1))]);
    }
  }

  T query(int L, int R) {
    int j = compute[R - L + 1];
    return merge(tab[j][L], tab[j][R - (1 << j) + 1]);
  }
};
struct LCA {
  int n = 0, root = 0;
  vector<vector<int>> edges;
  vector<int> parent, depth, subtree_size;
  vector<int> euler2, euler, first_occurence;
  SparseTable<int> st;

  LCA(int _n, int _root) {
    n = _n;
    root = _root;
    edges.assign(n, {});
    parent.resize(n);
    depth.resize(n);
    subtree_size.resize(n);
    first_occurence.assign(n, -1);
  }

  LCA(const vector<vector<int>>& adj, int root) {
    LCA((int) adj.size(), root);
    edges = adj;
  }

  void add_edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  void build() {
    function<void(int, int)> Dfs = [&](int a, int pr) {
      euler2.push_back(a);
      euler.push_back(a);
      subtree_size[a] = 1;
      parent[a] = pr;
      for(int b : edges[a]) {
        if(b != pr) {
          depth[b] = depth[a] + 1;
          parent[b] = a;
          Dfs(b, a);
          euler2.push_back(a);
        }
      }
      euler.push_back(a);
    };

    Dfs(root, -1);

    for(int i = 0; i < 2 * n; ++i)
      if(first_occurence[euler2[i]] == -1) 
        first_occurence[euler2[i]] = i;

    st.build(euler2, depth);
  }

  int get_lca(int a, int b) {
    a = first_occurence[a];
    b = first_occurence[b];

    if(a > b)
      swap(a, b);

    return st.query(a, b);
  }
};

void test_case() {
  int N;
  cin >> N;

  LCA lca(N, 0);
  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    lca.add_edge(--a, --b);
  }

  lca.build();
  int Q, ans;
  cin >> Q;

  for(int q = 0; q < Q; ++q) {
    int r, u, v;
    cin >> r >> u >> v;

    --r, --u, --v;
    int L1 = lca.get_lca(r, u);
    int L2 = lca.get_lca(u, v);
    int L3 = lca.get_lca(r, v);

    if(L1 == L2) 
      ans = L3;
    else if(L2 == L3)
      ans = L1;
    else
      ans = L2;

    cout << ans + 1 << '\n';
  }
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  // cin >> tests;
  while(tests--)
    test_case();

}