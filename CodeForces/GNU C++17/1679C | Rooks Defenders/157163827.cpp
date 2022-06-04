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
   int N, Q, x, y;
   cin >> N >> Q;
 
   fenwick_tree row(N), col(N);
   set<pair<int, int>> rooks;
   vector<int> row_sum(N), col_sum(N);
 
   for (int q = 0; q < Q; ++q) {
      int t;
      cin >> t;
      if (t == 1) {
         cin >> x >> y;
         --x, --y;
         rooks.insert ({x, y});
         row.set_value (x, 1);
         col.set_value (y, 1);
 
         row_sum[x] += 1;
         col_sum[y] += 1;
      }
 
      else if (t == 2) {
         cin >> x >> y;
         --x, --y;
         rooks.erase ({x, y});
 
         row_sum[x] -= 1;
         col_sum[y] -= 1;
         if (row_sum[x] == 0)
            row.set_value (x, 0);
         if (col_sum[y] == 0)
            col.set_value (y, 0);
      }
 
      else {
         int x1, y1, x2, y2;
         cin >> x1 >> y1 >> x2 >> y2;
         --x1, --y1, --x2, --y2;
 
         int sr = col.query (y1, y2);
         int sc = row.query (x1, x2);
 
         cout << (sr == y2 - y1 + 1 || sc == x2 - x1 + 1 ? "Yes" : "No") << '\n';
      }
   }
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tt = 1;
   // cin >> tt;
 
   while(tt--)
      test_case();
}