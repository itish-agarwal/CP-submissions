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
ostream& operator << (ostream& stream, const vector<T>& values) {
  for(T v : values) 
    cout << v << " ";

  return stream;
}
template <class T>
void print_vector(const vector<T>& values, int from = -1, int to = -1) {
  if(from < 0) from = 0;
  if(to < 0) to = int(values.size()) - 1;

  for(int i = from; i <= to; ++i) 
    cout << values[i] << '\n';
}

struct DSU {
  vector<int> p, sz;
  int components;

  DSU(const vector<int>& sizes, int n) {
    p.resize(n);
    sz = sizes;
    components = n;
    iota(p.begin(), p.end(), 0);
  }
  inline int get(int x) {
    return x == p[x] ? x : p[x] = get(p[x]);
  }

  void unite(int x, int y) {
    x = get(x), y = get(y);
    if(x != y) {
      if(sz[y] > sz[x]) 
        swap(x, y);

      sz[x] += sz[y];
      components--;
      p[y] = x;
    }
  }

  inline bool belong(int x, int y) {
    return get(x) == get(y);
  }

  inline int get_size(int x) {
    return sz[get(x)];
  }
};

void test_case() {  
  int N, Q;
  cin >> N >> Q;

  vector<pair<int, int>> queries;
  for(int q = 0; q < Q; ++q) {
    int c, x;
    cin >> c >> x;
    queries.emplace_back(c, x);
  }

  vector<int> cuts;
  for(auto [c, x] : queries) 
    if(c == 1) 
      cuts.push_back(x - 1);

  sort(cuts.begin(), cuts.end());

  int last = 0;
  vector<int> sizes;
  for(int c : cuts) {
    sizes.push_back(c - last + 1);
    last = c + 1;
  }

  sizes.push_back(N - last);

  reverse(queries.begin(), queries.end());

  DSU d(sizes, (int) sizes.size());

  vector<int> preffix_sum = sizes;
  for(int i = 1; i < (int) sizes.size(); ++i)
    preffix_sum[i] += preffix_sum[i - 1];

  vector<int> ans;
  for(auto [c, x] : queries) {
    if(c == 1) {
      int in = lower_bound(preffix_sum.begin(), preffix_sum.end(), x) - preffix_sum.begin();
      d.unite(in, in + 1);
    }
    else {
      int in = lower_bound(preffix_sum.begin(), preffix_sum.end(), x) - preffix_sum.begin();
      ans.emplace_back(d.get_size(in));
    }
  }

  reverse(ans.begin(), ans.end());
  print_vector(ans);
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  // cin >> tests;
  while(tests--)
    test_case();

} 