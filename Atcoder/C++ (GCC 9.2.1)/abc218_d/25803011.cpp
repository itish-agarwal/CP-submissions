#include <bits/stdc++.h>

using namespace std;

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

////
pair<vector<int>, vector<int>> bfs_result(const vector<vector<int>>& edges, int sc, int des) {
  int n = edges.size();

  vector<int> d(n, -1), pr(n, -1);
  d[sc] = 0;
  queue<int> q;
  q.push(sc);

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    for(int v : edges[u]) {
      if(d[v] == -1 || d[v] > d[u] + 1) {
        d[v] = d[u] + 1;
        pr[v] = u;
        q.push(v);
      }
    }
  }

  return make_pair(d, pr);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> all_edges;
  map<pair<int, int>, int> index;

  for(int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    all_edges.emplace_back(a, b);
    index[{a, b}] = i;
  }

  vector<vector<int>> edges(N);
  for(auto [a, b] : all_edges)
    edges[a].push_back(b);

  auto init = bfs_result(edges, 0, N - 1);

  vector<int> d = init.first;
  vector<int> pr = init.second;

  if(d[N - 1] == -1) {
    for(int i = 0; i < M; ++i)
      cout << -1 << '\n';

    return 0;
  }

  vector<int> path;
  int x = N - 1;

  while(pr[x] != -1) {
    path.emplace_back(x);
    x = pr[x];
  }
  path.emplace_back(0);

  reverse(path.begin(), path.end());

  vector<int> affected(M);
  for(int i = 1; i < (int) path.size(); ++i) {
    int id = index[{path[i - 1], path[i]}];
    affected[id] = 1;
  }  

  vector<int> ids;
  vector<int> ans(M);
  for(int i = 0; i < M; ++i) {
    if(!affected[i]) {
      ans[i] = d[N - 1];
    }
    else {
      ids.emplace_back(i);
    }
  }

  for(int id : ids) {
    vector<vector<int>> adj(N);
    for(int i = 0; i < M; ++i) {
      if(i ^ id) {
        adj[all_edges[i].first].push_back(all_edges[i].second);
      }
    }
    auto it = bfs_result(adj, 0, N - 1);
    ans[id] = it.first[N - 1];
  }

  for(int i = 0; i < M; ++i)
    cout << ans[i] << '\n';
}