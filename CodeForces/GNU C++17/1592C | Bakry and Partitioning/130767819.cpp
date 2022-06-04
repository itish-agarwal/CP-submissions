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
 
bool not_intersect(const pair<int, int> &a, const pair<int, int> &b) {
  return b.first > a.second;
}
 
void test_case() {
  int N, K;
  cin >> N >> K;
 
  int total_xor = 0;
  vector<int> A(N);
 
  for(auto &a : A) {
    cin >> a;
    total_xor ^= a;
  }
 
  vector<pair<int, int>> all_edges;
  vector<vector<int>> edges(N);
  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
    all_edges.emplace_back(a, b);
  }
 
  if(total_xor == 0) {
    cout << "YES" << '\n';
    return;
  }
 
  if(N - 1 < 2 || K - 1 < 2) {
    cout << "NO" << '\n';
    return;
  } 
 
  vector<int> subtree_xor(N), depth(N), parent(N, -1);
 
  function<void(int, int)> Dfs = [&](int a, int pr) {
    subtree_xor[a] = A[a];
    for(int b : edges[a]) 
      if(b != pr) {
        parent[b] = a;
        depth[b] = depth[a] + 1;
        Dfs(b, a);
        subtree_xor[a] ^= subtree_xor[b];
      }
  };
 
  Dfs(0, -1);
 
  int node = -1, d = -1;
 
  for(int i = 0; i < N; ++i)
    if(subtree_xor[i] == total_xor)
      if(depth[i] > d) {
        d = depth[i];
        node = i;
      }
 
  if(node <= 0) {
    cout << "NO" << '\n';
    return;
  }
 
  vector<bool> bad(N);
  int rem = N;
 
  function<void(int, int)> Dfs2 = [&](int a, int pr) {
    bad[a] = 1;
    for(int b : edges[a]) 
      if(b != pr) {
        Dfs2(b, a);
      }
  };
 
  Dfs2(node, parent[node]);
  for(int i = 0; i < N; ++i)
    rem -= bad[i];
 
  if(rem < 2) {
    cout << "NO" << '\n';
    return;
  }
 
  vector<vector<int>> adj(N);
  for(auto [a, b] : all_edges)
    if(!bad[a] && !bad[b]) {
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
 
  subtree_xor.assign(N, 0);
 
  function<void(int, int)> Dfs3 = [&](int a, int pr) {
    subtree_xor[a] = A[a];
    for(int b : adj[a]) 
      if(b != pr) { 
        Dfs3(b, a);
        subtree_xor[a] ^= subtree_xor[b];
      }
  };
 
  Dfs3(0, -1);
 
  for(int i = 0; i < N; ++i)
    if(!bad[i] && subtree_xor[i] == total_xor) {
      cout << "YES" << '\n';
      return;
    }
 
  cout << "NO" << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  cin >> tests;
 
  while(tests--) 
    test_case();
}