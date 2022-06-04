#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
#define int long long

void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(bool x)  { cout << x; }
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
  pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins

void test_case() {
  int N;
  cin >> N;

  vector<vector<int>> edges(N);
  for(int r = 0; r < N - 1; ++r) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  vector<int> A(N);
  for(auto &a : A) 
    cin >> a;

  for(int a = 0; a < N; ++a)
    sort(edges[a].begin(), edges[a].end());

  vector<int> down(N), up(N), subtree_gcds(N), parent(N, -1);
  vector<vector<int>> children(N);

  function<void(int, int)> dfs1 = [&](int a, int pr) {
    subtree_gcds[a] = A[a];
    for(int b : edges[a])
      if(b != pr) {
        dfs1(b, a);
        parent[b] = a;
        children[a].push_back(b);
        subtree_gcds[a] = __gcd(subtree_gcds[a], subtree_gcds[b]);
      }
  };
  dfs1(0, -1);

  vector<vector<int>> pk_gcd(N), sk_gcd(N);
  for(int a = 0; a < N; ++a) {
    pk_gcd[a] = children[a];
    for(auto &b : pk_gcd[a])
      b = A[b];

    for(int i = 1; i < (int) pk_gcd[a].size(); ++i)
      pk_gcd[a][i] = __gcd(pk_gcd[a][i-1], pk_gcd[a][i]);

    sk_gcd[a] = children[a];
    for(auto &b : sk_gcd[a])
      b = A[b];

    for(int i = (int) sk_gcd[a].size() - 2; i >= 0; --i)
      sk_gcd[a][i] = __gcd(sk_gcd[a][i+1], sk_gcd[a][i]);
  }

  function<void(int, int)> dfs2 = [&](int a, int pr) {
    for(int b : edges[a])
      if(b != pr) {
        down[a] += subtree_gcds[b];
        dfs2(b, a);
      }
  };  
  dfs2(0, -1);

  function<void(int, int)> dfs3 = [&](int a, int pr) {
    if(pr > -1) {
      int g = __gcd(up[pr], A[pr]);

      int in = lower_bound(children[pr].begin(), children[pr].end(), a) - children[pr].begin();
      if(in - 1 >= 0) 
        g = __gcd(g, pk_gcd[pr][in-1]);

      if(in + 1 < (int) children[pr].size())
        g = __gcd(g, sk_gcd[pr][in+1]);
      
      up[a] += g;
    }

    for(int b : edges[a])
      if(b != pr)
        dfs3(b, a);
  };  

  dfs3(0, -1);

  int ans = -1;
  for(int a = 0; a < N; ++a)
    ans = max(ans, up[a] + down[a]);

  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}