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
const int64_t INF = (int64_t) 1e10 + 7;

void test_case() {   
   int N;
   cin >> N;

   vector<int64_t> A(N);
   for (auto &a : A)
      cin >> a;

   sort(A.begin(), A.end());
   int64_t total = accumulate(A.begin(), A.end(), 0LL);

   int m = N / 2;
   if (N % 2 == 0)
      m--;

   auto compute = [&](int64_t x) {
      if (N * x < total) 
         return (int64_t) -1;

      int64_t extra = N * x - total;

      for (int i = 0; i <= m; ++i) 
         if (A[i] > x) 
            return (int64_t) -1;

      int64_t y = 0;
      for (int i = m; i < N; ++i) 
         if (A[i] < x)
            y += x - A[i];

      if (y > extra)
         return (int64_t) -1;

      return extra;
   }; 

   int64_t lo = 0, hi = INF, ans = INF;
   while (lo <= hi) {
      int64_t mid = (lo + hi) / 2;
      int64_t ops = compute(mid);
      if (ops > -1) {
         hi = mid - 1;
         ans = ops;
      }

      else {
         lo = mid + 1;
      }
   }

   cout << ans << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tests = 1;
   cin >> tests;

   while(tests--)
      test_case();
}