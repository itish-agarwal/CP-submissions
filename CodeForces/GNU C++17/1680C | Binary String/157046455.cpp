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
 
void test_case() {
   string S;
   cin >> S;
 
   const int N = S.length();
 
   vector<int> pref(N);
   for (int i = 0; i < N; ++i)
      pref[i] = (S[i] == '1') + (i > 0 ? pref[i-1] : 0);
 
   auto get_ones = [&] (int l, int r) {
      if (l > r)
         return 0;
 
      return pref[r] - (l > 0 ? pref[l-1] : 0);
   };
 
   auto get_zeros = [&] (int l, int r) {
      if (l > r)
         return 0;
 
      return r - l + 1 - get_ones (l, r);
   };
 
   auto segment_left = [&] (int l, int r) {
      return max (get_ones (0, l - 1) + get_ones (r + 1, N - 1), get_zeros (l, r));
   };
 
   int ans = min (pref.back(), N - pref.back());
 
   for (int i = 0; i < N - 2; ++i) {
      int ones_removed = pref[i];
      int lo = i + 1, hi = N - 1, best_j = -1;
 
      while (lo <= hi) {
         int m = (lo + hi) / 2;
         if (ones_removed + get_ones (m + 1, N - 1) >= get_zeros (i + 1, m)) {
            best_j = m;
            lo = m + 1;
         }
         else {
            hi = m - 1;
         }
      }
 
      if (best_j > -1)
         ans = min (ans, ones_removed + get_ones (best_j + 1, N - 1));
 
      if (best_j + 1 < N) 
         ans = min (ans, segment_left (i + 1, best_j + 1));
   }
   
   for (int i = 0; i < N; ++i) {
      ans = min (ans, segment_left (0, i));
      ans = min (ans, segment_left (i + 1,  N - 1));
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