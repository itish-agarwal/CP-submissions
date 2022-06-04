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
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int N;
   int64_t K;
   cin >> N >> K;
 
   vector<int64_t> A(N);
   for (auto &a : A)
      cin >> a;
 
   auto get_val = [&] (vector<int64_t> a) {
      int64_t mn = 0, mx = 0, s = 0;
      for (auto e : a) {
         s += e;
         mn = min (mn, s);
         mx = max (mx, s);
      }
 
      return mx - mn + 1;
   };
 
   int cnt = count (A.begin(), A.end(), 0);
   int64_t total = accumulate (A.begin(), A.end(), 0LL);
 
   if (cnt == 0) {
      cout << (total == 0 ? get_val(A) : -1) << '\n';
      return 0;
   }
 
   if (cnt == 1) {
      if (abs (total) > K) {
         cout << -1 << '\n';
         return 0;
      }
 
      for (int i = 0; i < N; ++i)
         if (A[i] == 0) 
            A[i] = -total;
 
      cout << get_val(A) << '\n';
      return 0;
   }
 
   int64_t ans = -1;
 
   for (int r = 0; r < N; ++r) {
      rotate (A.begin(), A.begin() + 1, A.end());
      // debug(A);
 
      int x = cnt;
      int64_t s = total, ok = 1;
 
      vector<int64_t> B = A;
 
      for (auto &b : B) {
         if (b == 0) {
            x -= 1;
            b = min (K, K * x - s);
            if (b > K || b < -K) {
               ok = 0;
               break;
            }
 
            s += b;
         }
      }
 
      if (ok == true && s == 0) 
         ans = max (ans, get_val (B));
   }
 
   cout << ans << '\n';
}