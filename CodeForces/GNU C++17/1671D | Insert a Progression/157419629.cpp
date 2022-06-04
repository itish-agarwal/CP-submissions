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
const uint64_t INF = (int64_t) 2e15 + 7;
 
int64_t best (vector<int> a, int x, int y) {
   const int n = a.size();
 
   vector<int64_t> preffix_sum(n);
   for (int i = 1; i < n; ++i)
      preffix_sum[i] = preffix_sum[i-1] + abs (a[i] - a[i-1]);
 
   vector<int64_t> suffix_sum(n);
   for (int i = n - 2; i >= 0; --i)
      suffix_sum[i] = suffix_sum[i+1] + abs(a[i] - a[i+1]);
 
   vector<int64_t> preffix_best(n, INF);
   for (int i = 0; i < n; ++i) 
      if (i == 0) 
         preffix_best[i] = abs (a[i] - x);
      else
         preffix_best[i] = min (preffix_best[i-1] + abs (a[i] - a[i-1]), preffix_sum[i-1] + abs (a[i-1] - x) + abs (x - a[i]));
 
   int64_t res = INF, total = preffix_sum.back();
 
   for (int i = 0; i < n; ++i) {
      int64_t add = (i + 1 < n ? abs (a[i] - y) + abs (y - a[i+1]) : abs (a[i] - y));
      add += (i + 1 < n ? suffix_sum[i+1] : 0);
 
      res = min (res, add + preffix_best[i]);  
   }
 
   return res;
}
 
void test_case() {
   int N, X;
   cin >> N >> X;
 
   vector<int> A(N);
   for (auto &a : A)
      cin >> a;
 
   int64_t total = 0;
   for (int i = 1; i < N; ++i)
      total += abs (A[i] - A[i-1]);   
 
   int64_t ans = INF;
 
   for (int i = 1; i < N; ++i) {
      int64_t p = total - abs (A[i] - A[i-1]);
      int64_t val0 = abs (A[i-1] - 1) + abs (1 - X) + abs (A[i] - X);
      int64_t val1 = abs (A[i-1] - X) + abs (1 - X) + abs (A[i] - 1);
      ans = min (ans, p + min (val0, val1));
   }
 
   ans = min (ans, (int64_t) abs (1 - X) + min (abs (A[0] - X), abs (A[0] - 1)) + total);
   ans = min (ans, (int64_t) abs (1 - X) + min (abs (A.back() - X), abs (A.back() - 1)) + total);
 
   ans = min (ans, best (A, 1, X));
   reverse (A.begin(), A.end());
   ans = min (ans, best (A, 1, X));
 
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