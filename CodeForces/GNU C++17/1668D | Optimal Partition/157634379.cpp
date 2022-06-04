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
   for (auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
   for (int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
const uint64_t INf = (int64_t) 2e18 + 7;
 
void ckmax (int64_t &a, int64_t b) {
   a = max (a, b);
}
 
template <class T> 
struct segtree {
   vector<T> t;
   T dft;
  
   segtree(int _n, T dd) {
      dft = dd;
      t.assign(4*_n, dd);
   }
 
   T merge(const T& a, const T& b) {
      return max(a, b);
   }
 
   void update(int id, int l, int r, int p, T val) {
      if(l == r) {
         t[id] = max (t[id], val);
         return;
      }
      int m = (l + r) >> 1;
 
      if(p <= m)
         update(id<<1, l, m, p, val);
      else
         update(id<<1 | 1, m + 1, r, p, val);
 
      t[id] = merge(t[id<<1], t[id<<1 | 1]);
   }
   T query(int id, int l, int r, int lq, int rq) {
      if(lq > r || l > rq) 
         return dft;
 
      if(lq <= l && r <= rq)
         return t[id];
      
      int m = (l + r) >> 1;
 
      T x = query(id<<1, l, m, lq, rq);
      T y = query(id<<1 | 1, m + 1, r, lq, rq);
      return merge(x, y);
   }
};
 
void test_case() {
   int N;
   cin >> N;
 
   vector<int64_t> A(N + 1);
   for (int i = 1; i <= N; ++i)
      cin >> A[i];
 
   vector<int64_t> preffix_sum = A;
   for (int i = 1; i <= N; ++i)
      preffix_sum[i] += preffix_sum[i-1];
 
   vector<int64_t> dp(N + 1, -INf);
   dp[0] = 0;
 
   auto value = [&] (int l, int r) {
      int64_t s = 0;
      for (int i = l; i <= r; ++i)
         s += A[i];
 
      if (s > 0)
         return r - l + 1;
      else if (s == 0)
         return 0;
      else
         return l - r - 1;
   };
 
   vector<pair<int64_t, int>> ret;
   for (int i = 0; i <= N; ++i)
      ret.emplace_back (preffix_sum[i], -i);
 
   sort (ret.begin(), ret.end());
 
   vector<int> P(N + 1);
   for (int i = 0; i <= N; ++i)
      P[-ret[i].second] = i;
 
   segtree<int64_t> T(N + 1, -INf);
 
   for (int i = 1; i <= N; ++i) {
      ckmax (dp[i], value (i, i) + dp[i-1]);
      int pv = P[i];
      if (pv > 0) 
         ckmax (dp[i], T.query (1, 0, N, 0, pv - 1) + i + 1);
 
      T.update (1, 0, N, P[i-1], dp[i-1] - i);
   }
 
   cout << dp.back() << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}