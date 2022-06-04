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
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
void pr(bool x)  { cout << x; }
// void pr(int x)  { cout << x; }

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

vector<vector<pair<int, int>>> edges;
vector<int> D, up, down, parent;
vector<int> other1, other2;
vector<int> max1, max2;

void dfs1(int a, int pr) {
  for(auto [b, c] : edges[a]) {
    if(b != pr) {
      dfs1(b, a);
      parent[b] = a;
      down[a] = max({down[a], c + D[b], c + down[b]});
    }
  }
  for(auto [b, c] : edges[a]) {
    int val = c + down[b];
    if(val > max1[a]) {
      max2[a] = max1[a];
      max1[a] = val;
    }
    else if(val > max2[a]) {
      max2[a] = val;
    }

    val = c + D[b];
    if(val > other1[a]) {
      other2[a] = other1[a];
      other1[a] = val;
    }
    else if(val > other2[a]) {
      other2[a] = val;
    }
  }
}

void dfs2(int a, int pr, int c) {
  if(pr > -1) {
    up[a] = max({up[a], c + D[pr], c + up[pr]});

    int mx1 = other1[pr], mx2 = other2[pr];
    if(c + D[a] != other1[pr]) {
      up[a] = max(up[a], c + mx1);
    } else {
      up[a] = max(up[a], c + mx2);
    }

    mx1 = max1[pr], mx2 = max2[pr];
    if(c + down[a] != max1[pr]) {
      up[a] = max(up[a], c + mx1);
    } else {
      up[a] = max(up[a], c + mx2);
    }
  }

  for(auto [b, cc] : edges[a]) {
    if(b != pr) {
      dfs2(b, a, cc);
    }
  }
}

void test_case() {
  int N;
  cin >> N;

  edges.resize(N);
  up.resize(N);
  down.resize(N);
  parent.assign(N, -1);
  D.resize(N);

  max1.resize(N, -1);
  max2.resize(N, -1);
  other1.resize(N, -1);
  other2.resize(N, -1);

  for(int i = 0; i < N - 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    edges[a].emplace_back(b, c);
    edges[b].emplace_back(a, c);
  }

  for(auto &d : D)
    cin >> d;

  dfs1(0, -1);
  dfs2(0, -1, 0);

  for(int i = 0; i < N; ++i)
    cout << max(up[i], down[i]) << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;

  while(tests--) 
    test_case();
}