#include <bits/stdc++.h>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(long long x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }
 
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
 
template <class T, class V> void pr(const map<T, V>& mp) {
   for (auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
   for (int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T, class... V> void pr(T t, V... v) {
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
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
         tree[x] += delta;
   }
 
   void set_value(int id, const T& val) {
      T prev_val = values[id];
      add_value(id, val - prev_val);
      values[id] = val;
   }
 
   T query(int l, int r) {
      return query(r) - query(l - 1);
   }
 
   T query(int r) {
      T res = 0;
      for (int x = r + 1; x > 0; x -= x & -x)
         res += tree[x];
      return res;
   }  
};
 
void test_case() {
   int N;
   cin >> N;
 
   vector<int> A(N);
   for (auto &a : A) {
      cin >> a;
      a -= 1;
   }
 
   int64_t ans = 0;
 
   for (int j = 1; j < N; ++j) {
      fenwick_tree L(N), R(N);
 
      for (int i = 0; i < j; ++i)
         L.set_value (A[i], 1);
 
      for (int i = j + 1; i < N; ++i)
         R.set_value (A[i], 1);
 
      for (int k = j + 1; k < N; ++k) {
         R.set_value (A[k], 0);
 
         ans += (int64_t) L.query (0, A[k] - 1) * R.query (0, A[j] - 1);
      }
   }
 
   cout << ans << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tt = 1;
   cin >> tt;
 
   while(tt--)
      test_case();
}