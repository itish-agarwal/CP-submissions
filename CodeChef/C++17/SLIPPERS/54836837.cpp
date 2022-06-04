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
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
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
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
const int mod = 998244353;
const int nax = 2e5 + 7;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}

template <class T = long long>
struct fenwick_tree {
  int n;
  vector<T> tree, values;

  fenwick_tree(int _n) {
    n = _n;
    values.resize(n);
    tree.resize(n + 1);
  }

  fenwick_tree(const vector<T>& _values) {
    n = (int) values.size();
    values = _values;
    tree.resize(n + 1);
    for (int i = 0; i < n; ++i) 
      set_value(i, values[i]);
  }

  void add_value(int id, const T& delta) {
    values[id] += delta;
    for (int x = id + 1; x <= n; x += x & -x)
      add_self(tree[x], delta);
  }

  void set_value(int id, const T& val) {
    T prev_val = values[id];
    add_value(id, val - prev_val);
    values[id] = val;
  }

  T get_value(int id) {
    return values[id];
  }

  T query(int r) {
    T res = 0;
    for (int x = r + 1; x > 0; x -= x & -x)
      add_self(res, tree[x]);
    return res;
  }

  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

void test_case() {
   int N;
   cin >> N;

   vector<int> S(N);
   for (auto &s : S)
      cin >> s;   

   vector<int> dp(N);
   fenwick_tree<int> tree(nax);

   for (int i = 0; i < N; ++i) {
      int s = S[i];
      add_self(dp[i], 1);
      add_self(dp[i], tree.query(0, s - 1));
      tree.add_value(s, dp[i]);
   }

   int ans = 1;
   for (int i = 0; i < N; ++i)
      add_self(ans, dp[i]);

   cout << ans << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tests = 1;
   // cin >> tests;

   while(tests--)
      test_case();
}