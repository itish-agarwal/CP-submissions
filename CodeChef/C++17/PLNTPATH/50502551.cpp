#include <bits/stdc++.h>

using namespace std;
using namespace chrono;
#define int long long

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif

void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long double x)  { cout << x; }
// void pr(long long x)  { cout << x; }
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

const int INF = 2e17 + 9;

template <class T> 
ostream& operator << (ostream& stream, const vector<T>& values) {
  for(T v : values) 
    cout << v << " ";

  return stream;
}
template <class T>
void print_vector(const vector<T>& values, int from = -1, int to = -1) {
  if(from < 0) from = 0;
  if(to < 0) to = (int) values.size() - 1;

  for(int i = from; i <= to; ++i) 
    cout << values[i] << (i < to ? ' ' : '\n');
}

void test_case() {
  int N, K, S;
  cin >> N >> K >> S;
  S -= 1;

  vector<int> belongs(N);

  for (auto &a : belongs) {
    cin >> a;
    a -= 1;
  }

  vector<vector<int>> inter_alliance(K, vector<int> (K, -1));

  auto update = [&](int &x, int cost) {
    if(x == -1) 
      x = cost;
    x = min(x, cost);
  };

  for(int i = 0; i < N; ++i) {
    for(int j = 0; j < K; ++j) {
      int cost;
      cin >> cost;
      if(cost > -1) {
        update(inter_alliance[belongs[i]][j], cost);
      }
    }
  }

  vector<vector<pair<int, int>>> edges(K);

  for(int a = 0; a < K; ++a) 
    for(int b = 0; b < K; ++b) 
      if(a != b && inter_alliance[a][b] > -1) 
        edges[a].push_back({b, inter_alliance[a][b]});
      
  vector<int> d(K, -1);

  set<pair<int, int>> q;
  q.insert({0, belongs[S]});
  d[belongs[S]] = 0;

  while(!q.empty()) {
    int a = q.begin() -> second;
    q.erase(q.begin());

    for (auto [b, w] : edges[a]) {
      int cost = d[a] + w;
      if(d[b] == -1 || cost < d[b]) {
        q.erase({d[b], b});
        d[b] = cost;
        q.insert({cost, b});
      }
    } 
  }

  vector<int> ans(N, -1);
  for(int a = 0; a < N; ++a)
    ans[a] = d[belongs[a]];

  print_vector(ans);
} 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  // cin >> tests;
  while(tests--)
    test_case();
}